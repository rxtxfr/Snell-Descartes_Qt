
#include "repere.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstring>
#include <sstream>
#include <cstdlib>
#include <QSlider>
#include <QWidget>
#include <QtWidgets>
#include <iostream>
#include <QLineEdit>
#include <iomanip>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rep = new Repere(this);
    ui->grid->addWidget(rep);

    ui->label_angle_incident->setStyleSheet("QLabel { color : red; }");
    ui->label_3->setStyleSheet("QLabel { color : #0000ff; }");
    ui->label_5->setStyleSheet("QLabel { color : #088A08; }");
    ui->label_6->setStyleSheet("QLabel { color : #088A08; }");

    connect( ui->Slider_incident, SIGNAL(valueChanged(int)), rep, SLOT(SetIncident(int)) );
    connect( ui->Slider_incident, SIGNAL(valueChanged(int)), this, SLOT(setLabelIncident(int)) );
    connect(ui->Slider_incident, SIGNAL(valueChanged(int)), this, SLOT(setLabelV2()) );

    connect(ui->line_incident, SIGNAL(returnPressed()), this, SLOT(getIncident()) );

    connect(ui->Edit_V1, SIGNAL(returnPressed()), this, SLOT(getV1()) );
    connect(ui->Slider_V1, SIGNAL(valueChanged(int)), rep, SLOT(setV1(int)) );
    connect(ui->Slider_V1, SIGNAL(valueChanged(int)), this, SLOT(setEdit_V1(int)) );
    connect(ui->Slider_V1, SIGNAL(valueChanged(int)), this, SLOT(setLabelV2()) );

    connect(ui->Edit_V2, SIGNAL(returnPressed()), this, SLOT(getV2()) );
    connect(ui->Slider_V2, SIGNAL(valueChanged(int)), rep, SLOT(setV2(int)) );
    connect(ui->Slider_V2, SIGNAL(valueChanged(int)), this, SLOT(setEdit_V2(int)) );
    connect(ui->Slider_V2, SIGNAL(valueChanged(int)), this, SLOT(setLabelV2()) );

    connect(ui->checkBox_Reflechi, SIGNAL(stateChanged(int)), rep, SLOT(checkReflechi(int)));
    connect(ui->checkBox_Refracte, SIGNAL(stateChanged(int)), rep, SLOT(checkRefracte(int)));
    connect(ui->checkBox_Arcs, SIGNAL(stateChanged(int)), rep, SLOT(checkArcs(int)));

    setLabelV2();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete rep;
}

void MainWindow::setLabelIncident(int value){

    stringstream stream;
    stream << fixed << value;
    string s = stream.str();

    QString valeur = s.c_str();

    ui->line_incident->setText( valeur );
    ui->label_Reflexion->setText( valeur + " °" );
}

void MainWindow::setEdit_V1(int value){

    stringstream stream;
    stream << fixed << value;
    string s = stream.str();

    QString valeur = s.c_str();

    ui->Edit_V1->setText( valeur );
}

void MainWindow::getIncident(){

    QString value = ui->line_incident->text();
    if( value.toInt() < 0 ){
        rep->SetIncident(10);
        ui->line_incident->setText("10");
        ui->Slider_incident->setValue(10);
    }
    if( value.toInt() > 90 ){
        rep->SetIncident(10);
        ui->line_incident->setText("10");
        ui->Slider_incident->setValue(10);
    }


    if( isalpha(value.toStdString()[0]) || isalpha(value.toStdString()[1]) ){
        rep->SetIncident(10);
        ui->line_incident->setText("10");
        ui->Slider_incident->setValue(10);
     }
    else if( (value.toInt() >= 0) && (value.toInt() <= 90 ) ){
        rep->SetIncident(value.toInt());
        ui->Slider_incident->setValue(value.toInt());
    }
}

void MainWindow::getV1(){

    QString value = ui->Edit_V1->text();
    if( value.toInt() < 1000 ){
        rep->setV1(1000);
        ui->Edit_V1->setText("1000");
        ui->Slider_V1->setValue(1000);
     }
    if( value.toInt() > 300000000 ){
        rep->setV1(300000000);
        ui->Edit_V1->setText("300000000");
        ui->Slider_V1->setValue(300000000);
     }


    if( isalpha(value.toStdString()[0]) || isalpha(value.toStdString()[1]) ){
        rep->setV1(300000000);
        ui->Edit_V1->setText("300000000");
        ui->Slider_V1->setValue(300000000);
     }
    else if( (value.toInt() >= 1000) && (value.toInt() <= 300000000 ) ){
        rep->setV1(value.toInt());
        ui->Slider_V1->setValue(value.toInt());
    }
}

void MainWindow::getV2(){

    QString value = ui->Edit_V2->text();
    if( value.toInt() < 1000 ){
        rep->setV2(1000);
        ui->Edit_V2->setText("1000");
        ui->Slider_V2->setValue(1000);
     }
    if( value.toInt() > 300000000 ){
        rep->setV2(300000000);
        ui->Edit_V2->setText("300000000");
        ui->Slider_V2->setValue(300000000);
     }


    if( isalpha(value.toStdString()[0]) || isalpha(value.toStdString()[1]) ){
        rep->setV2(300000000);
        ui->Edit_V2->setText("300000000");
        ui->Slider_V2->setValue(300000000);
     }
    else if( (value.toInt() >= 1000) && (value.toInt() <= 300000000 ) ){
        rep->setV2(value.toInt());
        ui->Slider_V2->setValue(value.toInt());
    }
}

void MainWindow::setEdit_V2(int value){

    stringstream stream;
    stream << fixed << value;
    string s = stream.str();

    QString valeur = s.c_str();

    ui->Edit_V2->setText( valeur );
}


void MainWindow::setLabelV2(){

    stringstream stream;
    stream << fixed << std::setprecision(2) << rep->getRefracte2();
    string s = stream.str();

    s += " °";
    QString valeur = s.c_str();

    ui->label_Refraction_V2->setText( valeur );
}

