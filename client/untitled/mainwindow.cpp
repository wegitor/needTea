#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUdpSocket>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->pushButton->ev
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::MY()
{
    QUdpSocket * udp = new QUdpSocket();
    QByteArray datagram("test");
    udp->writeDatagram(datagram, QHostAddress::Broadcast, 3838);
    /*
    QUdpSocket txSocket(); //create UDP socket to send to
    QPac
    txPacket.clear();
    txDatagram.clear();

    // Build a packet to send
    txPacket.append("This is a test");
    txPacket.append(" ");

    //Create the datagram
    txDatagram = txPacket.toUtf8(); //convert string to datagram

    //Send the datagram

    txSocket->writeDatagram(txDatagram.data(), txDatagram.size(), QHostAddress("192.168.1.118"), 1000);
    */
}

void MainWindow::on_pushButton_clicked()
{
    MY();
}
