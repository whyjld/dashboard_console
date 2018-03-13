#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnUp_clicked();

    void on_btnDown_clicked();

    void on_btnLeft_clicked();

    void on_btnRight_clicked();

    void on_sbOil_valueChanged(const QString &arg1);

    void on_spinBox_4_valueChanged(const QString &arg1);

    void on_spinBox_3_valueChanged(const QString &arg1);

    void on_sbWater_valueChanged(const QString &arg1);

private:
    void UDPSend(const QString& msg);
    Ui::MainWindow *ui;
    QUdpSocket m_UDP;

};

#endif // MAINWINDOW_H
