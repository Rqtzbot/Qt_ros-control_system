/**
 * @file /include/class1_ros_qt_demo/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef class1_ros_qt_demo_QNODE_HPP_
#define class1_ros_qt_demo_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include <serial/serial.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <move_base_msgs/MoveBaseActionResult.h>
#endif
#include <string>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/String.h>
#include <QThread>
#include <QStringListModel>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <QLabel>
#include "target_msg.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
    void front_vel(double speed);
    void back_vel(double speed);
    void left_vel(double speed);
    void right_vel(double speed);
    void moveleft_vel(double speed);
    void moveright_vel(double speed);
    void stop_vel();
    void pub_voicw_words(std_msgs::String words);
    void pub_awake_words(std_msgs::String awake);
    void run();
    void cmd_cb(const geometry_msgs::Twist::ConstPtr &msg);
    void odom_cb(const nav_msgs::Odometry::ConstPtr &msg);
    void yaw_cb(const std_msgs::Float32::ConstPtr &msg);
    void settopic_vel(std::string topic);
    void voice_asr_cb(const std_msgs::String::ConstPtr &msg);
    void voice_tts_cb(const std_msgs::String::ConstPtr &msg);
    void angle_cb(const std_msgs::Int32::ConstPtr &msg);
    void object_tf_cb(const geometry_msgs::Point::ConstPtr &msg);
    void goodsindex_cb(const std_msgs::String::ConstPtr &msg);
    void name_cb(const std_msgs::String::ConstPtr &msg);
    void face_distance_cb(const std_msgs::Float64::ConstPtr &msg);
    void face_offset_cb(const std_msgs::Float64::ConstPtr &msg);
    void pub_arm_status(const bigcar_nav::target_msg status);
    void signelpose_cb(const geometry_msgs::PoseStamped::ConstPtr &msg);
    void mult_goals_cb(const geometry_msgs::PoseStamped::ConstPtr &msg);
    void If_Getaimpoint_cb(const move_base_msgs::MoveBaseActionResult::ConstPtr &msg);
    void send_goals(double x,double y,double z,double w);
    void send_stratpose();
    void connect_lines();
	/*********************
	** Logging
	**********************/
    enum LogLevel
    {
      Debug,
      Info,
      Warn,
      Error,
      Fatal
	 };
   int receive_angle(){return angle;}
   QStringListModel* loggingModel() { return &logging_model; }
   QStringListModel* receive_voice_asr_text(){return &voice_asr;}
   QStringListModel* receive_voice_tts_text(){return &voice_tts;}
   QStringListModel* receive_arm_list(){return &arm_list;}
   void log( const LogLevel &level, const std::string &msg,double msg1);

Q_SIGNALS:
  void loggingUpdated();
  void rosShutdown();
  void odom_update(double x,double y,double z,double w);
  void send_signelpose(double x,double y,double z,double w);
  void speed_update(double x,double y,double z);
  void face_distance_update(double data);
  void face_offset_update(double data);
  void object_zuobiao_udpate(double zuobiao_x,double zuobiao_y,double zuobiao_z,std::string data);
  void yaw_update(float yaw);
  void name_udpate(std::string data);
  void mult_pose_update(std::map<int,std::vector<double>> bings);
  void get_aimpoint(int index);
private:
  int init_argc;
  char** init_argv;
  float yaw;
  int angle;
  std::string topicvalue= "/cmd_vel";
  ros::Subscriber cmd_sub;
  ros::Publisher cmd_pub;
  ros::Publisher arm_status_pub;
  ros::Publisher voice_words_pub;
  ros::Publisher awake_words_pub;
  ros::Publisher marker_pub;
  ros::Subscriber good_index_sub;
  ros::Subscriber face_distance_sub;
  ros::Subscriber face_offset_sub;
  ros::Subscriber name_sub;
  ros::Subscriber odom_sub;
  ros::Subscriber yaw_sub;
  ros::Subscriber move_sub;
  ros::Subscriber mult_goals_sub;
  ros::Subscriber angle_sub;
  ros::Subscriber anser_sub;
  ros::Subscriber voice_sub;
  ros::Subscriber object_tf_sub;
  ros::Subscriber awake_angle_sub;
  ros::Subscriber get_singelpose_sub;
  QStringListModel logging_model; 
  QStringListModel voice_asr;
  QStringListModel voice_tts;
  QStringListModel arm_list;
  std::string goodindex;
  std::map<int ,std::vector<double>>poselist;
  int count=0;
  bool signal_flag=false;

};

}  // namespace class1_ros_qt_demo

#endif /* class1_ros_qt_demo_QNODE_HPP_ */
