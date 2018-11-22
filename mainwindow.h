#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUrl>
#include <QMovie>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void openSerialPort(QString port_name,int baudrate);

    void closeSerialPort();

    void readData();

    void handleError(QSerialPort::SerialPortError error);

    void writeData(const QByteArray &data);

    void acceptConnection();

    void startRead();

    void work_data(QByteArray data);

    void on_bt_open_clicked();

    void on_bt_close_clicked();

    void on_bt_send_clicked();

    void disconnected();

    void on_bt_DTR_clicked();

    void on_rb_Sul_clicked(bool checked);

    void on_rB_norte_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QTcpServer server;
    QTcpSocket* client;
    QSerialPort *serial;
    quint16 port = 6666;
    float LATITUDE = 41.108329;
    QMovie *loading_blue, *loading_green;
    bool norte = false;
};

#endif // MAINWINDOW_H
