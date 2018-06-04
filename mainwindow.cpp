#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int MainWindow::Mi0 = 0;
int MainWindow::Mi1 = 0;
int MainWindow::Mi2 = 0;
int MainWindow::Mi3 = 0;
int MainWindow::Mi4 = 0;
int MainWindow::Mi5 = 0;
int MainWindow::Mi6 = 0;
string MainWindow::map_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\map.txt";
string MainWindow::rebuild_map_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\rebuilt_map.txt";
string MainWindow::determine_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\determine.txt";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ifstream infile(determine_File);
    int flag;
    while(!infile.eof())
    {
        infile>>flag;
    }
    if(flag==0)
        play_mode.initWorld(map_File);
    else
        play_mode.initWorld(rebuild_map_File);
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    QPainter painter(this);

    if(Mi0==1)
    {
        static int flag=0;
        painter.drawPixmap(rect(), QPixmap("://images/choose_role_bg.jpg"));
        if(flag==0){
            ui->pushButton->show();
            ui->pushButton_2->show();
            flag++;
        }
        if(Mi1%2==0)
            role_choose_mode.show(pa,0);
        else
            role_choose_mode.show(pa,1);
    }
    if(Mi2==1){
        static int flag1=0;
        painter.drawPixmap(rect(), QPixmap("://images/place_choose_bg.jpg"));
        if(flag1==0){
            ui->pushButton_3->show();
            flag1++;
        }
     }
    if(Mi3==1)
    {
        painter.drawPixmap(rect(), QPixmap("://images/gate1_bg.png"));
        ui->pushButton_17->show();

    }
    if(Mi6==1)
    {
        ui->pushButton_17->hide();
        painter.drawPixmap(rect(), QPixmap("://images/black_bg.jpg"));
        play_mode.show(pa);
        ui->pushButton_5->show();
        ui->pushButton_15->show();
        ui->pushButton_16->show();

    }


    if(Mi4==1)
    {
        painter.drawPixmap(rect(), QPixmap("://images/buy_property_bg.jpg"));
        ui->pushButton_5->hide();
        ui->pushButton_6->show();
    }
    if(Mi5==1)
    {
        painter.drawPixmap(rect(), QPixmap("://images/black_bg.jpg"));
        ui->pushButton_6->hide();
        property_mode.show(pa);
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
        ui->pushButton_10->show();
        ui->pushButton_11->show();
        ui->pushButton_12->show();
        ui->pushButton_13->show();
        ui->pushButton_14->show();
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
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    this->repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    Mi3=1;
    ui->pushButton_3->hide();
    this->repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    Mi0=1;
    ui->pushButton_4->hide();
    this->repaint();
}

void MainWindow::on_pushButton_5_clicked()
{
    Mi4=1;
    this->repaint();
}

void MainWindow::on_pushButton_6_clicked()
{
    Mi5=1;
    this->repaint();
}

void MainWindow::on_pushButton_15_clicked()
{
    play_mode.rebuildWorld();
    exit(1);
}

void MainWindow::on_pushButton_16_clicked()
{
    ofstream determinefile(determine_File);
    int flag=0;
    determinefile<<flag<<endl;
    exit(1);
}

void MainWindow::on_pushButton_17_clicked()
{
    Mi6=1;
    this->repaint();
}
