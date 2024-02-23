/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <serial/serial.h>
#include <ros/network.h>
#include <string>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <sstream>
#include <QDebug>
#include <QProcess>
#include <QCoreApplication>
#include <visualization_msgs/Marker.h>
#include <std_msgs/Bool.h>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseGoal.h>
#include <move_base_msgs/MoveBaseAction.h>
#include "../include/ros_qt_demo/qnode.hpp"
//#include "../include/ros_qt_demo/target_msg.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
  {
//  id = QThread::currentThreadId();
//  qDebug() << id;
}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
       qDebug() << "ros shut";
    }
  wait();

  qDebug() << "over";
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"class1_ros_qt_demo");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
  qDebug() << "init";
  cmd_pub = n.advertise<geometry_msgs::Twist>(topicvalue,10);
  voice_words_pub = n.advertise<std_msgs::String>("/change_voice_words",10);
  awake_words_pub = n.advertise<std_msgs::String>("/change_awake_words",10);
  cmd_sub = n.subscribe(topicvalue,10,&QNode::cmd_cb,this);
  odom_sub = n.subscribe("/odom",1000,&QNode::odom_cb,this);
  yaw_sub = n.subscribe("/yaw",10,&QNode::yaw_cb,this);
  voice_sub = n.subscribe("/voice_text",10,&QNode::voice_asr_cb,this);
  anser_sub = n.subscribe("/anser",10,&QNode::voice_tts_cb,this);
  angle_sub = n.subscribe("/mic/awake/angle",10,&QNode::angle_cb,this);
  object_tf_sub = n.subscribe("/object_zuobiao",10,&QNode::object_tf_cb,this);
  good_index_sub = n.subscribe("/goods",10,&QNode::goodsindex_cb,this);
  name_sub = n.subscribe("/name",10,&QNode::name_cb,this);
  face_distance_sub = n.subscribe("/person_distance",10,&QNode::face_distance_cb,this);
  face_offset_sub = n.subscribe("/person_offset",10,&QNode::face_offset_cb,this);
  arm_status_pub = n.advertise<bigcar_nav::target_msg>("/arm_control",10);
  get_singelpose_sub = n.subscribe("/move_base_simple/goal",10,&QNode::signelpose_cb,this);
  mult_goals_sub = n.subscribe("/mult_goals",10,&QNode::mult_goals_cb,this);
  marker_pub = n.advertise<visualization_msgs::Marker>("/marker",100);
  move_sub = n.subscribe("/move_base/result",100,&QNode::If_Getaimpoint_cb,this);
	start();
  return true;
}
bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"class1_ros_qt_demo");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
  ros::NodeHandle n;
	// Add your ros communications here.
  qDebug() << "init+++";
  cmd_pub = n.advertise<geometry_msgs::Twist>(topicvalue,10);
  cmd_sub = n.subscribe(topicvalue,10,&QNode::cmd_cb,this);
  odom_sub = n.subscribe("/odom",10,&QNode::odom_cb,this);
  yaw_sub = n.subscribe("/yaw",10,&QNode::yaw_cb,this);
  voice_sub = n.subscribe("/voice_text",10,&QNode::voice_asr_cb,this);
  anser_sub = n.subscribe("/anser",10,&QNode::voice_tts_cb,this);
  voice_words_pub = n.advertise<std_msgs::String>("/change_voice_words",10);
  awake_words_pub = n.advertise<std_msgs::String>("/change_awake_words",10);
  angle_sub = n.subscribe("/mic/awake/angle",10,&QNode::angle_cb,this);
  object_tf_sub = n.subscribe("/object_zuobiao",10,&QNode::object_tf_cb,this);
  name_sub = n.subscribe("/name",10,&QNode::name_cb,this);
  good_index_sub = n.subscribe("/goods",10,&QNode::goodsindex_cb,this);
  face_distance_sub = n.subscribe("/person_distance",10,&QNode::face_distance_cb,this);
  face_offset_sub = n.subscribe("/person_offset",10,&QNode::face_offset_cb,this);
  arm_status_pub = n.advertise<bigcar_nav::target_msg>("/arm_control",10);
  get_singelpose_sub = n.subscribe("/move_base_simple/goal",10,&QNode::signelpose_cb,this);
  mult_goals_sub = n.subscribe("/mult_goals",10,&QNode::mult_goals_cb,this);
  marker_pub = n.advertise<visualization_msgs::Marker>("/marker",100);
  move_sub = n.subscribe("/move_base/result",100,&QNode::If_Getaimpoint_cb,this);
  start();
  return true;
}
void QNode::run() {
    ros::Rate loop_rate(1);
	while ( ros::ok() ) {

		ros::spinOnce();
		loop_rate.sleep();

	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
  Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}
void QNode::settopic_vel(std::string topic)
{
  topicvalue=topic;
  ros::shutdown();
  init();
}
void QNode::front_vel(double speed)
{
  geometry_msgs::Twist cmd;
  cmd.linear.x = speed;
  cmd.linear.y = 0;
  cmd.angular.z = 0;
  cmd_pub.publish(cmd);
  qDebug() << "222";

}
void QNode::back_vel(double speed)
{
  geometry_msgs::Twist cmd;
  cmd.linear.x = speed;
  cmd.linear.y = 0;
  cmd.angular.z = 0;
  cmd_pub.publish(cmd);
}
void QNode::left_vel(double speed)
{
  geometry_msgs::Twist cmd;
  cmd.linear.x = 0;
  cmd.linear.y = 0;
  cmd.angular.z = speed;
  cmd_pub.publish(cmd);

}
void QNode::right_vel(double speed)
{
  geometry_msgs::Twist cmd;
  cmd.linear.x = 0;
  cmd.linear.y = 0;
  cmd.angular.z = speed;
  cmd_pub.publish(cmd);

}
void QNode::moveleft_vel(double speed)
{
  geometry_msgs::Twist cmd;
  cmd.linear.x = 0;
  cmd.linear.y = speed;
  cmd.angular.z = 0 ;
  cmd_pub.publish(cmd);

}
void QNode::moveright_vel(double speed)
{
  geometry_msgs::Twist cmd;
  cmd.linear.x = 0;
  cmd.linear.y = speed;
  cmd.angular.z = 0 ;
  cmd_pub.publish(cmd);

}
void QNode::stop_vel()
{
  geometry_msgs::Twist cmd;
  cmd.linear.x = 0;
  cmd.linear.y = 0;
  cmd.angular.z = 0;
  cmd_pub.publish(cmd);

}
//速度回调函数
void QNode::cmd_cb(const geometry_msgs::Twist::ConstPtr &msg)
{
//  qDebug() << "速度回调";
//  log(Info,"x轴速度：",msg->linear.x);
//  log(Info,"y轴速度：",msg->linear.y);
//  log(Info,"z轴速度：",msg->angular.z);
emit speed_update(msg->linear.x,msg->linear.y,msg->angular.z);
}
//里程计回调函数
void QNode::odom_cb(const nav_msgs::Odometry::ConstPtr &msg)
{
//  qDebug() << "里程计回调";
  emit odom_update(msg->pose.pose.position.x,msg->pose.pose.position.y,msg->pose.pose.orientation.z,msg->pose.pose.orientation.w);
}

//偏航角回调函数
void QNode::yaw_cb(const std_msgs::Float32::ConstPtr &msg)
{
    emit yaw_update(msg->data);
}
//语音识别文本显示函数
void QNode::voice_asr_cb(const std_msgs::String::ConstPtr &msg)
{
  voice_asr.insertRows(voice_asr.rowCount(),1);
  std::stringstream ls;
  ls <<"["<<ros::Time::now()<<"]"<<"识别成功："<<msg->data;
  QVariant new_row(ls.str().c_str());
  voice_asr.setData(voice_asr.index(voice_asr.rowCount()-1),new_row);
  Q_EMIT loggingUpdated();
}
//语音播报文本显示函数
void QNode::voice_tts_cb(const std_msgs::String::ConstPtr &msg)
{
  std::stringstream ls;
  ls<<"["<<ros::Time::now()<<"]"<<"应答成功："<<msg->data;
//  std::string se=msg->data;
//爱心
//  QString sr=se.data();
//  qDebug()<<sr;
// QProcess *pro =new QProcess();
// pro->start("gnome-terminal --geometry=61x31+400+400 -e '/home/qtz-robot/sim_car/aix.sh'";
  QVariant new_row(ls.str().c_str());
  voice_tts.insertRows(voice_tts.rowCount(),1);
  voice_tts.setData(voice_tts.index(voice_tts.rowCount()-1),new_row);
  Q_EMIT loggingUpdated();
}
//订阅唤醒角度回调函数
void QNode::angle_cb(const std_msgs::Int32::ConstPtr &msg)
{
  angle=msg->data;
}
//修改语音应答词函数
void QNode::pub_voicw_words(std_msgs::String words)
{
  voice_words_pub.publish(words);
}
//修改语音唤醒词函数
void QNode::pub_awake_words(std_msgs::String awake)
{
  awake_words_pub.publish(awake);
}
//订阅物品坐标
void QNode::object_tf_cb(const geometry_msgs::Point::ConstPtr &msg)
{
  emit object_zuobiao_udpate(msg->x,msg->y,msg->z,goodindex);
   qDebug()<<"object";
}
//订阅物品坐标名称索引
void QNode::goodsindex_cb(const std_msgs::String::ConstPtr &msg)
{
    goodindex=msg->data;
}
//订阅物品名称
void QNode::name_cb(const std_msgs::String::ConstPtr &msg)
{
    emit name_udpate(msg->data);
    qDebug()<<"name";
}
//订阅人脸直线距离
void QNode::face_distance_cb(const std_msgs::Float64::ConstPtr &msg)
{
  emit face_distance_update(msg->data);
}
//订阅人脸偏移距离
void QNode::face_offset_cb(const std_msgs::Float64::ConstPtr &msg)
{
  emit face_offset_update(msg->data);
}
//发布机械臂档位参数
void QNode::pub_arm_status(bigcar_nav::target_msg status)
{
    arm_status_pub.publish(status);
    if(status.arm_status==100)status.arm_status=0;
    std::string arm = QString::number(status.arm_status).toStdString();
    std::string claw = QString::number(status.claw_status).toStdString();
    std::stringstream ls;
    ls<<"["<<ros::Time::now()<<"]"<<"机械臂： "<<arm<<" 档  ||"<<"  爪子： "<<claw<<" 档 ";
    QVariant new_row(ls.str().c_str());
    arm_list.insertRows(arm_list.rowCount(),1);
    arm_list.setData(arm_list.index(arm_list.rowCount()-1),new_row);
    Q_EMIT loggingUpdated();
}
//单点导航订阅
void QNode::signelpose_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    signal_flag=true;
    emit send_signelpose(msg->pose.position.x,msg->pose.position.y,msg->pose.orientation.z,msg->pose.orientation.w);
}
//多点导航marker
void QNode::mult_goals_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    count++;
    poselist[count]={msg->pose.position.x,msg->pose.position.y,msg->pose.orientation.z,msg->pose.orientation.w};
    emit mult_pose_update(poselist);
    visualization_msgs::Marker arrow;
    visualization_msgs::Marker text;

    arrow.header.frame_id = "map";
    arrow.header.stamp = ros::Time::now();
    arrow.ns = "arrow_namespace";
    arrow.id = count;
    arrow.type = visualization_msgs::Marker::ARROW;
    arrow.action = visualization_msgs::Marker::ADD;
    arrow.pose = msg->pose;
    arrow.pose.position.z = 1;
    arrow.scale.x = 1.6;
    arrow.scale.y =0.1;
    arrow.scale.z =0.1;
    arrow.color.r = 1;
    arrow.color.g = 0.85f;
    arrow.color.b = 0.2f;
    arrow.color.a = 1;

    text.header.frame_id = "map";
    text.header.stamp = ros::Time::now();
    text.ns = "text_namespace";
    text.id = count;
    text.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    text.action = visualization_msgs::Marker::ADD;
    text.pose = msg->pose;
    text.pose.position.z = 1;
    text.scale.x = 0.7;
    text.scale.y = 0.7;
    text.scale.z = 0.7;
    text.color.r = 0.98f;
    text.color.g = 0.13f;
    text.color.b = 0.75f;
    text.color.a = 1;
    text.text = "Point"+std::to_string(count);
    marker_pub.publish(arrow);
    marker_pub.publish(text);

}
//多点导航的线段
void QNode::connect_lines()
{
      visualization_msgs::Marker line;
      line.header.frame_id = "map";
      line.header.stamp = ros::Time::now();
      line.ns = "line_namespace";
      line.id = count;
      line.type = visualization_msgs::Marker::LINE_STRIP;
      line.action = visualization_msgs::Marker::ADD;
      line.scale.x=0.1;
      line.pose.orientation.w = 1.0;
      line.color.r = 0;
      line.color.g = 0;
      line.color.b = 1;
      line.color.a = 1;

       geometry_msgs::Point point1;
       for(auto it =poselist.begin();it!=poselist.end();++it)
       {
           point1.x = it->second.at(0);
           point1.y = it->second.at(1);
           point1.z = 0;
           line.points.push_back(point1);
           qDebug()<<point1.x<<point1.y<<point1.z;
       }
      marker_pub.publish(line);
}
//到达目标点函数
void QNode::If_Getaimpoint_cb(const move_base_msgs::MoveBaseActionResult::ConstPtr &msg)
{
    if(!signal_flag)
    {
        static int num=1;
        if(msg->status.status==3)
        {
            num++;
            emit get_aimpoint(num-1);
            if(num==count+1)emit get_aimpoint(100);
            else send_goals(poselist[num][0],poselist[num][1],poselist[num][2],poselist[num][3]);
        }
    }
    else if(msg->status.status==3)get_aimpoint(99);
}
//发送第一个点
void QNode::send_stratpose()
{
     send_goals(poselist[1][0],poselist[1][1],poselist[1][2],poselist[1][3]);
     qDebug()<<"第一个点";
}
//导航函数
void QNode::send_goals(double x,double y,double z,double w)
{
    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base",true);
    ROS_INFO("Waiting for move_base action server...");
    if(!ac.waitForServer(ros::Duration(30)))
     {
        ROS_INFO("Can't connected to move base server");
        ros::shutdown();
     }
    ROS_INFO("Connected to move base server");
    ROS_INFO("Starting navigation test");
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;
    goal.target_pose.pose.position.z = 1.0;
    goal.target_pose.pose.orientation.z = z;
    goal.target_pose.pose.orientation.w = w;
    ac.sendGoal(goal);
}
//void QNode::start_multnav_thread()
//{
//    navtred = new boost::thread(boost::bind(&QNode::send_goals,this,poselist));
//}
//速度日志订阅函数
void QNode::log( const LogLevel &level, const std::string &msg,double msg1) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
        logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg << msg1;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
        logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg << msg1;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
        logging_model_msg << "[Warn] [" << ros::Time::now() << "]: " << msg << msg1;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
        logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg << msg1;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
        logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg << msg1;
				break;
		}
	}
//  logging_model.insertRows(logging_model.rowCount(),1);
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}


}  // namespace class1_ros_qt_demo
