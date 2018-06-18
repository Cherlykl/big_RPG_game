#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <iostream>
#include <fstream>
#include <QTime>
#include <ctime>
#include "property.h"
using namespace std;

int MainWindow::movei=0;
int MainWindow::Mi = 0;
int MainWindow::Mi0 = 0;
int MainWindow::Mi1 = 0;
int MainWindow::Mi2 = 0;
int MainWindow::Mi3 = 0;
int MainWindow::Mi4 = 0;
int MainWindow::Mi5 = 0;
int MainWindow::Mi6 = 0;
int MainWindow::Mi7 = 0;
string MainWindow::map_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\map.txt";
string MainWindow::border_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\border.txt";
string MainWindow::rebuild_map_File1 = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\rebuilt_map1.txt";
string MainWindow::rebuild_map_File2 = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\rebuilt_map2.txt";
string MainWindow::determine_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\determine.txt";
string MainWindow::property_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\properties.txt";
string MainWindow::variety_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\player_fairy_monster.txt";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(recoverBoss()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(setSkillPlace()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(recoverPlayerHP()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(canSpeedUP()));
    timer1->start(10000);
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(showworld1()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(movedFairy()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(movedSkill()));
    timer2->start(10);

    ui->pushButton_4->setStyleSheet("color: rgb(255, 255, 255);font: 75 14pt ”Jokerman“;");
    ui->pushButton_4->show();

    ifstream infile(determine_File);
    int flag1,flag2,flag3;
    infile>>flag1>>flag2>>flag3;
    if(flag1==0)
    {
        play_mode.initWorld(map_File,0);
        play_mode.initWorld(border_File,0);
    }
    else
    {
        ui->pushButton_4->hide();
        play_mode.initWorld(rebuild_map_File1,0);
        play_mode.initWorld(rebuild_map_File2,0);
        play_mode.initWorld(variety_File,1);
    }
    if(flag2==1)
    {
        //ui->label_5->hide();
        //ui->pushButton_19->hide();
        ui->pushButton_4->hide();
        setMi6(flag2);
    }

    if(flag3==1)
    {
        ui->pushButton_4->hide();
        setMi7(flag3);
    }

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
    ui->pushButton_18->hide();
    ui->pushButton_19->hide();
    ui->pushButton_20->hide();
    ui->pushButton_21->hide();
    ui->pushButton_22->hide();
    ui->label_7->hide();
    ui->label_6->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_3->setText(QString::number(play_mode.getMoney(),10));
    ui->label_4->setText(QString::number(play_mode.getHP(),10));
    ui->label_5->hide();
    ui->progressBar->hide();
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar_2->hide();
    ui->progressBar_2->setMinimum(0);
    ui->progressBar_2->setMaximum(100);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer1;
    delete timer2;
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    QPainter painter(this);
    if(Mi==0)
       painter.drawPixmap(rect(),QPixmap("://images/start.jpg"));
    if(play_mode.getBoss().getblood_volume()<=0)
    {
        Mi6=0;
        Mi7=0;
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->progressBar->hide();
        ui->progressBar_2->hide();
        painter.drawPixmap(rect(),QPixmap("://images/end.jpg"));
        ui->pushButton_22->show();
    }
    if(play_mode.getPlayer().getBlood()<=0)
    {
        Mi6=0;
        Mi7=0;
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->progressBar->hide();
        ui->progressBar_2->hide();
        painter.drawPixmap(rect(),QPixmap("://images/fail_bg.png"));
        ui->pushButton_22->show();
        ui->pushButton_22->setStyleSheet("font: 75 14pt ”Jokerman“;color: rgb(255, 255, 255);");
    }
    if(Mi==1){
        painter.drawPixmap(rect(),QPixmap("://images/welcome_bg,jpg"));
    }
    if(Mi0==1)
    {
        static int flag=0;
        painter.drawPixmap(rect(), QPixmap("://images/choose_role_bg.jpg"));
        if(flag==0){
            ui->pushButton->show();
            ui->pushButton_2->show();
            flag++;
        }
        role_choose_mode.show(pa,Mi1,personi);
    }
    if(Mi2==1)
    {
        static int flag1=0;
        painter.drawPixmap(rect(), QPixmap("://images/place_choose_bg.jpg"));
        if(flag1==0)
        {
            ui->pushButton_3->setStyleSheet("background:transparent;font: 75 12pt ”Agency FB“; border-image: url(:/images/gate1_bg.png);color: rgb(255, 255, 255);");
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
        painter.drawPixmap(rect(), QPixmap("://images/map.jpg"));
        ui->label_5->setGeometry(QRect(200,60,250,27*4));
        ui->pushButton_19->setGeometry(160,50,311,131);
        play_mode.showcruise(pa,movei);
        ui->pushButton_5->show();
        ui->pushButton_15->show();
        ui->pushButton_16->show();
        ui->pushButton_19->show();
        ui->label_5->show();
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();

        ui->progressBar->show();
        ui->progressBar->setGeometry(570,90,311,21);
        if(play_mode.getPlayer().getBlood()>0)
           ui->progressBar->setValue(play_mode.getPlayer().getBlood());
        else
           ui->progressBar->setValue(0);

        if(ui->label_5->text()=="退出"){
            ui->pushButton_19->hide();
            ui->label_5->hide();
         }

        if ((this->play_mode.getPlayer().getPosX()>=1450)&&(this->play_mode.getPlayer().getPosX())<=1650&&
                (this->play_mode.getPlayer().getPosY()<=652)&&(this->play_mode.getPlayer().getPosY()>=552))
             this->turn_battle();
        }
    if (Mi7 == 1)
    {
         painter.drawPixmap(rect(), QPixmap("://images/battle_bg.jpg"));
         play_mode.showbattle(pa, movei);
         ui->pushButton_15->show();
         ui->pushButton_16->show();
         ui->progressBar->show();
         ui->progressBar->setGeometry(230,30,311,21);
         if(play_mode.getPlayer().getBlood()>0)
            ui->progressBar->setValue(play_mode.getPlayer().getBlood());
         else
             ui->progressBar->setValue(0);
         ui->progressBar_2->show();
         ui->progressBar_2->setGeometry(1230,30,311,21);
         if(play_mode.getBoss().getblood_volume()>0)
             ui->progressBar_2->setValue(play_mode.getBoss().getblood_volume());
         else
             ui->progressBar_2->setValue(0);
    }
    if(Mi4==1)
    {
        painter.drawPixmap(rect(), QPixmap("://images/buy_property_bg.jpg"));
        painter.drawPixmap(400,500,10*32,15*32,QPixmap("://images/npc2.png"));
        ui->pushButton_5->hide();
        ui->pushButton_21->show();
        ui->label_7->show();
        ui->pushButton_6->show();
        ui->pushButton_18->show();
        ui->label->show();
        ui->label_2->hide();
        ui->label_3->show();
        ui->label_4->hide();
        ui->progressBar->hide();
        if(ui->label_7->text()=="退出"){
           ui->pushButton_21->hide();
           ui->label_7->hide();
       }

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
        ui->pushButton_18->show();
    }

    pa->end();
    delete pa;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右

    static int mm =0 ;
    if ((e->key() == Qt::Key_A)||(e->key() == Qt::Key_D)||(e->key() == Qt::Key_W)||(e->key() == Qt::Key_S)
            ||(e->key() == Qt::Key_J))
    {
        movei = mm%2+1;
        if(e->key() == Qt::Key_A)
        {
            mm++;
            this->play_mode.handlePlayerMove(3,1);
            ui->label_3->setText(QString::number(play_mode.getMoney(),10));
            ui->label_4->setText(QString::number(play_mode.getHP(),10));
            this->repaint();
        }
        else if(e->key() == Qt::Key_D)
        {
            mm++;
            this->play_mode.handlePlayerMove(4,1);
            ui->label_3->setText(QString::number(play_mode.getMoney(),10));
            ui->label_4->setText(QString::number(play_mode.getHP(),10));
            this->repaint();
        }
        else if(e->key() == Qt::Key_W)
        {
            mm++;
            this->play_mode.handlePlayerMove(1,1);
            ui->label_3->setText(QString::number(play_mode.getMoney(),10));
            ui->label_4->setText(QString::number(play_mode.getHP(),10));

            this->repaint();
        }
        else if(e->key() == Qt::Key_S)
        {
            mm++;
            this->play_mode.handlePlayerMove(2,1);
            ui->label_3->setText(QString::number(play_mode.getMoney(),10));
            ui->label_4->setText(QString::number(play_mode.getHP(),10));
            this->repaint();
        }
        else if(e->key() == Qt::Key_J)
        {
            mm++;
            this->play_mode.handlePlayerMove(5,1);
            this->play_mode.change_blood();
            ui->label_3->setText(QString::number(play_mode.getMoney(),10));
            this->repaint();
        }
    }
    else
    {
        if (e->key() == Qt::Key_U)
        {
            this->play_mode.handlePlayerMove(6,1);

            this->play_mode.getPlayer().getprop(0).getSkill().setStartX(this->play_mode.getPlayer().getPosX()+210);
            this->play_mode.getPlayer().getprop(0).getSkill().setPosX();
            this->play_mode.getPlayer().getprop(0).getSkill().setStartY(this->play_mode.getPlayer().getPosY()+100);
            this->play_mode.getPlayer().getprop(0).getSkill().setPosY();
            this->play_mode.getPlayer().getprop(0).getSkill().setEndX(this->play_mode.getBoss().getPosX());
            this->play_mode.getPlayer().getprop(0).getSkill().setEndY(this->play_mode.getBoss().getPosY());
            this->play_mode.getPlayer().getprop(0).getSkill().setSteps();
            this->play_mode.getPlayer().getprop(0).getSkill().setFlag(0,3);

            if (play_mode.getPlayer().getprop(0).getname() == Property::tot_name[7])
                play_mode.getPlayer().addblood(10);

            this->repaint();
        }
        else if (e->key() == Qt::Key_I)
        {
            this->play_mode.handlePlayerMove(7,1);
            this->play_mode.getPlayer().getprop(1).getSkill().setStartX(this->play_mode.getPlayer().getPosX()+210);
            this->play_mode.getPlayer().getprop(1).getSkill().setPosX();
            this->play_mode.getPlayer().getprop(1).getSkill().setStartY(this->play_mode.getPlayer().getPosY()+100);
            this->play_mode.getPlayer().getprop(1).getSkill().setPosY();
            this->play_mode.getPlayer().getprop(1).getSkill().setEndX(this->play_mode.getBoss().getPosX());
            this->play_mode.getPlayer().getprop(1).getSkill().setEndY(this->play_mode.getBoss().getPosY());
            this->play_mode.getPlayer().getprop(1).getSkill().setSteps();
            this->play_mode.getPlayer().getprop(1).getSkill().setFlag(0,3);

            if (play_mode.getPlayer().getprop(1).getname() == Property::tot_name[7])
                play_mode.getPlayer().addblood(10);

            this->repaint();
        }
        else if (e->key() == Qt::Key_O)
        {
            this->play_mode.handlePlayerMove(8,1);
            this->play_mode.getPlayer().getprop(2).getSkill().setStartX(this->play_mode.getPlayer().getPosX()+210);
            this->play_mode.getPlayer().getprop(2).getSkill().setPosX();
            this->play_mode.getPlayer().getprop(2).getSkill().setStartY(this->play_mode.getPlayer().getPosY()+100);
            this->play_mode.getPlayer().getprop(2).getSkill().setPosY();
            this->play_mode.getPlayer().getprop(2).getSkill().setEndX(this->play_mode.getBoss().getPosX());
            this->play_mode.getPlayer().getprop(2).getSkill().setEndY(this->play_mode.getBoss().getPosY());
            this->play_mode.getPlayer().getprop(2).getSkill().setSteps();
            this->play_mode.getPlayer().getprop(2).getSkill().setFlag(0,3);

            if (play_mode.getPlayer().getprop(2).getname() == Property::tot_name[7])
                play_mode.getPlayer().addblood(10);

            this->repaint();
        }
        else if (e->key() == Qt::Key_P)
        {
            this->play_mode.handlePlayerMove(9,1);
            this->play_mode.getPlayer().getprop(3).getSkill().setStartX(this->play_mode.getPlayer().getPosX()+210);
            this->play_mode.getPlayer().getprop(3).getSkill().setPosX();
            this->play_mode.getPlayer().getprop(3).getSkill().setStartY(this->play_mode.getPlayer().getPosY()+100);
            this->play_mode.getPlayer().getprop(3).getSkill().setPosY();
            this->play_mode.getPlayer().getprop(3).getSkill().setEndX(this->play_mode.getBoss().getPosX());
            this->play_mode.getPlayer().getprop(3).getSkill().setEndY(this->play_mode.getBoss().getPosY());
            this->play_mode.getPlayer().getprop(3).getSkill().setSteps();
            this->play_mode.getPlayer().getprop(3).getSkill().setFlag(0,3);

            if (play_mode.getPlayer().getprop(3).getname() == Property::tot_name[7])
                play_mode.getPlayer().addblood(10);

            this->repaint();
        }
    }
    this->delay(0.05);
    if(this->play_mode.getPlayer().getPosX()==960)
    {
        ui->pushButton_20->setGeometry(1010,680,281,101);
     ui->pushButton_20->show();
     ui->label_6->show();
    }
    else {
     ui->pushButton_20->hide();
     ui->label_6->hide();
 }
}

void MainWindow::on_pushButton_clicked()
{
    Mi1++;
    this->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    Mi0=0;
    Mi2=1;
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    this->repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    Mi2=0;
    Mi3=1;
    ui->pushButton_3->hide();
    this->repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    static int k=0;
    if(k==0){
        Mi=1;
        k++;
    }
    else if(k==1)
    {
        Mi0=1;
        Mi=0;
        ui->pushButton_4->hide();
    }
    this->repaint();
}

void MainWindow::on_pushButton_5_clicked()
{
    Mi6=0;
    Mi4=1;
    this->repaint();
}

void MainWindow::on_pushButton_6_clicked()
{
    Mi4=0;
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
    ofstream determinefile(determine_File);                         //change_byke

    determinefile<<0<<endl;
    determinefile<<0<<endl;
    determinefile<<0<<endl;

    fstream emptyfile(property_File,ios::out);

    exit(1);
}

void MainWindow::on_pushButton_17_clicked()
{
    Mi3=0;
    Mi6=1;
    this->repaint();
}

void MainWindow::showworld1(){
    personi = clock()%100;
    this->repaint();
}

void MainWindow::movedFairy()
{
    if ((Mi6)||(Mi7))
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int i = rand()%60;
        if (Mi6)
        {
            if(i<15)
                play_mode.handleFairyMove(1);
            if(i>=15&&i<30)
                play_mode.handleFairyMove(2);
            if(i>=30&&i<45)
                play_mode.handleFairyMove(3);
            if(i>=45)
                play_mode.handleFairyMove(4);
        }

        if (Mi7)
        {
            if(i<15)
                play_mode.handleMonsterMove(1);
            if(i>=15&&i<30)
                play_mode.handleMonsterMove(2);
            if(i>=30&&i<45)
                play_mode.handleMonsterMove(3);
            if(i>=45)
                play_mode.handleMonsterMove(4);
        }
        this->repaint();
    }
}

