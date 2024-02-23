/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <QDebug>
#include <QSlider>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include <nav_msgs/Odometry.h>
#include <QLineEdit>
#include <ros/ros.h>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QProcess>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "../include/ros_qt_demo/main_window.hpp"
#include "../include/ros_qt_demo/target_msg.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/
using namespace std;
namespace class1_ros_qt_demo {

using namespace Qt;
QImage *showimage =new QImage;
/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application
    QObject::connect(ui.action_robot, SIGNAL(triggered(bool)), this, SLOT(robot_statement())); // qApp is a global variable for the application
    QObject::connect(ui.robot_function, SIGNAL(clicked(bool)), this, SLOT(robot_statement()));
    ui.tabWidget->setDisabled(true);
    ui.tab_3->setDisabled(true);
    lab = new QLabel;
    setWindowTitle("家庭服务机器人功能调试系统");
    setWindowIcon(QIcon(":/robot"));
    lab->setPixmap(QPixmap("://error").scaled(15,15));
    ui.statusBar->addWidget(new QLabel("串口状态"));
    ui.statusBar->addWidget(lab);
    ui.serialnumtext->setText("4");
    ui.serial_list->setMaximumHeight(35);
    ui.speedtopEdit->setText("/cmd_vel");
    ui.school->setPixmap(QPixmap("://school2").scaled(530,130));
    ui.serial_select->setDisabled(false);
    ui.disport->setDisabled(true);
    ui.omoi->setCheckState(Qt::Checked);
    ui.tab_2->setDisabled(true);
    ui.dis_lab->setPixmap(QPixmap("://dispalys"));
    ui.odom->setPixmap(QPixmap("://odom").scaled(17,17));
    ui.imu->setPixmap(QPixmap("://imu").scaled(25,23));
    ui.move_lab->setPixmap(QPixmap("://time").scaled(20,20));
    ui.arm_status_lab->setPixmap(QPixmap("://error").scaled(20,20));

    ui.operation_lab->setPixmap(QPixmap("://operation").scaled(25,25));
    ui.logo_lab->setPixmap(QPixmap("://rqtz").scaled(100,50));
    ui.singelnav_goal_toolbtn->setText("单点导航");
    ui.singelnav_goal_toolbtn->setIcon(QPixmap("://sendgoal").scaled(15,15));
    ui.singelnav_goal_toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui.multnav_toolbtn->setText("多点导航");
    ui.multnav_toolbtn->setIcon(QPixmap("://multnav").scaled(15,15));
    ui.multnav_toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui.Pose_toolbtn->setText("初始位姿");
    ui.Pose_toolbtn->setIcon(QPixmap("://poseinit").scaled(15,15));
    ui.Pose_toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui.save_yuyinpath->setDisabled(true);
    ui.down_arm_btn->setDisabled(true);//初始放下不可按

    //设置显示图标
    showimage->load("://topic");
    ui.speed_lab->setPixmap(QPixmap::fromImage(*showimage).scaled(25,25));
    showimage->load("://con");
    ui.con_lab->setPixmap(QPixmap::fromImage(*showimage).scaled(20,20));
    showimage->load("://info");
    ui.infor_lab->setPixmap(QPixmap::fromImage(*showimage).scaled(22,22));
    showimage->load("://vel");
    ui.vel_lab->setPixmap(QPixmap::fromImage(*showimage).scaled(22,22));
    showimage->load("://rise");

    ReadSettings();
    ui.serial_list->addItem(tr("/dev/ttyUSB0"));
    ui.serial_list->addItem(tr("/dev/ttyUSB1"));
    ui.serial_list->addItem(tr("/dev/ttyUSB2"));
    ui.serial_list->addItem(tr("/dev/ttyUSB3"));

    //重映射速度话题
    connect(ui.setvalue,&QPushButton::clicked,this,[=]()
    {
      qnode.settopic_vel(ui.speedtopEdit->text().toStdString());
      qDebug() << "speed_topic change success";
      ui.dipan_textEdit->setText("速度话题修改成功......");
    });
    //点击连接后可使用功能
    connect(ui.button_connect,&QPushButton::clicked,this,[=]()
    {
      ui.tab_2->setDisabled(false);
      ui.button_connect->setEnabled(false);
    });
    //设置保存语音识别文本checkbox
    connect(ui.save_yuyin_checkBox,&QCheckBox::stateChanged,[=](int state)
    {
      if(state>1)ui.save_yuyinpath->setDisabled(false);
      else ui.save_yuyinpath->setDisabled(true);
    });
    //设置速度大小滚动条
    slider_connect();
    //发送速度到话题
    vel_connect();
    //设置速度大小滚动条
    slider_connect_2();
    //发送速度到话题
    vel_connect_2();
    //设置全向轮或差速轮模式
    checkboxconnect();
    //显示目标点的位置
    connect(&qnode,&QNode::send_signelpose,this,[=](double x,double y,double z,double w)
    {
        ui.xpose->setText(QString::number(x)+"m");
        ui.ypose->setText(QString::number(y)+"m");
        ui.zpose->setText(QString::number(z));
        ui.wpose->setText(QString::number(w));
    });
    connect(&qnode,&QNode::mult_pose_update,this,[=](std::map<int,std::vector<double>>pose)
    {
        pose_count++;
        ui.xpose->setText(QString::number(pose[pose_count][0])+"m");
        ui.ypose->setText(QString::number(pose[pose_count][1])+"m");
        ui.zpose->setText(QString::number(pose[pose_count][2]));
        ui.wpose->setText(QString::number(pose[pose_count][3]));
    });
    connect(&qnode,&QNode::get_aimpoint,this,[=](int num)
    {
        if(num==100)ui.move_list->setText("终点已到达......");
        else if(num==99)ui.move_list->setText("目标点已到达......");
        else ui.move_list->setText("第"+QString::number(num)+"个点已到达......");
    });
//    QMessageBox::information(this,"infornation","清点击\"连接\"按钮，连接ros_master");
    //设置rviz树
    ui.treeWidget->setHeaderLabels(QStringList()<<"key"<<"value"<<"bu");
    ui.treeWidget->setHeaderHidden(true);

    QTreeWidgetItem *global = new QTreeWidgetItem(QStringList()<<"Gloabl Options");
    ui.treeWidget->setColumnWidth(0,180);

    global->setIcon(0,QIcon("://option"));
    ui.treeWidget->addTopLevelItem(global);
    global->setExpanded(true);

