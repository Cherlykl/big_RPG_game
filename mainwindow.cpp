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
string MainWindow::rebuild_map_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\rebuilt_map.txt";
string MainWindow::determine_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\determine.txt";
string MainWindow::property_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\properties.txt";

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
    timer2->start(50);

    ifstream infile(determine_File);
    int flag;
    while(!infile.eof())
    {
        infile>>flag;
    }
    if(flag==0)
    {
        play_mode.initWorld(map_File);
        play_mode.initWorld(border_File);
    }
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
    ui->pushButton_18->hide();
    ui->label->hide();//gai
    ui->label_2->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit->setText(QString::number(play_mode.getMoney(),10));
    ui->lineEdit_2->setText(QString::number(play_mode.getHP(),10));
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

        play_mode.showcruise(pa,movei);
        ui->pushButton_5->show();
        ui->pushButton_15->show();
        ui->pushButton_16->show();
        ui->label->show();
        ui->label_2->show();
        ui->lineEdit->show();
        ui->lineEdit_2->show();

        //change
        if ((this->play_mode.getPlayer().getPosX()>=1450)&&(this->play_mode.getPlayer().getPosX())<=1650&&
                (this->play_mode.getPlayer().getPosY()<=652)&&(this->play_mode.getPlayer().getPosY()>=552))
             this->turn_battle();
        }
    if (Mi7 == 1)
    {
         painter.drawPixmap(rect(), QPixmap("://images/battle_bg.jpg"));
         play_mode.showbattle(pa, movei);
    }
    if(Mi4==1)
    {
        painter.drawPixmap(rect(), QPixmap("://images/buy_property_bg.jpg"));
        ui->pushButton_5->hide();
        ui->pushButton_6->show();
        ui->pushButton_18->show();
        ui->label->show();
        ui->label_2->hide();
        ui->lineEdit->show();
        ui->lineEdit_2->hide();
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

    static int mm;
    movei = mm%2+1;
    if(e->key() == Qt::Key_A)
    {
        mm++;
        this->play_mode.handlePlayerMove(3,1);
        ui->lineEdit->setText(QString::number(play_mode.getMoney(),10));//
        ui->lineEdit_2->setText(QString::number(play_mode.getHP(),10));//
        this->repaint();
    }
    else if(e->key() == Qt::Key_D)
    {
        mm++;
        this->play_mode.handlePlayerMove(4,1);
        ui->lineEdit->setText(QString::number(play_mode.getMoney(),10));//
        ui->lineEdit_2->setText(QString::number(play_mode.getHP(),10));//
        this->repaint();
    }
    else if(e->key() == Qt::Key_W)
    {
        mm++;
        this->play_mode.handlePlayerMove(1,1);
        ui->lineEdit->setText(QString::number(play_mode.getMoney(),10));//
        ui->lineEdit_2->setText(QString::number(play_mode.getHP(),10));//
        this->repaint();
    }
    else if(e->key() == Qt::Key_S)
    {
        mm++;
        this->play_mode.handlePlayerMove(2,1);
        ui->lineEdit->setText(QString::number(play_mode.getMoney(),10));//
        ui->lineEdit_2->setText(QString::number(play_mode.getHP(),10));//
        this->repaint();
    }
    else if(e->key() == Qt::Key_J)
    {
        mm++;
        this->play_mode.handlePlayerMove(5,1);
        this->repaint();
    }
    else if (e->key() == Qt::Key_U)
    {
        this->play_mode.handlePlayerMove(6,1);

        this->play_mode.getPlayer().getprop(0).getSkill().setStartX(this->play_mode.getPlayer().getPosX()+210);
        this->play_mode.getPlayer().getprop(0).getSkill().setPosX();
        this->play_mode.getPlayer().getprop(0).getSkill().setStartY(this->play_mode.getPlayer().getPosY()+100);
        this->play_mode.getPlayer().getprop(0).getSkill().setPosY();
        this->play_mode.getPlayer().getprop(0).getSkill().setEndX(this->play_mode.getBoss().getPosX());
        this->play_mode.getPlayer().getprop(0).getSkill().setEndY(this->play_mode.getBoss().getPosY());
        this->play_mode.getPlayer().getprop(0).getSkill().setSteps();
        this->play_mode.getPlayer().getprop(0).getSkill().setFlag(0);

        //cout<<this->play_mode.getBoss().getPosX()<<" "<<this->play_mode.getBoss().getPosY()<<endl;
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
        this->play_mode.getPlayer().getprop(1).getSkill().setFlag(0);

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
        this->play_mode.getPlayer().getprop(2).getSkill().setFlag(0);

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
        this->play_mode.getPlayer().getprop(3).getSkill().setFlag(0);

        this->repaint();
    }
    this->delay();
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

void MainWindow::movedFairy(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int i = rand()%60;
    if(i<15)
    {
        play_mode.handleFairyMove(1);
        play_mode.handleMonsterMove(1);
    }
    if(i>=15&&i<30)
    {
        play_mode.handleFairyMove(2);
        play_mode.handleMonsterMove(2);
    }
    if(i>=30&&i<45)
    {
        play_mode.handleFairyMove(3);
        play_mode.handleMonsterMove(3);
    }
    if(i>=45)
    {
        play_mode.handleFairyMove(4);
        play_mode.handleMonsterMove(4);
    }
    this->repaint();
}

void MainWindow::recoverBoss()
{
    if((play_mode.getBoss().getblood_volume())+2<=100)
        play_mode.getBoss().recoverblood_volume();

    //cout<<play_mode.getBoss().getblood_volume()<<endl;
}

void MainWindow::recoverPlayerHP()
{
    play_mode.getPlayer().setHP(play_mode.getPlayer().getHP()+10);
    ui->lineEdit_2->setText(QString::number(play_mode.getHP(),10));
    this->repaint();
}

void MainWindow::setSkillPlace()
{
    play_mode.getFairy1().getSkill().setStartX(play_mode.getFairy1().getPosX());
    play_mode.getFairy1().getSkill().setStartY(play_mode.getFairy1().getPosY());
    play_mode.getFairy1().getSkill().setEndX(play_mode.getPlayer().getPosX());
    play_mode.getFairy1().getSkill().setEndY(play_mode.getPlayer().getPosY());

    play_mode.getFairy1().getSkill().setPosX();
    play_mode.getFairy1().getSkill().setPosY();
    play_mode.getFairy1().getSkill().setSteps();
    play_mode.getFairy1().getSkill().setFlag(0);

    play_mode.getFairy2().getSkill().setStartX(play_mode.getFairy2().getPosX());
    play_mode.getFairy2().getSkill().setStartY(play_mode.getFairy2().getPosY());
    play_mode.getFairy2().getSkill().setEndX(play_mode.getPlayer().getPosX());
    play_mode.getFairy2().getSkill().setEndY(play_mode.getPlayer().getPosY());

    play_mode.getFairy2().getSkill().setPosX();
    play_mode.getFairy2().getSkill().setPosY();
    play_mode.getFairy2().getSkill().setSteps();
    play_mode.getFairy2().getSkill().setFlag(0);

    play_mode.getFairy3().getSkill().setStartX(play_mode.getFairy3().getPosX());
    play_mode.getFairy3().getSkill().setStartY(play_mode.getFairy3().getPosY());
    play_mode.getFairy3().getSkill().setEndX(play_mode.getPlayer().getPosX());
    play_mode.getFairy3().getSkill().setEndY(play_mode.getPlayer().getPosY());

    play_mode.getFairy3().getSkill().setPosX();
    play_mode.getFairy3().getSkill().setPosY();
    play_mode.getFairy3().getSkill().setSteps();
    play_mode.getFairy3().getSkill().setFlag(0);

    play_mode.getBoss().getVersion1().setStartX(play_mode.getBoss().getPosX());
    play_mode.getBoss().getVersion1().setStartY(play_mode.getBoss().getPosY());
    play_mode.getBoss().getVersion1().setEndX(play_mode.getPlayer().getPosX());
    play_mode.getBoss().getVersion1().setEndY(play_mode.getPlayer().getPosY());

    play_mode.getBoss().getVersion1().setPosX();
    play_mode.getBoss().getVersion1().setPosY();
    play_mode.getBoss().getVersion1().setSteps();
    play_mode.getBoss().getVersion1().setFlag(0);

    play_mode.getBoss().getVersion2().setStartX(play_mode.getBoss().getPosX());
    play_mode.getBoss().getVersion2().setStartY(play_mode.getBoss().getPosY());
    play_mode.getBoss().getVersion2().setEndX(play_mode.getPlayer().getPosX());
    play_mode.getBoss().getVersion2().setEndY(play_mode.getPlayer().getPosY());

    play_mode.getBoss().getVersion2().setPosX();
    play_mode.getBoss().getVersion2().setPosY();
    play_mode.getBoss().getVersion2().setSteps();
    play_mode.getBoss().getVersion2().setFlag(0);

    play_mode.getBoss().getVersion3().setStartX(play_mode.getBoss().getPosX());
    play_mode.getBoss().getVersion3().setStartY(play_mode.getBoss().getPosY());
    play_mode.getBoss().getVersion3().setEndX(play_mode.getPlayer().getPosX());
    play_mode.getBoss().getVersion3().setEndY(play_mode.getPlayer().getPosY());

    play_mode.getBoss().getVersion3().setPosX();
    play_mode.getBoss().getVersion3().setPosY();
    play_mode.getBoss().getVersion3().setSteps();
    play_mode.getBoss().getVersion3().setFlag(0);

    play_mode.getBoss().getVersion4().setStartX(play_mode.getBoss().getPosX());
    play_mode.getBoss().getVersion4().setStartY(play_mode.getBoss().getPosY());
    play_mode.getBoss().getVersion4().setEndX(play_mode.getPlayer().getPosX());
    play_mode.getBoss().getVersion4().setEndY(play_mode.getPlayer().getPosY());

    play_mode.getBoss().getVersion4().setPosX();
    play_mode.getBoss().getVersion4().setPosY();
    play_mode.getBoss().getVersion4().setSteps();
    play_mode.getBoss().getVersion4().setFlag(0);

}

void MainWindow::movedSkill()
{
    play_mode.getFairy1().getSkill().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
    play_mode.getFairy1().getSkill().setFlag(1);
    play_mode.getFairy1().getSkill().move();

    play_mode.getFairy2().getSkill().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
    play_mode.getFairy2().getSkill().setFlag(1);
    play_mode.getFairy2().getSkill().move();

    play_mode.getFairy3().getSkill().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
    play_mode.getFairy3().getSkill().setFlag(1);
    play_mode.getFairy3().getSkill().move();

    play_mode.getBoss().getVersion1().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
    play_mode.getBoss().getVersion1().setFlag(1);
    play_mode.getBoss().getVersion1().move();

    play_mode.getBoss().getVersion2().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
    play_mode.getBoss().getVersion2().setFlag(1);
    play_mode.getBoss().getVersion2().move();

    play_mode.getBoss().getVersion3().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
    play_mode.getBoss().getVersion3().setFlag(1);
    play_mode.getBoss().getVersion3().move();

    play_mode.getBoss().getVersion4().setTarget(play_mode.getPlayer().getPosX(),play_mode.getPlayer().getPosY());
    play_mode.getBoss().getVersion4().setFlag(1);
    play_mode.getBoss().getVersion4().move();

    play_mode.getPlayer().getprop(0).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
    play_mode.getPlayer().getprop(0).getSkill().setFlag(1);
    play_mode.getPlayer().getprop(0).getSkill().move();

    play_mode.getPlayer().getprop(1).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
    play_mode.getPlayer().getprop(1).getSkill().setFlag(1);
    play_mode.getPlayer().getprop(1).getSkill().move();

    play_mode.getPlayer().getprop(2).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
    play_mode.getPlayer().getprop(2).getSkill().setFlag(1);
    play_mode.getPlayer().getprop(2).getSkill().move();

    play_mode.getPlayer().getprop(3).getSkill().setTarget(play_mode.getBoss().getPosX(),play_mode.getBoss().getPosY());
    play_mode.getPlayer().getprop(3).getSkill().setFlag(1);
    play_mode.getPlayer().getprop(3).getSkill().move();

    //cout<<play_mode.getBoss().getPosX()<<" "<<play_mode.getBoss().getPosY()<<endl;

    this->repaint();
}

void MainWindow::canSpeedUP()
{
    if (this->play_mode.getPlayer().getSpeed()==150)
        this->play_mode.getPlayer().setSpeed(32);
}

void MainWindow::delay(){
    clock_t start_time;
    start_time = clock();
    while ((clock()- start_time) <0.05 * CLOCKS_PER_SEC)
    {
        this->movei = 0;
    }
    this->repaint();
}

void MainWindow::on_pushButton_7_clicked()
{
    Property::addproperty(Property::tot_name[0] );
}

void MainWindow::on_pushButton_8_clicked()
{
    Property::addproperty(Property::tot_name[1] );
}

void MainWindow::on_pushButton_9_clicked()
{
    Property::addproperty(Property::tot_name[2] );
}

void MainWindow::on_pushButton_10_clicked()
{

    Property::addproperty(Property::tot_name[3] );
}

void MainWindow::on_pushButton_11_clicked()
{
    Property::addproperty(Property::tot_name[4] );
}

void MainWindow::on_pushButton_12_clicked()
{
    Property::addproperty(Property::tot_name[5] );
}

void MainWindow::on_pushButton_13_clicked()
{
    Property::addproperty(Property::tot_name[6] );
}

void MainWindow::on_pushButton_14_clicked()
{
    Property::addproperty(Property::tot_name[7] );
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
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();

}