void MainWindow::recoverBoss()
{
    if (Mi7==0)
        return ;
    else if((play_mode.getBoss().getblood_volume())+1<=100)  //加2还是加1？
        play_mode.getBoss().recoverblood_volume();
}

void MainWindow::recoverPlayerHP()
{
    if ((Mi6 == 0) && (Mi7 == 0))
        return ;
    play_mode.getPlayer().setHP(play_mode.getPlayer().getHP()+5);//+5or+1??
    ui->label_4->setText(QString::number(play_mode.getHP(),10));
    this->repaint();
}

void MainWindow::setSkillPlace()
{
    if (Mi6==1)
    {
        play_mode.getFairy1().getSkill().setStartX(play_mode.getFairy1().getPosX());
        play_mode.getFairy1().getSkill().setStartY(play_mode.getFairy1().getPosY());
        play_mode.getFairy1().getSkill().setEndX(play_mode.getPlayer().getPosX());
        play_mode.getFairy1().getSkill().setEndY(play_mode.getPlayer().getPosY());

        play_mode.getFairy1().getSkill().setPosX();
        play_mode.getFairy1().getSkill().setPosY();
        play_mode.getFairy1().getSkill().setSteps();
        play_mode.getFairy1().getSkill().setFlag(0,3);

        play_mode.getFairy2().getSkill().setStartX(play_mode.getFairy2().getPosX());
        play_mode.getFairy2().getSkill().setStartY(play_mode.getFairy2().getPosY());
        play_mode.getFairy2().getSkill().setEndX(play_mode.getPlayer().getPosX());
        play_mode.getFairy2().getSkill().setEndY(play_mode.getPlayer().getPosY());

        play_mode.getFairy2().getSkill().setPosX();
        play_mode.getFairy2().getSkill().setPosY();
        play_mode.getFairy2().getSkill().setSteps();
        play_mode.getFairy2().getSkill().setFlag(0,3);

        play_mode.getFairy3().getSkill().setStartX(play_mode.getFairy3().getPosX());
        play_mode.getFairy3().getSkill().setStartY(play_mode.getFairy3().getPosY());
        play_mode.getFairy3().getSkill().setEndX(play_mode.getPlayer().getPosX());
        play_mode.getFairy3().getSkill().setEndY(play_mode.getPlayer().getPosY());

        play_mode.getFairy3().getSkill().setPosX();
        play_mode.getFairy3().getSkill().setPosY();
        play_mode.getFairy3().getSkill().setSteps();
        play_mode.getFairy3().getSkill().setFlag(0,3);
    }

    if (Mi7==1)
    {
        if(play_mode.getBoss().getblood_volume()>=90)
        {
            play_mode.getBoss().getVersion1().setStartX(play_mode.getBoss().getPosX());
            play_mode.getBoss().getVersion1().setStartY(play_mode.getBoss().getPosY());
            play_mode.getBoss().getVersion1().setEndX(play_mode.getPlayer().getPosX());
            play_mode.getBoss().getVersion1().setEndY(play_mode.getPlayer().getPosY());

            play_mode.getBoss().getVersion1().setPosX();
            play_mode.getBoss().getVersion1().setPosY();
            play_mode.getBoss().getVersion1().setSteps();
            play_mode.getBoss().getVersion1().setFlag(0,3);
        }
        if((play_mode.getBoss().getblood_volume()<90)&&(play_mode.getBoss().getblood_volume()>=75))
        {
            play_mode.getBoss().getVersion2().setStartX(play_mode.getBoss().getPosX());
            play_mode.getBoss().getVersion2().setStartY(play_mode.getBoss().getPosY());
            play_mode.getBoss().getVersion2().setEndX(play_mode.getPlayer().getPosX());
            play_mode.getBoss().getVersion2().setEndY(play_mode.getPlayer().getPosY());

            play_mode.getBoss().getVersion2().setPosX();
            play_mode.getBoss().getVersion2().setPosY();
            play_mode.getBoss().getVersion2().setSteps();
            play_mode.getBoss().getVersion2().setFlag(0,3);
        }
        if((play_mode.getBoss().getblood_volume()<75)&&(play_mode.getBoss().getblood_volume()>=50))
        {
            play_mode.getBoss().getVersion3().setStartX(play_mode.getBoss().getPosX());
            play_mode.getBoss().getVersion3().setStartY(play_mode.getBoss().getPosY());
            play_mode.getBoss().getVersion3().setEndX(play_mode.getPlayer().getPosX());
            play_mode.getBoss().getVersion3().setEndY(play_mode.getPlayer().getPosY());

            play_mode.getBoss().getVersion3().setPosX();
            play_mode.getBoss().getVersion3().setPosY();
            play_mode.getBoss().getVersion3().setSteps();
            play_mode.getBoss().getVersion3().setFlag(0,3);
        }
        if((play_mode.getBoss().getblood_volume()<50)&&(play_mode.getBoss().getblood_volume()>0))
        {
            play_mode.getBoss().getVersion4().setStartX(play_mode.getBoss().getPosX());
            play_mode.getBoss().getVersion4().setStartY(play_mode.getBoss().getPosY());
            play_mode.getBoss().getVersion4().setEndX(play_mode.getPlayer().getPosX());
            play_mode.getBoss().getVersion4().setEndY(play_mode.getPlayer().getPosY());

            play_mode.getBoss().getVersion4().setPosX();
            play_mode.getBoss().getVersion4().setPosY();
            play_mode.getBoss().getVersion4().setSteps();
            play_mode.getBoss().getVersion4().setFlag(0,3);
        }
    }

}