    QTreeWidgetItem *fixframe = new QTreeWidgetItem(QStringList()<<"Fixed Frame");
    //设置只选中但不常亮
    fixframe->setFlags(fixframe->flags() & ~Qt::ItemIsSelectable);
    fixbox =new QComboBox();
    fixbox->addItem("map");
    fixbox->setEditable(true);
    fixbox->setMaximumWidth(80);
    fixbox->setMaximumHeight(20);
    global->addChild(fixframe);
    connect(fixbox,&QComboBox::currentTextChanged,this,[=]()
    {
        Dispaly_fix();
    });
    ui.treeWidget->setItemWidget(fixframe,1,fixbox);
    //设置网格grid
    QTreeWidgetItem *grid = new QTreeWidgetItem(QStringList()<<"Grid");
    grid->setIcon(0,QIcon("://grid"));
    ui.treeWidget->addTopLevelItem(grid);
    grid->setExpanded(true);

    grid_check = new QCheckBox();
    grid_check->setCheckState(Qt::CheckState(2));
    ui.treeWidget->setItemWidget(grid,1,grid_check);


    QTreeWidgetItem *cell_count = new QTreeWidgetItem(QStringList()<<"Plane Cell Count");
    cell_spinbox = new QSpinBox();
    cell_count->setFlags(cell_count->flags() & ~Qt::ItemIsSelectable);
    cell_spinbox->setValue(12);
    grid->addChild(cell_count);
    cell_spinbox->setMaximumWidth(80);
    cell_spinbox->setMaximumHeight(23);
    ui.treeWidget->setItemWidget(cell_count,1,cell_spinbox);

    QTreeWidgetItem *grid_color = new QTreeWidgetItem(QStringList()<<"Color");
    grid->addChild(grid_color);
    grid_color->setFlags(grid_color->flags() & ~Qt::ItemIsSelectable);
    color_box = new QComboBox();
    color_box->addItem("120;120;120;");
    color_box->setMaximumWidth(115);
    color_box->setMaximumHeight(23);
    color_box->setEditable(true);
    ui.treeWidget->setItemWidget(grid_color,1,color_box);
    //初态不可选中
    cell_count->setDisabled(false);
    cell_spinbox->setDisabled(false);
    color_box->setDisabled(false);
    grid_color->setDisabled(false);
    //勾选后可选函数

    connect(grid_check,&QCheckBox::stateChanged,this,[=](int state){
      if(state)
      {
        cell_count->setDisabled(false);
        cell_spinbox->setDisabled(false);
        color_box->setDisabled(false);
        grid_color->setDisabled(false);
        Display_Grid(state);
      }
      else
      {
        cell_count->setDisabled(true);
        cell_spinbox->setDisabled(true);
        color_box->setDisabled(true);
        grid_color->setDisabled(true);
        Display_Grid(state);
      }
    });

    //TF坐标
    QTreeWidgetItem * tf = new QTreeWidgetItem(QStringList()<<"TF");
    ui.treeWidget->addTopLevelItem(tf);
    tf->setIcon(0,QIcon("://tf"));
    QCheckBox *tf_box = new QCheckBox();
    ui.treeWidget->setItemWidget(tf,1,tf_box);
    QTreeWidgetItem *show_name = new QTreeWidgetItem(QStringList()<<"Show Names");
    tf->addChild(show_name);
    show_name_box = new QCheckBox();
    ui.treeWidget->setItemWidget(show_name,1,show_name_box);
    QTreeWidgetItem *show_Axes = new QTreeWidgetItem(QStringList()<<"Show Axes");
    tf->addChild(show_Axes);
    show_Aexs_box = new QCheckBox();
    ui.treeWidget->setItemWidget(show_Axes,1,show_Aexs_box);
    //初态不可选中
    show_name->setDisabled(true);
    show_name_box->setDisabled(true);
    show_Axes->setDisabled(true);
    show_Aexs_box->setDisabled(true);
    //勾选后可选函数
    connect(tf_box,&QCheckBox::stateChanged,this,[=](int state){
      if(state)
      {
        show_name->setDisabled(false);
        show_name_box->setDisabled(false);
        show_Axes->setDisabled(false);
        show_Aexs_box->setDisabled(false);
        show_Aexs_box->setCheckState(Qt::CheckState(2));
        show_name_box->setCheckState(Qt::CheckState(2));

         Display_TF(state);
//        connect(show_name_box,&QCheckBox::stateChanged,this,[=](int state)
//        {
//          Display_TF(state);
//        });
//        connect(show_Aexs_box,&QCheckBox::stateChanged,this,[=](int state)
//        {
//          Display_TF(state);
//        });

      }
      else
      {
        show_name->setDisabled(true);
        show_name_box->setDisabled(true);
        show_Axes->setDisabled(true);
        show_Aexs_box->setDisabled(true);
        show_Aexs_box->setCheckState(Qt::CheckState(0));
        show_name_box->setCheckState(Qt::CheckState(0));
        Display_TF(state);
//        connect(show_name_box,&QCheckBox::stateChanged,this,[=](int state)
//        {
//          Display_TF(state);
//        });
//        connect(show_Aexs_box,&QCheckBox::stateChanged,this,[=](int state)
//        {
//          Display_TF(state);
//        });
      }
    });

    //雷达scan
    QTreeWidgetItem *laser = new QTreeWidgetItem(QStringList()<<"LaserScan");
    ui.treeWidget->addTopLevelItem(laser);
    QCheckBox *laser_check =new QCheckBox();
    ui.treeWidget->setItemWidget(laser,1,laser_check);
    laser->setIcon(0,QIcon("://laser"));
    QTreeWidgetItem *laser_topic = new QTreeWidgetItem(QStringList()<<"Topic");
    laser_topic->setFlags(laser_topic->flags() & ~Qt::ItemIsSelectable);
    laser->addChild(laser_topic);
    laser_topicbox = new QComboBox();
    laser_topicbox->addItem("/scan");
    laser_topicbox->setEditable(true);
    laser_topicbox->setMaximumWidth(80);
    laser_topicbox->setMaximumHeight(20);
    ui.treeWidget->setItemWidget(laser_topic,1,laser_topicbox);
    QTreeWidgetItem *size = new QTreeWidgetItem(QStringList()<<"Size(m)");
    laser->addChild(size);
    size->setFlags(size->flags() & ~Qt::ItemIsSelectable);
    laser_size = new QLineEdit();
    laser_size->setText("0.05");
    laser_size->setMaximumWidth(80);
    laser_size->setMaximumHeight(20);
    ui.treeWidget->setItemWidget(size,1,laser_size);
    //初态不可选中
    laser_topic->setDisabled(true);
    laser_topicbox->setDisabled(true);
    show_Axes->setDisabled(true);
    laser_size->setDisabled(true);
    size->setDisabled(true);
    //勾选后可选函数
    connect(laser_check,&QCheckBox::stateChanged,this,[=](int state){
      if(state)
      {
        laser_topic->setDisabled(false);
        laser_topicbox->setDisabled(false);
        size->setDisabled(false);
        laser_size->setDisabled(false);
        size->setDisabled(false);
        Display_Laser(state);
      }
      else
      {
        laser_topic->setDisabled(true);
        laser_topicbox->setDisabled(true);
        show_Axes->setDisabled(true);
        laser_size->setDisabled(true);
         size->setDisabled(true);
        Display_Laser(state);
      }
    });

