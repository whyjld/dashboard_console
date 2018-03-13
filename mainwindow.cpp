#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_UDP(this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UDPSend(const QString& msg)
{
    QHostAddress sender(ui->leAddress->text());
    const quint16 port = 1088;
    QByteArray datagram = msg.toLocal8Bit();
    m_UDP.writeDatagram(datagram.data(), datagram.size(), sender, port);
}

void MainWindow::on_btnUp_clicked()
{
    UDPSend("up");
}

void MainWindow::on_btnDown_clicked()
{
    UDPSend("down");
}

void MainWindow::on_btnLeft_clicked()
{
    UDPSend("left");
}

void MainWindow::on_btnRight_clicked()
{
    UDPSend("right");
}

void MainWindow::on_sbOil_valueChanged(const QString &arg1)
{
    UDPSend(QString("OilMass:") + arg1);
}

void MainWindow::on_spinBox_4_valueChanged(const QString &arg1)
{
    UDPSend(QString("Speed:") + arg1);
}

void MainWindow::on_spinBox_3_valueChanged(const QString &arg1)
{
    UDPSend(QString("EngineSpeed:") + arg1);
}

void MainWindow::on_sbWater_valueChanged(const QString &arg1)
{
    UDPSend(QString("WaterTemperature:") + arg1);
}