void MainWindow::movedSkill()
{
    if (Mi6 == 1)
    {
        play_mode.getFairy1().getSkill().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
        play_mode.getFairy1().getSkill().setFlag(1,3);
        play_mode.getFairy1().getSkill().move();

        play_mode.getFairy2().getSkill().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
        play_mode.getFairy2().getSkill().setFlag(1,3);
        play_mode.getFairy2().getSkill().move();

        play_mode.getFairy3().getSkill().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
        play_mode.getFairy3().getSkill().setFlag(1,3);
        play_mode.getFairy3().getSkill().move();

        if ((play_mode.getFairy1().getSkill().getFlagBlood())||(play_mode.getFairy2().getSkill().getFlagBlood())||(play_mode.getFairy3().getSkill().getFlagBlood()))
        {

            this->play_mode.change_blood();
        }
        this->repaint();
    }

    else if (Mi7 == 1)
    {
        if(play_mode.getBoss().getblood_volume()>=90)
        {
            play_mode.getBoss().getVersion1().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
            play_mode.getBoss().getVersion1().setFlag(1,3);
            play_mode.getBoss().getVersion1().move();
        }
        if((play_mode.getBoss().getblood_volume()<90)&&(play_mode.getBoss().getblood_volume()>=75))
        {
            play_mode.getBoss().getVersion2().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
            play_mode.getBoss().getVersion2().setFlag(1,3);
            play_mode.getBoss().getVersion2().move();
        }
        if((play_mode.getBoss().getblood_volume()<75)&&(play_mode.getBoss().getblood_volume()>=50))
        {
            play_mode.getBoss().getVersion3().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
            play_mode.getBoss().getVersion3().setFlag(1,3);
            play_mode.getBoss().getVersion3().move();
        }
        if(play_mode.getBoss().getblood_volume()<50)
        {
            play_mode.getBoss().getVersion4().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
            play_mode.getBoss().getVersion4().setFlag(1,3);
            play_mode.getBoss().getVersion4().move();
        }

        play_mode.getPlayer().getprop(0).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
        play_mode.getPlayer().getprop(0).getSkill().setFlag(1,3);
        play_mode.getPlayer().getprop(0).getSkill().move();

        play_mode.getPlayer().getprop(1).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
        play_mode.getPlayer().getprop(1).getSkill().setFlag(1,3);
        play_mode.getPlayer().getprop(1).getSkill().move();

        play_mode.getPlayer().getprop(2).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
        play_mode.getPlayer().getprop(2).getSkill().setFlag(1,3);
        play_mode.getPlayer().getprop(2).getSkill().move();

        play_mode.getPlayer().getprop(3).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
        play_mode.getPlayer().getprop(3).getSkill().setFlag(1,3);
        play_mode.getPlayer().getprop(3).getSkill().move();

        if ((play_mode.getBoss().getVersion1().getFlagBlood())||(play_mode.getBoss().getVersion2().getFlagBlood())||
            (play_mode.getBoss().getVersion3().getFlagBlood())||(play_mode.getBoss().getVersion4().getFlagBlood())||
            (play_mode.getPlayer().getprop(0).getSkill().getFlagBlood())||(play_mode.getPlayer().getprop(1).getSkill().getFlagBlood())||
            (play_mode.getPlayer().getprop(2).getSkill().getFlagBlood())||(play_mode.getPlayer().getprop(3).getSkill().getFlagBlood()))
        {
            this->play_mode.change_blood();
            this->movei = 1;
            this->repaint();
            this->delay(0.5);
        }

        this->repaint();

    }


}