    //栅格地图map
    QTreeWidgetItem *map = new QTreeWidgetItem(QStringList()<<"Map");
    ui.treeWidget->addTopLevelItem(map);
    QCheckBox *map_check =new QCheckBox();
    ui.treeWidget->setItemWidget(map,1,map_check);
    map->setIcon(0,QIcon("://map"));
    QTreeWidgetItem *map_topic = new QTreeWidgetItem(QStringList()<<"Topic");
    map_topic->setFlags(map_topic->flags() & ~Qt::ItemIsSelectable);

    map->addChild(map_topic);
    map_topicbox = new QComboBox();
    map_topicbox->addItem("/map");
    map_topicbox->setEditable(true);
    map_topicbox->setMaximumWidth(80);
    map_topicbox->setMaximumHeight(20);
    ui.treeWidget->setItemWidget(map_topic,1,map_topicbox);

    QTreeWidgetItem *map_style = new QTreeWidgetItem(QStringList()<<"Color Scheme");
    map_style->setFlags(map_style->flags() & ~Qt::ItemIsSelectable);
    style_mapbox = new QComboBox();
    style_mapbox->addItem("map");
    style_mapbox->addItem("costmap");
    style_mapbox->addItem("raw");
    style_mapbox->setEditable(true);
    style_mapbox->setMaximumWidth(90);
    style_mapbox->setMaximumHeight(20);
    map->addChild(map_style);
    ui.treeWidget->setItemWidget(map_style,1,style_mapbox);
    //初态不可选中
    map_topic->setDisabled(true);
    map_topicbox->setDisabled(true);
    map_style->setDisabled(true);
    style_mapbox->setDisabled(true);
    //勾选后可选函数
    connect(map_check,&QCheckBox::stateChanged,this,[=](int state){
      if(state)
      {
        map_topic->setDisabled(false);
        map_topicbox->setDisabled(false);
        map_style->setDisabled(false);
        style_mapbox->setDisabled(false);
        Display_Map(state);
      }
      else
      {
        map_topic->setDisabled(true);
        map_topicbox->setDisabled(true);
        map_style->setDisabled(true);
        style_mapbox->setDisabled(true);
         Display_Map(state);
      }
    });
    connect(style_mapbox,&QComboBox::currentTextChanged,this,[=]()
    {
        Display_Map(2);
    });



    //设置机器人显示模型
    QTreeWidgetItem *Show_Robot = new QTreeWidgetItem(QStringList()<<"RobotModel");
    Show_Robot->setIcon(0,QIcon("://Show_Robot"));
    ui.treeWidget->addTopLevelItem(Show_Robot);
    QTreeWidgetItem *robot_description = new QTreeWidgetItem(QStringList()<<"Robot Description");
    QCheckBox *robot_check = new QCheckBox();
    ui.treeWidget->setItemWidget(Show_Robot,1,robot_check);
    Robot_edit = new QLineEdit();
    Robot_edit->setMaximumWidth(121);
    Robot_edit->setMaximumHeight(23);
    Robot_edit->setText("robot_description");
    Robot_edit->setMinimumWidth(10);
    Show_Robot->addChild(robot_description);
    ui.treeWidget->setItemWidget(robot_description,1,Robot_edit);

    robot_description->setDisabled(true);
    Robot_edit->setDisabled(true);

    connect(robot_check,&QCheckBox::stateChanged,this,[=](int state){
      if(state)
      {
        robot_description->setDisabled(false);
        Robot_edit->setDisabled(false);
        Display_Robot(state);
      }
      else
      {
        robot_description->setDisabled(true);
        Robot_edit->setDisabled(true);
        Display_Robot(state);
      }
    });
    //显示path
    QTreeWidgetItem *Show_Path = new QTreeWidgetItem(QStringList()<<"Path");
    Show_Path->setIcon(0,QIcon("://path"));
    ui.treeWidget->addTopLevelItem(Show_Path);
    QTreeWidgetItem *path_topic = new QTreeWidgetItem(QStringList()<<"Topic");
    path_topic->setFlags(path_topic->flags() & ~Qt::ItemIsSelectable);
    QCheckBox *path_check = new QCheckBox();
    ui.treeWidget->setItemWidget(Show_Path,1,path_check);
    Show_Path->addChild(path_topic);
    path_topicbox = new QComboBox();
    path_topicbox->addItem("/move_base/TebLocalPlannerROS/global_plan");
    path_topicbox->setEditable(true);
    path_topicbox->setMaximumWidth(140);
    path_topicbox->setMaximumHeight(20);
    ui.treeWidget->setItemWidget(path_topic,1,path_topicbox);
    QTreeWidgetItem *path_color = new QTreeWidgetItem(QStringList()<<"Color");
    Show_Path->addChild(path_color);
    path_color->setFlags(path_color->flags() & ~Qt::ItemIsSelectable);
    path_color_box = new QComboBox();
    path_color_box->addItem("0;255;0;");
    path_color_box->setMaximumWidth(115);
    path_color_box->setMaximumHeight(23);
    path_color_box->setEditable(true);
    ui.treeWidget->setItemWidget(path_color,1,path_color_box);

    path_topic->setDisabled(true);
    path_topicbox->setDisabled(true);
    path_color->setDisabled(true);
    path_color_box->setDisabled(true);

    connect(path_check,&QCheckBox::stateChanged,this,[=](int state){
      if(state)
      {
        path_topic->setDisabled(false);
        path_topicbox->setDisabled(false);
        path_color->setDisabled(false);
        path_color_box->setDisabled(false);
        Display_Path(state);
      }
      else
      {
        path_topic->setDisabled(true);
        path_topicbox->setDisabled(true);
        path_color->setDisabled(true);
        path_color_box->setDisabled(true);
        Display_Path(state);
      }
    });

    //显示marker
    QTreeWidgetItem *Show_marker = new QTreeWidgetItem(QStringList()<<"Marker");
    Show_marker->setIcon(0,QIcon("://marker"));
    ui.treeWidget->addTopLevelItem(Show_marker);
    QTreeWidgetItem *marker_topic = new QTreeWidgetItem(QStringList()<<"Marker Topic");
    path_topic->setFlags(path_topic->flags() & ~Qt::ItemIsSelectable);
    Show_marker->addChild(marker_topic);
    QCheckBox *marker_check = new QCheckBox();
    ui.treeWidget->setItemWidget(Show_marker,1,marker_check);
    marker_edit = new QLineEdit();
    marker_edit->setMaximumWidth(100);
    marker_edit->setMaximumHeight(23);
    marker_edit->setText("/marker");
    ui.treeWidget->setItemWidget(marker_topic,1,marker_edit);

