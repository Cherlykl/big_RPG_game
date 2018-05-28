#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <iostream>
using namespace std;

int MainWindow::Mi0 = 0;
int MainWindow::Mi1 = 0;
int MainWindow::Mi2 = 0;
int MainWindow::Mi3 = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralWidget->setMouseTracking(true);
    play_mode.initWorld("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    //this->role_choose_mode.show(pa,0);

    //role_choose_mode.show(pa,0);
    QPainter painter(this);

    if(Mi0==1)
    {
        painter.drawPixmap(rect(), QPixmap("://images/choose_role_bg.jpg"));
        if(Mi1%2==0)
            role_choose_mode.show(pa,0);
        else
            //painter.drawPixmap(rect(), QPixmap("://images/choose_role_bg.jpg"));
            role_choose_mode.show(pa,1);
    }

    //QPushButton*start=new QPushButton;
   // start->setText("开始");
    //start->show();
    //cout<<Mi1<<endl;



    //cout<<Mi2<<endl;
    if(Mi2==1)
        painter.drawPixmap(rect(), QPixmap("://images/place_choose_bg.jpg"));

    if(Mi3==1)
    {
        painter.drawPixmap(rect(), QPixmap("://images/blank_bg.PNG"));
        //setWindowOpacity(1);
        //setAttribute(Qt::WA_TranslucentBackground);
        play_mode.show(pa);
    }


    pa->end();
    delete pa;
}


void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->play_mode.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->play_mode.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->play_mode.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->play_mode.handlePlayerMove(2,1);
    }
    this->repaint();
}

void MainWindow::on_pushButton_clicked()
{
    Mi1++;
    this->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    Mi2=1;
    this->repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    Mi3=1;
    this->repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    Mi0=1;
    this->repaint();
    //this->hide();
}
