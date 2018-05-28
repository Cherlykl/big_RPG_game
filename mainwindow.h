#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include "world1.h"
#include "world2.h"

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
    void keyPressEvent(QKeyEvent *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    World1 role_choose_mode;
    World2 play_mode;
    static int Mi1 ;
    static int Mi2 ;
    static int Mi3 ;
    static int Mi0;
};

#endif // MAINWINDOW_H