    marker_topic->setDisabled(true);
    marker_edit->setDisabled(true);
    connect(marker_check,&QCheckBox::stateChanged,this,[=](int state){
      if(state)
      {
        marker_topic->setDisabled(false);
        marker_edit->setDisabled(false);
        Display_marker(state);
      }
      else
      {
        marker_topic->setDisabled(true);
        marker_edit->setDisabled(true);
        Display_marker(state);
      }
    });

    set_map  = new QProcess();
    save_map = new QProcess();
    open_sim  = new QProcess();
    close_sim = new QProcess();
    open_map = new QProcess();
    start_nav = new QProcess();

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    //通过信号和槽订阅速度，里程计，偏航角，语音识别，语音播报，物品名称，物品坐标，人脸直线距离，人脸偏移距离,机械臂，爪子，并动态显示在窗口中
    connect(&qnode,&QNode::speed_update,this,[=](double x,double y,double z)
    {
         ui.speeddetview->append("x轴速度: "+QString::number(x)+" m/s");
         ui.speeddetview->append("y轴速度: "+QString::number(y)+" m/s");
         ui.speeddetview->append("z轴速度: "+QString::number(z)+" m/s");
    });
    connect(&qnode,&QNode::odom_update,this,[=](double x,double y,double z,double w)
    {
      ui.odomx_view->setText(QString::number(x));
      ui.odomy_view->setText(QString::number(y));
      ui.odomz_view->setText(QString::number(z));
      ui.odomw_view->setText(QString::number(w));
    });
    connect(&qnode,&QNode::name_udpate,this,[=](std::string data)
    {
        ui.object_name->append("物品名称： "+QString::fromStdString(data));
    });
    connect(&qnode,&QNode::object_zuobiao_udpate,[=](double x,double y,double z,std::string data)
    {
        ui.object_tf->append("物品坐标： "+QString::fromStdString(data)+" --> "+" x: "+QString::number(x)+" m "+" y: "+QString::number(y)+" m "+" y: "+QString::number(z)+" m ");
    });
    connect(&qnode,&QNode::face_distance_update,this,[=](double data)
    {
        ui.face_distance->append("人脸直线距离： "+QString::number(data));
    });
    connect(&qnode,&QNode::face_offset_update,this,[=](double data)
    {
        ui.face_offset->append("人脸偏移距离： "+QString::number(data));
    });
    connect(&qnode,&QNode::yaw_update,this,[=](float yaw)
    {
        ui.yaw_view->setText(QString::number(yaw));
    });

    ui.voice_asr_edit->setModel(qnode.receive_voice_asr_text());
    ui.voice_tts_edit->setModel(qnode.receive_voice_tts_text());
    ui.arm_view->setModel(qnode.receive_arm_list());
    //接受唤醒角度
    connect(ui.angle_btn,&QPushButton::clicked,this,[=](){ui.angle_edit->setText(QString::number(qnode.receive_angle()));});
    //滑动到底部时出现滑动条
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
}

MainWindow::~MainWindow() {
  delete myrviz;
  delete arm_rviz;
  delete   set_map  ;
  delete   save_map ;
  delete   open_sim ;
  delete   close_sim;
  delete   open_map ;
  delete   start_nav;

  qDebug()<<"细狗函数已执行";
}

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

void MainWindow::on_button_connect_clicked(bool check ) {
  if ( ui.checkbox_use_environment->isChecked() )
  {
    if ( !qnode.init() )
    {
			showNoMasterMessage();
    }
    else
    {
        myrviz=new QRviz(ui.layout_rviz);
        arm_rviz=new QRviz(ui.arm_layout);
        Display_Grid(2);
        ui.tabWidget->setDisabled(false);
        ui.tab_3->setDisabled(false);
        ui.dipan_textEdit->setText("连接成功........");
		}
  } else
  {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
           ui.line_edit_host->text().toStdString()) )
    {
			showNoMasterMessage();
    }
    else
    {
      myrviz=new QRviz(ui.layout_rviz);
      arm_rviz=new QRviz(ui.arm_layout);
      Display_Grid(2);
      ui.tabWidget->setDisabled(false);
      ui.tab_3->setDisabled(false);
      ui.line_edit_master->setReadOnly(true);
      ui.line_edit_host->setReadOnly(true);
      ui.line_edit_topic->setReadOnly(true);
		}
	}
}

void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

void MainWindow::updateLoggingView() {
  ui.voice_asr_edit->scrollToBottom();
  ui.voice_tts_edit->scrollToBottom();
  ui.arm_view->scrollToBottom();
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "class1_ros_qt_demo");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "class1_ros_qt_demo");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}
void MainWindow::robot_statement()
{
    QMessageBox::about(this,tr("About robot"),"      本软件是基于linux系统下，通过Qt软件制作，且结合ros机器人操作系统的一款仅适用于家庭服务机器人的上位机系统,"
                                           "具有仿真与现实的环境模式， 并且具有多种功能，分别为\"全向轮底盘\",\"三轴机械臂\",\"讯飞六麦语音\",\"深度相机\""
                                           ",\"建图导航\"，\"串口号名称重映射\"等。其中，1:全向轮底盘部分主要实现了按钮控制机器人的运动，且具有机器人速度实时检"
                                            "测的功能，同时可以根据不同的速度话题来进行发布。2:三轴机械臂部分实现了按键控制机械臂与机械爪不同档位的切换，并且具"
                                            "有直观的仿真界面供我们与实体机器人进行对比。3:讯飞六麦语音部分通过使用讯飞旗下的语音模块，具有语音识别和语音播报的"
                                            "功能，同时该软件可以通过按钮快速的进行语音命令词，语音唤醒词，语音应答词进行修改，且可以根据声源的不同获唤醒角度"
                                            "(只是做了人机交互的页面，功能的实现是科大讯飞官方)。4:深度相机部分实现了物品的名称，坐标,以及人脸的直线距离，偏移"
                                            "距离的订阅，还有自主跟随的功能数据输出直观且准确。5:建图导航部分的GUI界面采用使用librviz库的方法，通过话题通信"
                                            "，可实时的获取到底盘的里程计信息，偏航角信息，且具有单次导航，多次巡航的功能，极大的方便了我们快速的熟悉服务机器"
                                            "人的使用方法。6:串口号名称重映射部分主要是可以检测到当前linux系统下有哪些串口连接，并且快捷的生成KERNEL命令来修"
                                            "改串口号的名称，相比终端直接操作更加便利。"

                                            "                           注：本软件为测试阶段，同时为Qt初学者创作，某些功能不是很完善,后续会不断维护......"
                                            "                                                                                               "
                                            "                                                                          2023/12/9 Made By Qtz" );


}


