#include "widget.h"
#include "ui_widget.h"
#include "QString"
#include "QDebug"
#include "QLineEdit"
#include "QMessageBox"
#include "mainwindow.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("账号/手机号/邮箱");
    ui->lineEdit_2->setPlaceholderText("密码");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
  //  ui->lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

void Widget::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();
    if(username.isEmpty()||pass.isEmpty()){
        QMessageBox::warning(this,"警告","输入内容不能为空");
    }
    else if(username !="MR YAO"||pass!="123"){
        QMessageBox::information(this,"提示","输入错误");
          }
    else{
              MainWindow *mainwindow=new MainWindow;
             mainwindow->show();
             this->close();
          }
        return  ;
}
Widget::~Widget()
{
    delete ui;
}
