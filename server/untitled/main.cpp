#include "mainwindow.h"
//#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QMessageBox>
#include <QUdpSocket>
#include <QTextStream>
void run(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    a.exec();
}
int main(int argc, char *argv[])
{



    while(1)
    {
        QTextStream qout(stdout);

            QUdpSocket *udpSocket = new QUdpSocket(0);
            udpSocket->bind(3838, QUdpSocket::ShareAddress);

            while (udpSocket->waitForReadyRead(-1)) {
                while(udpSocket->hasPendingDatagrams()) {
                    QByteArray datagram;
                    datagram.resize(udpSocket->pendingDatagramSize());
                    QHostAddress sender;
                    quint16 senderPort;

                    udpSocket->readDatagram(datagram.data(), datagram.size(),
                                            &sender, &senderPort);
                    qout << "datagram received from " << sender.toString() << endl;
                    run(argc, argv);
                }
            }


    }
    return 0;
}