//速度滚动条6种
void MainWindow::slider_connect()
{
  Factor=100.0;
  ui.X_slider->setMinimum(0);
  ui.X_slider->setMaximum(static_cast<int>(0.5 * Factor));
  ui.X_slider->setValue(static_cast<int>(0.2 * Factor));
  ui.Y_slider->setMinimum(0);
  ui.Y_slider->setMaximum(static_cast<int>(0.5 * Factor));
  ui.Y_slider->setValue(static_cast<int>(0.2 * Factor));
  ui.Z_slider->setMinimum(0);
  ui.Z_slider->setMaximum(static_cast<int>(0.5 * Factor));
  ui.Z_slider->setValue(static_cast<int>(0.2 * Factor));

  ui.unX_slider->setMinimum(static_cast<int>(-0.5 * Factor));
  ui.unX_slider->setMaximum(0);
  ui.unX_slider->setValue(static_cast<int>(-0.2 * Factor));
  ui.unY_slider->setMinimum(static_cast<int>(-0.5 * Factor));
  ui.unY_slider->setMaximum(0);
  ui.unY_slider->setValue(static_cast<int>(-0.2 * Factor));
  ui.unZ_slider->setMinimum(static_cast<int>(-0.5 * Factor));
  ui.unZ_slider->setMaximum(0);
  ui.unZ_slider->setValue(static_cast<int>(-0.2 * Factor));

  connect(ui.X_slider,&QSlider::valueChanged,this,[&](double value)
  {
    double doubleValue = static_cast<double>(value) / Factor;
    ui.X_value->setText(QString::number(doubleValue));
    vel[0]=doubleValue;
  });
  connect(ui.unX_slider,&QSlider::valueChanged,this,[&](double value)
  {
    double doubleValue = static_cast<double>(value) / Factor;
    ui.unX_value->setText(QString::number(doubleValue));
    vel[1]=doubleValue;
  });
  connect(ui.Y_slider,&QSlider::valueChanged,this,[&](double value)
  {
    double doubleValue = static_cast<double>(value) / Factor;
    ui.Y_value->setText(QString::number(doubleValue));
    vel[2]=doubleValue;
  });
  connect(ui.unY_slider,&QSlider::valueChanged,this,[&](double value)
  {
    double doubleValue = static_cast<double>(value) / Factor;
    ui.unY_value->setText(QString::number(doubleValue));
    vel[3]=doubleValue;
  });
  connect(ui.Z_slider,&QSlider::valueChanged,this,[&](double value)
  {
    double doubleValue = static_cast<double>(value) / Factor;
    ui.Z_value->setText(QString::number(doubleValue));
    vel[4]=doubleValue;
  });
  connect(ui.unZ_slider,&QSlider::valueChanged,this,[&](double value)
  {
    double doubleValue = static_cast<double>(value) / Factor;
    ui.unZ_value->setText(QString::number(doubleValue));
    vel[5]=doubleValue;
  });

}
//速度滚动条4种
void MainWindow::slider_connect_2()
{
  ui.pos_linear_slider->setMaximum(50);
  ui.pos_linear_slider->setMinimum(0);
  ui.pos_linear_slider->setValue(20);
  ui.pos_angular_slider->setMaximum(50);
  ui.pos_angular_slider->setMinimum(0);
  ui.pos_angular_slider->setValue(20);

  ui.neg_linear_slider->setMaximum(0);
  ui.neg_linear_slider->setMinimum(-50);
  ui.neg_linear_slider->setValue(-20);
  ui.neg_angular_slider->setMaximum(0);
  ui.neg_angular_slider->setMinimum(-50);
  ui.neg_angular_slider->setValue(-20);


  connect(ui.pos_linear_slider,&QSlider::valueChanged,this,[=](int value)
  {
    ui.pos_linear_lab->setText(QString::number(value));
    vel_2[0]=value;
  });
  connect(ui.pos_angular_slider,&QSlider::valueChanged,this,[=](int value)
  {
    ui.pos_angular_lab->setText(QString::number(value));
    vel_2[1]=value;
  });
  connect(ui.neg_linear_slider,&QSlider::valueChanged,this,[=](int value)
  {
    ui.neg_linear_lab->setText(QString::number(value));
    vel_2[2]=value;
  });
  connect(ui.neg_angular_slider,&QSlider::valueChanged,this,[=](int value)
  {
    ui.neg_angular_lab->setText(QString::number(value));
    vel_2[3]=value;
  });
}
//发布速度6种
void MainWindow::vel_connect()
{
  connect(ui.frontbtn,&QPushButton::clicked,this,[=]()
  {
    qnode.front_vel(vel[0]);

  });
  connect(ui.backbtn,&QPushButton::clicked,this,[=]()
  {
    qnode.back_vel(vel[1]);
  });
  connect(ui.moveleftbtn,&QPushButton::clicked,this,[=]()
  {
    qnode.moveleft_vel(vel[2]);
  });
  connect(ui.moverightbtn,&QPushButton::clicked,this,[=]()
  {
    qnode.moveleft_vel(vel[3]);
  });
  connect(ui.rightbtn,&QPushButton::clicked,this,[=]()
  {
    qnode.right_vel(vel[4]);
  });
  connect(ui.leftbtn,&QPushButton::clicked,this,[=]()
  {
    qnode.left_vel(vel[5]);
  });
  connect(ui.stopbtn,&QPushButton::clicked,this,[=]()
  {
    qnode.stop_vel();
  });
}
//发布速度4种
void MainWindow::vel_connect_2()
{
  connect(ui.frontbtn_2,&QPushButton::clicked,this,[=]()
  {
    qnode.front_vel(vel_2[0]/100);

  });
  connect(ui.backbtn_2,&QPushButton::clicked,this,[=]()
  {
    qnode.back_vel(vel_2[1]/100);
  });
  connect(ui.rightbtn_2,&QPushButton::clicked,this,[=]()
  {
    qnode.right_vel(vel_2[2]/100);
  });
  connect(ui.leftbtn_2,&QPushButton::clicked,this,[=]()
  {
    qnode.left_vel(vel_2[3]/100);
  });
  connect(ui.stopbtn_2,&QPushButton::clicked,this,[=]()
  {
    qnode.stop_vel();
  });
}
//全向轮模式和差速轮模式的选中与未选中
void MainWindow::checkboxconnect()
{
  connect(ui.omoi,&QCheckBox::stateChanged,this,[=](int state)
  {
   if(state == Qt::Checked)
   {
     ui.moveleftbtn->setDisabled(false);
     ui.moverightbtn->setDisabled(false);
     ui.frontbtn->setDisabled(false);
     ui.backbtn->setDisabled(false);
     ui.leftbtn->setDisabled(false);
     ui.rightbtn->setDisabled(false);
     ui.diff->setCheckState(Qt::Unchecked);
   }
  });
  connect(ui.diff,&QCheckBox::stateChanged,this,[=](int state)
  {
   if(state == Qt::Checked)
   {
       ui.moveleftbtn->setDisabled(true);
       ui.moverightbtn->setDisabled(true);
       ui.frontbtn->setDisabled(false);
       ui.backbtn->setDisabled(false);
       ui.leftbtn->setDisabled(false);
       ui.rightbtn->setDisabled(false);
       ui.omoi->setCheckState(Qt::Unchecked);
   }

  });
}
//rviz中显示地图
void MainWindow::Display_Map(int state)
{
  bool enable =  state>1?true:false;
  myrviz->Display_Map(map_topicbox->currentText(),style_mapbox->currentText(),enable);
}
//rviz中显示栅格地图
void MainWindow::Display_Grid(int state)
{
  bool enable = state>1?true:false;
  QStringList list = color_box->currentText().split(";");
  QColor color = QColor(list[0].toInt(),list[1].toInt(),list[2].toInt());
  myrviz->Display_Grid(cell_spinbox->text().toInt(),color,enable);
  arm_rviz->Display_Grid(cell_spinbox->text().toInt(),color,enable);
}
//rviz中显示tf坐标
void MainWindow::Display_TF(int state)
{
  bool enable = state>1?true:false;
  myrviz->Display_TF(enable,show_name_box->checkState(),show_Aexs_box->checkState());
  arm_rviz->Display_TF(enable,show_name_box->checkState(),show_Aexs_box->checkState());
}
//rviz中显示雷达
void MainWindow::Display_Laser(int state)
{
  bool enable = state>1?true:false;
  myrviz->Display_LaserScan(laser_topicbox->currentText(),laser_size->text().toFloat(),enable);
}
//rviz中显示机器人模型pub_voicw_words
void MainWindow::Display_Robot(int state)
{
  bool enable = state>1?true:false;
  myrviz->Display_Robot(Robot_edit->text(),enable);
  arm_rviz->Display_Robot(Robot_edit->text(),enable);
}
//rviz中显示fix_frame
void MainWindow::Dispaly_fix()
{
    qDebug()<<fixbox->currentText();
  myrviz->Set_FixedFrame(fixbox->currentText());
      arm_rviz->Set_FixedFrame(fixbox->currentText());
}
//rviz中显示路径
void MainWindow::Display_Path(int state)
{
  bool enable =  state>1?true:false;
  QStringList list = path_color_box->currentText().split(";");
  QColor color = QColor(list[0].toInt(),list[1].toInt(),list[2].toInt());
  myrviz->Display_Path(path_topicbox->currentText(),color,enable);
}
void MainWindow::Display_marker(int state)
{
    bool enable =  state>1?true:false;
    myrviz->Display_Marker(marker_edit->text(),enable);
}
//判断机械臂按键状态
void MainWindow::juage_armbtn_state()
{
    if(arm_forstatus.arm_status==1)
    {
        ui.two_arm_btn->setDisabled(false);
        ui.three_arm_btn->setDisabled(false);
        ui.down_arm_btn->setDisabled(false);
        ui.one_arm_btn->setDisabled(true);

    }
    else if(arm_forstatus.arm_status==2)
    {
        ui.one_arm_btn->setDisabled(true);
        ui.three_arm_btn->setDisabled(false);
        ui.two_arm_btn->setDisabled(true);
        ui.down_arm_btn->setDisabled(false);
    }
    else if(arm_forstatus.arm_status==3)
    {
        ui.one_arm_btn->setDisabled(true);
        ui.three_arm_btn->setDisabled(true);
        ui.down_arm_btn->setDisabled(false);
        ui.two_arm_btn->setDisabled(true);
    }
    else if(arm_forstatus.arm_status==100)
    {
        ui.one_arm_btn->setDisabled(false);
        ui.three_arm_btn->setDisabled(false);
        ui.down_arm_btn->setDisabled(true);
        ui.two_arm_btn->setDisabled(false);
    }
}
//判断爪子按键状态
void MainWindow::juage_clawbtn_state()
{
    if(arm_forstatus.claw_status==1)
    {
        ui.one_claw_btn->setDisabled(true);
        ui.two_claw_btn->setDisabled(false);
        ui.three_claw_btn->setDisabled(false);
        ui.four_claw_btn->setDisabled(false);
        ui.five_claw_btn->setDisabled(false);
    }
    else if(arm_forstatus.claw_status==2)
    {
        ui.one_claw_btn->setDisabled(false);
        ui.two_claw_btn->setDisabled(true);
        ui.three_claw_btn->setDisabled(false);
        ui.four_claw_btn->setDisabled(false);
        ui.five_claw_btn->setDisabled(false);
    }
    else if(arm_forstatus.claw_status==3)
    {
        ui.one_claw_btn->setDisabled(false);
        ui.two_claw_btn->setDisabled(false);
        ui.three_claw_btn->setDisabled(true);
        ui.four_claw_btn->setDisabled(false);
        ui.five_claw_btn->setDisabled(false);
    }
    else if(arm_forstatus.claw_status==4)
    {
        ui.one_claw_btn->setDisabled(false);
        ui.two_claw_btn->setDisabled(false);
        ui.three_claw_btn->setDisabled(false);
        ui.four_claw_btn->setDisabled(true);
        ui.five_claw_btn->setDisabled(false);
    }
    else if(arm_forstatus.claw_status==5)
    {
        ui.one_claw_btn->setDisabled(false);
        ui.two_claw_btn->setDisabled(false);
        ui.three_claw_btn->setDisabled(false);
        ui.four_claw_btn->setDisabled(false);
        ui.five_claw_btn->setDisabled(true);
    }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
  WriteSettings();
  QMainWindow::closeEvent(event);
}

}  // namespace class1_ros_qt_demo

