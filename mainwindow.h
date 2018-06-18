#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <string>
#include "world1.h"
#include "world2.h"
#include "world3.h"
#include <Qtimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    static int getMi1(){return Mi1;}
    static int getMi6(){return Mi6;}
    static int getMi7(){return Mi7;}
    static void setMi6(int i) {Mi6 = i;}
    static void setMi7(int i) {Mi7 = i;}
    void keyPressEvent(QKeyEvent *);
    void setContent(int i=0) ;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void turn_battle();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
protected slots:
    void showworld1();
    void movedFairy();
    void recoverBoss();
    void setSkillPlace();
    void movedSkill();
    void recoverPlayerHP();
    void canSpeedUP();
private:
    Ui::MainWindow *ui;
    World1 role_choose_mode;
    World2 play_mode;
    World3 property_mode;
    QTimer *timer1;
    QTimer *timer2;
    int personi;
    static int movei;
    static int Mi;
    static int Mi0;
    static int Mi1 ;
    static int Mi2 ;
    static int Mi3 ;
    static int Mi4 ;
    static int Mi5 ;
    static int Mi6 ;
    static int Mi7 ;
    static string map_File;
    static string border_File;
    static string rebuild_map_File1;
    static string rebuild_map_File2;
    static string variety_File;
    static string determine_File;
    static string property_File;

    //change by wang
    void delay(double stime);

};

#endif // MAINWINDOW_H