void MainWindow::canSpeedUP()
{
    if ((this->play_mode.getPlayer().getSpeed()==150)&&(Mi7 == 1))
        this->play_mode.getPlayer().setSpeed(32);
}

void MainWindow::delay(double stime){
    clock_t start_time;
    start_time = clock();
    while ((clock()- start_time) < stime * CLOCKS_PER_SEC)
    {
        this->movei = 0;
    }
    this->repaint();
}

void MainWindow::on_pushButton_7_clicked()
{
    Property::addproperty(Property::tot_name[0] );
    this->setContent(0);
}

void MainWindow::on_pushButton_8_clicked()
{
    Property::addproperty(Property::tot_name[1] );
    this->setContent(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    Property::addproperty(Property::tot_name[2] );
    this->setContent(2);
}

void MainWindow::on_pushButton_10_clicked()
{

    Property::addproperty(Property::tot_name[3] );
    this->setContent(3);
}

void MainWindow::on_pushButton_11_clicked()
{
    Property::addproperty(Property::tot_name[4] );
    this->setContent(4);
}

void MainWindow::on_pushButton_12_clicked()
{
    Property::addproperty(Property::tot_name[5] );
    this->setContent(5);
}

void MainWindow::on_pushButton_13_clicked()
{
    Property::addproperty(Property::tot_name[6] );
    this->setContent(6);
}

void MainWindow::on_pushButton_14_clicked()
{
    Property::addproperty(Property::tot_name[7] );
    this->setContent(7);
}


void MainWindow::on_pushButton_18_clicked()
{
    Mi4 = 0;
    Mi5 = 0;
    Mi6 = 1;
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_18->hide();
    this->repaint();
}

void MainWindow::turn_battle()
{
    Mi6 = 0;
    Mi7 = 1;
    play_mode.getPlayer().setPosX(50);
    play_mode.getPlayer().setPosY(50);
    play_mode.getPlayer().setTag(1);
    ui->pushButton_5->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();


}

void MainWindow::on_pushButton_19_clicked()
{
    static int text=0;
  //  static int t=0;
   // cout<<text<<"clicked"<<endl;
    if(Mi6==1){
        if(text==0)
            ui->label_5->setText("欢迎来到贪婪之地");
        if(text==1)
            ui->label_5->setText("每走一步会消耗一点HP值");
        if(text==2)
            ui->label_5->setText("搜集宝石，可以积累财富，在商店购买道具");
        if(text==4)
            ui->label_5->setText("攻击中心的小精灵会获得金币");
        if(text==5)
            ui->label_5->setText("祝你好运");
        if(text==6)
            ui->label_5->setText("退出");

    }
     text++;

    ui->label_5->setGeometry(QRect(200,60,250,27*4));
    ui->label_5->setWordWrap(true);
    ui->label_5->setAlignment(Qt::AlignTop);
  //  this->repaint();

}

void MainWindow::on_pushButton_20_clicked()
{
    static int text1=0;
        if(text1==0)
            ui->label_6->setText("小心");
        if(text1==1)
            ui->label_6->setText("莫要被金钱蒙蔽双眼");
        if(text1==2)
            ui->label_6->setText("年轻人");

    text1++;
    ui->label_6->setGeometry(QRect(1040,700,250,27*4));
    ui->label_6->setWordWrap(true);
    ui->label_6->setAlignment(Qt::AlignTop);

}

void MainWindow::on_pushButton_21_clicked()
{
    static int text2=0;
    switch(text2){
         case 0:
        ui->label_7->setText("欢迎来到商店");
        break;
         case 1:
        ui->label_7->setText("每件武器对应不同的属性");
        break;
         case 2:
        ui->label_7->setText("您最多只能购买4件武器");
        break;
         case 3:
        ui->label_7->setText("退出");
        break;
    }
    text2++;
    ui->label_7->setWordWrap(true);
    ui->label_7->setAlignment(Qt::AlignTop);
}

void MainWindow::setContent(int i)
{
    if(play_mode.getPlayer().getProperty_num()<4){
        if(play_mode.getPlayer().getMoney()>=property_mode.getProperty(i).getValue()){
           play_mode.getPlayer().setMoney(play_mode.getMoney()-property_mode.getProperty(i).getValue());
           QDialog* dia=new QDialog(this);
           dia->setModal(true);
           dia->setStyleSheet("background-image:url(://images/black_bg.jpg;color: rgb(255, 255, 255);)");
           dia->resize(1000,1000);
           QMessageBox::information(dia,"提示","购买成功",QMessageBox::Ok);
           play_mode.getPlayer().setProperty_num(play_mode.getPlayer().getProperty_num()+1);
           ui->label_3->setText(QString::number(play_mode.getPlayer().getMoney(),10));
           delete dia;
        }
        else{
            QDialog* dia=new QDialog(this);
            dia->setModal(true);
            dia->setStyleSheet("background-image:url(://images/black_bg.jpg;color: rgb(255, 255, 255);)");
            dia->resize(1000,1000);
            QMessageBox::information(dia,"提示","余额不足，无法购买",QMessageBox::Ok);
            delete dia;
        }
    }
}

void MainWindow::on_pushButton_22_clicked()
{
    exit(1);
}