void class1_ros_qt_demo::MainWindow::on_connect_serial_clicked()
{
  QString serialtext = ui.serial_list->currentText();
  if(serialtext=="/dev/ttyUSB0")
    port="/dev/base";
  else if(serialtext=="/dev/ttyUSB1")
    port="/dev/arm";
  else if(serialtext=="/dev/ttyUSB2")
    port="/dev/rplidar";
  else if(serialtext=="/dev/ttyUSB3")
    port="/dev/fdilink_ahrs";
}
/*-----------
  导航建图
------------*/
//新建终端打开保存地图launch程序
void class1_ros_qt_demo::MainWindow::on_set_map_clicked()
{
  set_map = new QProcess();
  QString program = "gnome-terminal --geometry=80x18+0+748 -e '/home/qtz-robot/sim_car/set_map.sh'"; // 脚本文件的路径
  set_map->start(program);
}
//新建终端打开仿真环境launch程序
void class1_ros_qt_demo::MainWindow::on_open_sim_clicked()
{
  open_sim = new QProcess();
  QString program = "gnome-terminal --geometry=80x18+0+0 -e  '/home/qtz-robot/sim_car/open_sim.sh'"; // 脚本文件的路径
  open_sim->start(program);
}
//新建终端打开保存地图launch文件
void class1_ros_qt_demo::MainWindow::on_save_map_clicked()
{
  save_map = new QProcess();
  QString program = "gnome-terminal --geometry=80x18+0+1122 -e '/home/qtz-robot/sim_car/save_map.sh'"; // 脚本文件的路径
  save_map->start(program);
}
//新建终端打开打开地图launch程序
void class1_ros_qt_demo::MainWindow::on_open_map_clicked()
{
  open_map = new QProcess();
  QString program = "gnome-terminal --geometry=80x18+732+0 -e '/home/qtz-robot/sim_car/open_map.sh'"; // 脚本文件的路径
  open_map->start(program);
}
//新建终端来打开导航launch程序
void class1_ros_qt_demo::MainWindow::on_start_nav_clicked()
{
  start_nav = new QProcess();
  QString program = "gnome-terminal --geometry=80x18+0+374 -e '/home/qtz-robot/sim_car/nav.sh'"; // 脚本文件的路径
  start_nav->start(program);
}
//用文本编辑器打开所选路径下的地图文件并修改内容
void class1_ros_qt_demo::MainWindow::on_change_mapname_clicked()
{
  change_map = new QProcess();
  QString program = "gedit" +path; // 用文本编辑器打开
  change_map->start(program);

  QObject::connect(change_map,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {

    QMessageBox::information(this,"information","修改成功");
    qDebug() << "修改地图名称/路径进程结束......" ;
    delete change_map;
});
}
//选择保存地图文件路径
void class1_ros_qt_demo::MainWindow::on_finsh_savemap_clicked()
{
  QString pathlist = QFileDialog::getOpenFileName(this,"修改文件","/home",tr("Launch(*.launch)"));
  path=pathlist;
  ui.savemap_path->setText(pathlist);
}
/*-----------
  串口udev
------------*/
//修改串口udev规则函数
void class1_ros_qt_demo::MainWindow::on_serial_select_clicked()
{
    QProcess *port= new QProcess();
    QString command;
    command ="/home/qtz-robot/ubuntu_port/start.sh";
    port->start(command);
    QObject::connect(port,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
      QMessageBox::information(this,"information","修改成功");
      qDebug() << "串口重映射进程结束......" ;
      delete port;
  });
    ui.dipan_textEdit->setText("正在配置串口.......");
}
/*-----------
  讯飞六麦语音
------------*/
//选择命令词文件路径
void class1_ros_qt_demo::MainWindow::on_select_yuyintext_clicked()
{
    filepath = QFileDialog::getOpenFileName(this,"选择路径","/home/qtz-robot/bigcar_nat/src/xf_mic_asr_offline/config",tr("BNF(*.bnf)"));
    ui.yuyin_edit->setText(filepath);
}
//用文本编辑器打开所选路径下的命令词文件
void class1_ros_qt_demo::MainWindow::on_change_yuyintext_clicked()
{
    QProcess *change_yuyintext = new QProcess();
    change_yuyintext->start("gedit "+filepath);
    QObject::connect(change_yuyintext,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
      QMessageBox::information(this,"information","修改成功");
      qDebug() << "修改语音命令词进程结束......" ;
      delete change_yuyintext;
  });

}
//新建终端启动语音识别程序
void class1_ros_qt_demo::MainWindow::on_open_asr_clicked()
{
    QProcess *open_asr= new QProcess();
    open_asr->start("gnome-terminal --geometry=80x18+732+374 -e '/home/qtz-robot/sim_car/open_asr.sh'");
    ui.yuyin_textEdit->append("语音识别成功!......");
    QObject::connect(open_asr,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
      qDebug() << "asr进程结束......" ;
      delete open_asr;
  });
}
//新建终端启动语音播报程序
void class1_ros_qt_demo::MainWindow::on_open_tts_clicked()
{
  QProcess *open_tts= new QProcess();
  open_tts->start("gnome-terminal --geometry=80x18+732+374 -e '/home/qtz-robot/sim_car/open_tts.sh'");
  ui.yuyin_textEdit->append("语音播报成功!......");
  QObject::connect(open_tts,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
    qDebug() << "tts进程结束......" ;
    delete open_tts;
});
}
//将文本内容修改为应答词
void class1_ros_qt_demo::MainWindow::on_change_voice_words_btn_clicked()
{
  std_msgs::String voice;
  voice.data=ui.change_voice_words_edit->text().toStdString();
  qnode.pub_voicw_words(voice);
  ui.yuyin_textEdit->append("应答词修改成功!......");
}
//将文本内容设置为唤醒词
void class1_ros_qt_demo::MainWindow::on_awake_btn_clicked()
{
 std_msgs::String awake;
 awake.data = ui.awake_words->text().toStdString();
 qnode.pub_awake_words(awake);
 ui.yuyin_textEdit->append("唤醒词修改成功!......");
}
//唤醒角度获取按钮
void class1_ros_qt_demo::MainWindow::on_angle_btn_clicked()
{
  ui.angle_edit->setText(QString::number(qnode.receive_angle()));
}
//完成写入应答词文件路径
void class1_ros_qt_demo::MainWindow::on_select_yuyin_reply_btn_clicked()
{
    pathlist = QFileDialog::getOpenFileName(this,"选择路径","/home/qtz-robot/bigcar_nat/src/xf_mic_tts_offline/src",tr("CPP(*.cpp)"));
    ui.yuyin_reply_edit->setText(pathlist);
}
//根据路径修改语音应答词
void class1_ros_qt_demo::MainWindow::on_change_yuyin_reply_text_btn_clicked()
{
    QProcess *change_yuyin_reply = new QProcess();
    change_yuyin_reply->start("gedit "+pathlist);
    QObject::connect(change_yuyin_reply,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
      QMessageBox::information(this,"information","修改成功");
      qDebug() << "修改语音应答词进程结束......" ;
      delete change_yuyin_reply;
  });
}
//选择保存语音识别文件的路径
void class1_ros_qt_demo::MainWindow::on_save_yuyinpath_clicked()
{
  if(qnode.receive_voice_asr_text()->rowCount()!=0)
  {
    QString filename = QFileDialog::getOpenFileName(this,"选择文件","/home/qtz-robot",tr("TEXT(*.text)"));
    std::ofstream file(filename.toStdString(),std::ios::app);
    if(file.is_open())
    {
      //循环读取每行的内容
      for (int row = 0; row < qnode.receive_voice_asr_text()->rowCount(); ++row)
      {
          QModelIndex index = qnode.receive_voice_asr_text()->index(row, 0);
          QVariant data = qnode.receive_voice_asr_text()->data(index, Qt::UserRole); // 使用 UserRole 获取数据
          QString storedData = data.toString();
          file << storedData.toStdString() << std::endl;
      }
    }
  }
  else
  {
    QMessageBox::warning(this,"Waring","当前没有任何识别内容，无法保存！");
  }
}
/*-----------
  深度相机
------------*/
//启动图像识别
void class1_ros_qt_demo::MainWindow::on_start_picvisual_clicked()
{
  QProcess *start_pic_visual = new QProcess();
  start_pic_visual->start("gnome-terminal --geometry=80x18+732+374 -e '/home/qtz-robot/sim_car/start_yolo.sh'");
  QObject::connect(start_pic_visual,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
    qDebug() << "启动图像识别进程结束......" ;
    delete start_pic_visual;
    ui.visual_view->setText("图像识别启动成功.......");
});
}
//启动人脸识别
void class1_ros_qt_demo::MainWindow::on_start_facevisual_clicked()
{
  QProcess *start_face_visual = new QProcess();
  start_face_visual->start("gnome-terminal --geometry=80x18+732+374 -e '/home/qtz-robot/sim_car/start_face.sh'");
  QObject::connect(start_face_visual,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
    qDebug() << "启动人脸识别进程结束......" ;
    delete start_face_visual;
      ui.visual_view->setText("人脸识别启动成功.......");
});
}
//选择识别数据库
void class1_ros_qt_demo::MainWindow::on_visual_sql_btn_clicked()
{
    QString sql_list = QFileDialog::getOpenFileName(this,"选择路径","/home/qtz-robot/bigcar_nat/src/bigcar_yolo",tr("PT(*.pt)"));
    ui.sql_parh_edit->setText(sql_list);
    QString filename = QFileInfo(sql_list).fileName();
    qDebug()<<filename<<" "<<sql_list;
    QString destinationDir = "/home/qtz-robot/bigcar_nat/src/bigcar_yolo/scripts/weights";     // 目标目录路径
    QString destinationFilePath = QDir(destinationDir).filePath(filename);
     qDebug()<<destinationFilePath;
    if(QFile::exists(destinationFilePath))
    {
        QFile::remove(destinationFilePath);
        ui.visual_view->setText("存在重名文件，已移除......");
        QFile::copy(sql_list,destinationFilePath);
    }
    if(QFile::copy(sql_list,destinationFilePath))
    {
        ui.visual_view->setText("新的数据库文件已替换成功.......");
    }
}
//修改yaml文件
void class1_ros_qt_demo::MainWindow::on_change_yaml_btn_clicked()
{
    QString yaml_list = QFileDialog::getOpenFileName(this,"选择路径","/home/qtz-robot/bigcar_nat/src/bigcar_yolo",tr("YAML(*.yaml)"));
    ui.yaml_path_edit->setText(yaml_list);
    QProcess *change_yaml = new QProcess();
    change_yaml->start("gedit "+yaml_list);
    QObject::connect(change_yaml,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
      QMessageBox::information(this,"information","修改成功");
      qDebug() << "修改yaml进程结束......" ;
      delete change_yaml;
  });
}
/*-----------
  三轴机械臂
------------*/
//启动机械臂仿真
void class1_ros_qt_demo::MainWindow::on_start_arm_sim_clicked()
{
    QProcess *open_arm = new QProcess();
    open_arm->start("gnome-terminal --geometry=80x18+0+374 -e '/home/qtz-robot/sim_car/start_arm_sim.sh'");
    QObject::connect(open_arm,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
      qDebug() << "启动机械臂仿真进程结束......" ;
      delete open_arm;
  });
}
//按下机械臂一档
void class1_ros_qt_demo::MainWindow::on_one_arm_btn_clicked()
{
    arm_forstatus.arm_status = 1;
//    arm_forstatus.claw_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_armbtn_state();
}
//按下机械臂二档
void class1_ros_qt_demo::MainWindow::on_two_arm_btn_clicked()
{
    arm_forstatus.arm_status = 2;
//    arm_forstatus.claw_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_armbtn_state();
}
//按下机械臂二档
void class1_ros_qt_demo::MainWindow::on_three_arm_btn_clicked()
{
    arm_forstatus.arm_status = 3;
//    arm_forstatus.claw_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_armbtn_state();
}
//按下机械臂放下
void class1_ros_qt_demo::MainWindow::on_down_arm_btn_clicked()
{
    arm_forstatus.arm_status = 100;
//    arm_forstatus.claw_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_armbtn_state();
//    qDebug()<<arm_forstatus.arm_status<<"状态";
}
//按下按键爪子一档
void class1_ros_qt_demo::MainWindow::on_one_claw_btn_clicked()
{
    arm_forstatus.claw_status = 1;
//    claw_forstatus.arm_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_clawbtn_state();
}
//按下按键爪子二档
void class1_ros_qt_demo::MainWindow::on_two_claw_btn_clicked()
{
    arm_forstatus.claw_status = 2;
//    claw_forstatus.arm_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_clawbtn_state();
}
//按下按键爪子三档
void class1_ros_qt_demo::MainWindow::on_three_claw_btn_clicked()
{
    arm_forstatus.claw_status = 3;
//    claw_forstatus.arm_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_clawbtn_state();
}
//按下按键爪子四档
void class1_ros_qt_demo::MainWindow::on_four_claw_btn_clicked()
{
    arm_forstatus.claw_status = 4;
//    claw_forstatus.arm_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_clawbtn_state();
}
//按下按键爪子五档
void class1_ros_qt_demo::MainWindow::on_five_claw_btn_clicked()
{
    arm_forstatus.claw_status = 5;
//    claw_forstatus.arm_status = 0;
    qnode.pub_arm_status(arm_forstatus);
    juage_clawbtn_state();
}

