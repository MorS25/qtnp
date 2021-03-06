/**
 * @file /include/qtnp/main_window.hpp
 *
 * @brief Qt based gui for qtnp.
 *
 * @date November 2010
 **/
#ifndef qtnp_MAIN_WINDOW_HPP
#define qtnp_MAIN_WINDOW_HPP

/*****************************************************************************
** Includes
*****************************************************************************/

// #include <QtGui/QMainWindow>
#include <QtWidgets/qmainwindow.h>
#include <QMainWindow>
#include <QStandardItemModel>
#include "ui_main_window.h"
#include "ui_log_settings.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace qtnp {

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

    bool validate_connection();

    void showNoMasterMessage();
    void showNoKmlMessage();
    void showGenericMessage(QString message);

    void set_kml_filename(QString filename){ kml_filename = filename; }
    QString get_kml_filename(){ return kml_filename; }

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
    void on_actionLog_options_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);

    // extra - fb
    void on_button_browse_clicked(bool check );
    void on_button_validate_kml_clicked(bool check );
    void on_button_perform_cdt_clicked(bool check );
    void on_button_add_clicked(bool check);
    void on_button_remove_clicked(bool check);
    void on_button_partition_clicked(bool check);
    void on_button_coverage_clicked(bool check);
    void on_button_go_to_goal_clicked(bool check);

    void on_button_save_uas_config_clicked(bool check);
    void on_button_load_last_uas_conf_clicked(bool check);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically

private:
	Ui::MainWindowDesign ui;
    Ui::Dialog_log_settings ui_log_settings;

	QNode qnode;

    QStandardItemModel *model;
    QString kml_filename;
};

}  // namespace qtnp

#endif // qtnp_MAIN_WINDOW_H
