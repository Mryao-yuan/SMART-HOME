#include "mainwindow.h"
#include <QTimer>
#include "ui_mainwindow.h"
#include "QDebug"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer * time=new  QTimer;
   QObject:: connect(time,SIGNAL(timeout()),this,SLOT(Handtimeout()));
   time->start(1000);
   itemModel =new QStandardItemModel(this);
   ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//数据传输到listView上
void MainWindow::showmessage(QString msg){

    QStandardItem *item=new QStandardItem(msg);
    this->itemModel->insertRow(0,item);
    ui->listView->setModel(this->itemModel);
}

void MainWindow::Handtimeout(){

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int temp=rand()%25+10;
    ui->lcdTemp->display(QString::number(temp));
}

void MainWindow::on_pushButton_clicked()
{
    static bool isLedOn=false;  //定义一个状态变量（用于判断灯开和按）,刚开始的时候灯是按的故初始为false
     isLedOn =!isLedOn;           //改变状态
    if(isLedOn){
            ui->pushButton->setStyleSheet("image: url(:/image/open_led.png)");
            ui->label->setStyleSheet("image: url(:/image/led_on.png)");
           showmessage("客厅灯已经打开");
    }    //改变按钮上的状态的图片
            else{
            ui->pushButton->setStyleSheet("image: url(:/image/close_led.png)");
             ui->label->setStyleSheet("image: url(:/image/led_off.png)");
               showmessage("客厅灯已经关闭");}
}

void MainWindow::on_pushButton_2_clicked()
{
    static bool Led2=false;
        Led2=!Led2;
        if(Led2){
            ui->pushButton_2->setStyleSheet("image: url(:/image/open_led.png)");
            ui->label_3->setStyleSheet("image: url(:/image/Spotlight_open.png)");
            showmessage("客厅灯已经打开");}
        else{
            ui->pushButton_2->setStyleSheet("image: url(:/image/close_led.png)");
            ui->label_3->setStyleSheet("image: url(:/image/Spotlight_off.png)");
            showmessage("客厅灯已经关闭");}
}
void MainWindow::on_pushButton_3_clicked()
{
    static bool Led3=false;
    Led3=!Led3;
    if(Led3){
        ui->pushButton_3->setStyleSheet("image: url(:/image/open_led.png)");
        ui->label_5->setStyleSheet("image: url(:/image/voice_open.png)");
        showmessage("卧室灯已经打开");}
    else{
        ui->pushButton_3->setStyleSheet("image: url(:/image/close_led.png)");
        ui->label_5->setStyleSheet("image: url(:/image/voice_off.png)");
        showmessage("卧室灯已经关闭");}

}

void MainWindow::on_pushButton_4_clicked()
{
    static bool Led4=false;
    Led4=!Led4;
    if(Led4){
        ui->pushButton_4->setStyleSheet("image: url(:/image/open_led.png)");
        showmessage("书房灯已经打开");

    }
    else{
        ui->pushButton_4->setStyleSheet("image: url(:/image/close_led.png)");
        showmessage("书房灯已经关闭");
       }
}