void class1_ros_qt_demo::MainWindow::on_start_aim_btn_clicked()
{
    QProcess *start_arm = new QProcess();
    start_arm->start("gnome-terminal --geometry=80x18+0+732 -e '/home/qtz-robot/sim_car/start_fact_arm.sh'");
    QObject::connect(start_arm,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [=]() {
      qDebug() << "启动机械臂进程结束......" ;
      delete start_arm;
  });
    ui.arm_status_lab->setPixmap(QPixmap("://right").scaled(20,20));
}
/*-----------
  单点导航
------------*/
void class1_ros_qt_demo::MainWindow::on_singelnav_goal_toolbtn_clicked()
{
    myrviz->Set_single_nav_Pose();
}
/*-----------
  多点导航
------------*/
void class1_ros_qt_demo::MainWindow::on_multnav_toolbtn_clicked()
{
    myrviz->Set_mult_nav_Pose();
}
/*-----------
  多点导航线段
------------*/
void class1_ros_qt_demo::MainWindow::on_connect_line_clicked()
{
    qnode.connect_lines();
}
/*-----------
  启动多点导航
------------*/
void class1_ros_qt_demo::MainWindow::on_navgation_btn_clicked()
{
    qnode.send_stratpose();
}
/*-----------
 设定初始位姿
------------*/
void class1_ros_qt_demo::MainWindow::on_Pose_toolbtn_clicked()
{
    myrviz->Set_Start_Pose();
}

