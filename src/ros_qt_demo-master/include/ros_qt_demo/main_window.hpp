/**
 * @file /include/class1_ros_qt_demo/main_window.hpp
 *
 * @brief Qt based gui for class1_ros_qt_demo.
 *
 * @date November 2010
 **/
#ifndef class1_ros_qt_demo_MAIN_WINDOW_H
#define class1_ros_qt_demo_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "qrviz.hpp"
#include <serial/serial.h>
#include <QLabel>
#include <QTreeWidgetItem>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QProcess>


/*****************************************************************************
** Namespace
*****************************************************************************/
using namespace std;
namespace class1_ros_qt_demo {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

    void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();
    void slider_connect();
    void slider_connect_2();
    void vel_connect();
    void vel_connect_2();
    void checkboxconnect();
    void juage_armbtn_state();
    void juage_clawbtn_state();
    void Display_Map(int state);
    void Display_Grid(int state);
    void Display_TF(int state);
    void Display_Laser(int state);
    void Display_Robot(int state);
    void Display_Path(int state);
    void Display_marker(int state);
    void Dispaly_fix();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);
    void updateLoggingView(); // no idea why this can't connect automatically


private slots:

    void on_connect_serial_clicked();

    void on_set_map_clicked();

    void on_open_sim_clicked();

    void on_save_map_clicked();

    void on_open_map_clicked();

    void on_start_nav_clicked();

    void on_change_mapname_clicked();

    void on_finsh_savemap_clicked();

    void on_serial_select_clicked();

    void on_select_yuyintext_clicked();

    void on_change_yuyintext_clicked();

    void on_open_asr_clicked();

    void on_open_tts_clicked();

    void on_change_voice_words_btn_clicked();

    void on_awake_btn_clicked();

    void on_angle_btn_clicked();

    void on_select_yuyin_reply_btn_clicked();

    void on_change_yuyin_reply_text_btn_clicked();

    void on_save_yuyinpath_clicked();

    void on_start_picvisual_clicked();

    void on_start_facevisual_clicked();

    void on_visual_sql_btn_clicked();

    void on_change_yaml_btn_clicked();

    void on_start_arm_sim_clicked();

    void on_one_arm_btn_clicked();

    void on_two_arm_btn_clicked();

    void on_three_arm_btn_clicked();

    void on_down_arm_btn_clicked();

    void on_one_claw_btn_clicked();

    void on_two_claw_btn_clicked();

    void on_three_claw_btn_clicked();

    void on_four_claw_btn_clicked();

    void on_five_claw_btn_clicked();

    void on_start_aim_btn_clicked();

    void on_singelnav_goal_toolbtn_clicked();

    void on_multnav_toolbtn_clicked();

    void on_connect_line_clicked();

    void on_navgation_btn_clicked();

    void on_Pose_toolbtn_clicked();

    void robot_statement();

private:
  Ui::MainWindowDesign ui;
  QNode qnode;
  serial::Serial my_serial;
  QRviz *myrviz;
  QRviz *arm_rviz;
  QLabel *lab;
  QLabel label;

  QCheckBox *grid_check;
  QComboBox *fixbox;
  QComboBox *color_box;
  QCheckBox *show_name_box;
  QCheckBox *show_Aexs_box;
  QComboBox *laser_topicbox;
  QLineEdit *laser_size;
  QComboBox *map_topicbox;
  QComboBox *path_topicbox;
  QComboBox *path_color_box;
  QComboBox *style_mapbox;
  QSpinBox *cell_spinbox;
  QLineEdit *Robot_edit;
  QLineEdit *marker_edit;
  QProcess *set_map;
  QProcess *save_map;
  QProcess *open_map;
  QProcess *open_sim;
  QProcess *close_sim;
  QProcess *change_map;
  QProcess *start_nav;
  QString path;
  QString filepath;
  QString pathlist;
  std::string port;
  bool sim_flag=false;
  double vel[6]={0.2,-0.2,0.2,-0.2,0.2,-0.2};
  double vel_2[4]={20,-20,20,-20};
  double Factor;
  int pose_count=0;
  bigcar_nav::target_msg arm_forstatus;
  bigcar_nav::target_msg claw_forstatus;

};

}  // namespace class1_ros_qt_demo

#endif // class1_ros_qt_demo_MAIN_WINDOW_H
