#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdio.h>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbTea->setDisabled(true);
    ui->pbcola->setDisabled(true);
    ui->pbcoffee->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
    ui->pbcoffee->setEnabled(true);
}

void Widget::changeMoney(int diff)
{
    if(diff == 0)
        money=0;

    money +=diff;
    ui->lcdNumber->display(money);

    if(money < 100)
        ui->pbcoffee->setDisabled(true);
    else
        ui->pbcoffee->setEnabled(true);
    if(money < 150)
        ui->pbTea->setDisabled(true);
    else
        ui->pbTea->setEnabled(true);
    if(money < 200)
        ui->pbcola->setDisabled(true);
    else
        ui->pbcola->setEnabled(true);
}

void Widget::on_pb10_clicked()
{
   changeMoney(10);

}

void Widget::on_pb50_clicked()
{
   changeMoney(50);

}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbcola_clicked()
{
   changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    int r500,r100,r50,r10;
    char buff[100];
    r500 = money/500;
    r100 = (money%500)/100;
    r50 = ((money%500)%100)/50;
    r10 = (((money%500)%100)%50)/10;

    sprintf(buff,"반환 돈 500원 %d 개,100원 %d개, 50원 %d개,10원 %d개",r500,r100,r50,r10);
    msg.information(nullptr,"반환",buff);


    changeMoney(0);
}
