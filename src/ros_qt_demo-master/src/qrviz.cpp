#include "../include/ros_qt_demo/qrviz.hpp"

#include <QDebug>
#include <QException>

QRviz::QRviz(QVBoxLayout* layout)
{
  //创建rviz panel
  render_panel_=new rviz::RenderPanel();
  //向layout添加
  layout->addWidget(render_panel_);
  //创建rviz控制对象
  manager_=new rviz::VisualizationManager(render_panel_);
  tool_manager_=manager_->getToolManager();
  ROS_ASSERT(manager_!=NULL);
  //初始化render_panel 实现放大缩小等操作
  render_panel_->initialize(manager_->getSceneManager(),manager_);

  manager_->setFixedFrame("map");
  //初始化rviz控制对象
  manager_->initialize();
  manager_->startUpdate();
  manager_->removeAllDisplays();
}

void QRviz::Set_FixedFrame(QString Frame_name)
{
    manager_->setFixedFrame(Frame_name);
    qDebug()<<manager_->getFixedFrame();
}

void QRviz::Display_Grid(int Cell_Count,QColor color,bool enable)
{
    if(Grid_!=NULL)
    {
        delete Grid_;
        Grid_=NULL;
    }
    Grid_=manager_->createDisplay("rviz/Grid","myGrid",enable);
    //设置cell Count
    Grid_->subProp("Plane Cell Count")->setValue(Cell_Count);
    //设置颜色
    Grid_->subProp("Color")->setValue(color);
    ROS_ASSERT(Grid_!=NULL);
}

void QRviz::Display_TF(bool enable,bool name_state,bool axes_name)
{
    if(TF_!=NULL)
    {
        delete TF_;
        TF_=NULL;
    }
    TF_=manager_->createDisplay("rviz/TF","myTF",enable);
    TF_->subProp("Show Axes")->setValue(name_state);
    TF_->subProp("Show Names")->setValue(axes_name);
    ROS_ASSERT(TF_!=NULL);
}
void QRviz::Display_Robot(QString robot_desc,bool enable)
{
  if(Robot_!=NULL)
  {
    delete  Robot_;
    Robot_=NULL;
  }
  Robot_=manager_->createDisplay("rviz/RobotModel","robot",enable);
  Robot_->subProp("Robot Description")->setValue(robot_desc);
  ROS_ASSERT(Robot_!=NULL);
}
void QRviz::Display_LaserScan(QString laser_topic,float size,bool enable)
{
    if(LaserScan_!=NULL)
    {
        delete LaserScan_;
        LaserScan_=NULL;
    }
    LaserScan_=manager_->createDisplay("rviz/LaserScan","myLaser",enable);
    LaserScan_->subProp("Topic")->setValue(laser_topic);
    LaserScan_->subProp("Size (m)")->setValue(size);
    ROS_ASSERT(LaserScan_!=NULL);
}

void QRviz::Display_Map(QString topic,QString color_scheme,bool enable)
{
    if(Map_!=NULL)
    {
        delete Map_;
        Map_=NULL;
    }
    Map_=manager_->createDisplay("rviz/Map","myMap",enable);
    ROS_ASSERT(Map_!=NULL);
    Map_->subProp("Topic")->setValue(topic);
    Map_->subProp("Color Scheme")->setValue(color_scheme);
}

void QRviz::Display_Marker(QString marker_topic,bool enable)
{
    if(Marker_!=NULL)
    {
        delete Marker_;
        Marker_=NULL;
    }
    Marker_=manager_->createDisplay("rviz/Marker","myMarker",enable);
    ROS_ASSERT(Marker_!=NULL);
    Marker_->subProp("Marker Topic")->setValue(marker_topic);
    qDebug()<< "test Display_Marker";
}
void QRviz::Display_Path(QString topic, QColor color, bool enable)
{
  if(Path_!=NULL)
  {
      delete Path_;
      Path_=NULL;
  }
  Path_=manager_->createDisplay("rviz/Path","myMap",enable);
  ROS_ASSERT(Path_!=NULL);
  Path_->subProp("Topic")->setValue(topic);
  Path_->subProp("Color")->setValue(color);
}
void QRviz::Set_Start_Pose()
{
    rviz::Tool* current_tool_=tool_manager_->addTool("rviz/SetInitialPose");
    current_tool_->setCursor(Qt::ArrowCursor);
    //获取属性容器
    rviz::Property* pro=current_tool_->getPropertyContainer();
    pro->subProp("Topic")->setValue("/init_pose");
    //设置当前使用的工具
    tool_manager_->setCurrentTool(current_tool_);
}

void QRviz::Set_single_nav_Pose()
{
     rviz::Tool* current_tool_=tool_manager_->addTool("rviz/SetGoal");
     current_tool_->setCursor(Qt::ArrowCursor);
     //获取属性容器
     rviz::Property* pro=current_tool_->getPropertyContainer();
     //
     pro->subProp("Topic")->setValue("/move_base_simple/goal");
     //设置当前使用的工具
     tool_manager_->setCurrentTool(current_tool_);
}

void QRviz::Set_mult_nav_Pose()
{
    rviz::Tool* current_tool_=tool_manager_->addTool("rviz/SetGoal");
    current_tool_->setCursor(Qt::ArrowCursor);
    //设置当前使用的工具
    rviz::Property* pro=current_tool_->getPropertyContainer();
    //
    pro->subProp("Topic")->setValue("/mult_goals");
    tool_manager_->setCurrentTool(current_tool_);
}


