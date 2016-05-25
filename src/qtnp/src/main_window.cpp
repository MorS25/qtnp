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

#include <std_msgs/Float64.h>
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QDomDocument>
#include <QTableView>
#include <boost/algorithm/string/trim.hpp>
#include <iostream>
#include "../include/qtnp/main_window.hpp"
#include "../include/qtnp/uas_model.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtnp {

using namespace Qt;

/*****************************************************************************
** Helpers
*****************************************************************************/

qtnp::Placemarks kml_parsing(const QString &filename) {

    QDomDocument doc;
    QFile file(filename);
    qtnp::Placemarks placemarks_msg;

    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return placemarks_msg; // return nothing

    QDomNodeList placemarks = doc.elementsByTagName("Placemark");
    for (int i = 0; i < placemarks.size(); i++) {

        QDomNode placemark = placemarks.item(i);

        qtnp::Coordinates placemark_coordinates;
        placemark_coordinates.placemark_type = placemark.firstChildElement("name").text().toStdString();
        std::string all_coordinates = placemark.namedItem("Polygon").namedItem("LinearRing")
                .firstChildElement("coordinates").text().toStdString();
        char split_char = '\n';
        boost::algorithm::trim(all_coordinates);
        std::istringstream split(all_coordinates);
        std::vector<std::string> tokens;
        for (std::string each; std::getline(split, each, split_char); tokens.push_back(each));
        split_char = ',';
        for (int i=0; i<tokens.size(); i++){
            std::istringstream split2(tokens[i]);
            std::vector<std::string> tokens2;
            for (std::string each; std::getline(split2, each, split_char); tokens2.push_back(each));
            placemark_coordinates.latitude.push_back(::atof(tokens2[0].c_str()));
            placemark_coordinates.longitude.push_back(::atof(tokens2[1].c_str()));
        }

        placemarks_msg.placemark.push_back(placemark_coordinates);
    }
    return placemarks_msg;
}

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    /*********************
    ** Table view uas
    **********************/
    QStandardItemModel *model = new QStandardItemModel(2,4,this); //2 Rows and 4 Columns

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Sensor type")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Footprint size")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Autonomy %")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Task")));

    ui.table_view_uas->setModel(model);

    /*******************************************/

    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    /*********************
	** Logging
	**********************/
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/


bool MainWindow::validate_connection(){

    bool result(false);

    if ( ui.checkbox_use_environment->isChecked() ) {
        if ( !qnode.init() ) {
            showNoMasterMessage();
        } else {
            ui.button_connect->setEnabled(false);
            result = true;
        }
    } else {
        if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
                   ui.line_edit_host->text().toStdString()) ) {
            showNoMasterMessage();
        } else {
            ui.button_connect->setEnabled(false);
            ui.line_edit_master->setReadOnly(true);
            ui.line_edit_host->setReadOnly(true);
            ui.line_edit_topic->setReadOnly(true);
            result = true;
        }
    }
    return result;
}

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    // close(); // closes the app
}

void MainWindow::showNoKmlMessage() {

    QMessageBox msgBox;
    msgBox.setText("No kml file is defined.");
    msgBox.exec();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
    validate_connection();
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

void MainWindow::on_button_browse_clicked(bool check ) {

    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open kml file"), "/home/", tr("Kml Files (*.kml)"));

    ui.line_edit_kml_file->setPlaceholderText(filename);
    ui.line_edit_kml_file->setReadOnly(true);

    set_kml_filename(filename);

}

void MainWindow::on_button_validate_kml_clicked(bool check ) {

    // TODO
    kml_parsing(kml_filename);

}

void MainWindow::on_button_perform_cdt_clicked(bool check ) {

    if ( get_kml_filename() == "" ) {
        showNoKmlMessage();
    } else {
        if (validate_connection()) {
            qnode.get_tnp_update_pointer()->perform_polygon_definition(kml_parsing(kml_filename).placemark);
        }
    }

}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "qtnp");
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
    QSettings settings("Qt-Ros Package", "qtnp");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace qtnp

