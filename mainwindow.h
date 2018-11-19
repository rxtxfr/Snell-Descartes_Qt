#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "repere.h"

#include <QSlider>
#include <QLineEdit>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


signals:

public slots:
    void getIncident();
    void setLabelIncident(int value);
    void getV1();
    void setEdit_V1(int value);

    void getV2();
    void setEdit_V2(int value);
    void setLabelV2();

private:
    Ui::MainWindow *ui;
    Repere *rep;
};

#endif // MAINWINDOW_H
