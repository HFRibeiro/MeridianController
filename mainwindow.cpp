#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"
#include <QtMath>

const double PI  = 3.141592653589793238463;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

    client = nullptr;

    connect(&server, SIGNAL(newConnection()),this, SLOT(acceptConnection()));

    ui->cb_baudrate->addItem(QString::number(1200));
    ui->cb_baudrate->addItem(QString::number(2400));
    ui->cb_baudrate->addItem(QString::number(4800));
    ui->cb_baudrate->addItem(QString::number(9600));
    ui->cb_baudrate->addItem(QString::number(19200));
    ui->cb_baudrate->addItem(QString::number(38400));
    ui->cb_baudrate->addItem(QString::number(57600));
    ui->cb_baudrate->addItem(QString::number(115200));

    ui->cb_baudrate->setCurrentIndex(7);

    server.listen(QHostAddress::Any, port);

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts())
    {
       ui->cb_serial->addItem(port.portName());
    }

    ui->cb_serial->setCurrentIndex(1);

    ui->lb_server_state->setText("TCP Server waiting for connection...");
    loading_blue = new QMovie(":/loading_blue.gif");
    loading_blue->start();
    loading_green= new QMovie(":/loading_green.gif");
    loading_green->start();

    ui->lb_loading->setMovie(loading_blue);

    qDebug() << "Setup Done";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readData()
{
   QString read = serial->readLine();
   if(read.contains("conv.Intpusels in steps is:"))
   {
        QString tmp = read.replace("conv.Intpusels in steps is:","");
        ui->lb_int_pulse->setText(tmp);
   }
   else if(read.contains("Puselsis:"))
   {
        QString tmp = read.replace("Puselsis:","");
        ui->lb_pulse->setText(tmp);
   }
   else if(read!="\n") ui->pl_recieved_serial_port->appendPlainText(read);
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::writeData(const QByteArray &data)
{
    if(serial->isOpen()){
        serial->write(data);
    }
    else qDebug() << "Serial not opened!";
}

void MainWindow::openSerialPort(QString port_name, int baudrate)
{
    qDebug() << "Opening :" << port_name;
    serial->setPortName(port_name);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits( QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::SoftwareControl);

    if (serial->open(QIODevice::ReadWrite)){
         ui->bt_open->setEnabled(false);
         ui->bt_close->setEnabled(true);
         ui->bt_send->setEnabled(true);
         qDebug() << "Opened!";
    }
    else QMessageBox::critical(this, tr("Error"), serial->errorString());

}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen()){
        ui->bt_open->setEnabled(true);
        ui->bt_close->setEnabled(false);
        ui->bt_send->setEnabled(false);
       serial->close();
    }
}

void MainWindow::acceptConnection()
{
    client = server.nextPendingConnection();
    connect(client, SIGNAL(readyRead()),this, SLOT(startRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
    qDebug() << "Connected";
    ui->lb_server_state->setText("TCP Server connected, waiting data...");
    ui->lb_loading->setMovie(loading_green);
    openSerialPort(ui->cb_serial->itemText(ui->cb_serial->currentIndex()),ui->cb_baudrate->itemText(ui->cb_serial->currentIndex()).toInt());
}

void MainWindow::startRead()
{
    QByteArray buffer = client->read(client->bytesAvailable());
    qDebug() <<"Recieved from Stellarium: " << buffer;
    work_data(buffer);

}

void MainWindow::work_data(QByteArray data)
{
    long ra  = 0L | data[15] << 24 | (data[14] & 0xFF) << 16 | (data[13] & 0xFF) << 8 | (data[12] & 0xFF);
    // data[16-19] - declination

    long dec = 0L | data[19] << 24 | (data[18] & 0xFF) << 16 | (data[17] & 0xFF) << 8 | (data[16] & 0xFF);

    //compute ra and dec

    qDebug() << "ra:" << ra;

    qDebug() << "dec:" << dec;


    //0x80000000 = 2147483648 equals 12 hours

    double raf  = (double)12 * (double)ra  / (double)2147483648;
    qDebug() <<"RAF: "<< raf;
    //raf = ((double)raf < (double)0)? (double)24.0 + (double)raf: (double)raf;
    // 0x40000000 = 1073741824 equals 90 degrees

    double decf = (double)90 * (double)dec / (double)1073741824; //descomentar isto se não der
    //decf = decf*(double)PI/(double)180;

    qDebug() <<"decf: "<< decf;


    double LAT_rad = qDegreesToRadians(LATITUDE);

    double decf_rad = qDegreesToRadians(decf);

    double ALT_rad_sin = sin(decf_rad)*sin(LAT_rad);

    double ALT = 0;

    if(norte){

        ALT_rad_sin = ALT_rad_sin - cos(decf_rad)*cos(LAT_rad);
        double ALT_rad = asin(ALT_rad_sin);


        ALT = qRadiansToDegrees(ALT_rad);

         qDebug() << ALT;

        ALT = ALT / (double)2 +(double)ui->sp_angle->value();

        qDebug() << ALT;
    }
    else
    {
        ALT_rad_sin = ALT_rad_sin + cos(decf_rad)*cos(LAT_rad);
        double ALT_rad = asin(ALT_rad_sin);


        ALT = qRadiansToDegrees(ALT_rad);

        qDebug() << ALT;

        ALT = ALT / (double)2;

        ALT = (double)180 - (double)ALT; // Ajuste para referencial local

        ALT = ALT +(double)ui->sp_angle->value();



        qDebug() << ALT;
    }

    QString valueToSend = QString::number(ALT) + "\r";
    qDebug() << "Sending: " << valueToSend;

    writeData(valueToSend.toLocal8Bit());





    //QString valueToSend = QString::number(angle) + "\r";
    //qDebug() << "Sending: " << valueToSend;

    //writeData(valueToSend.toLocal8Bit());


     // print some debug info
    /*
    double raf_hour = Math.floor(raf);
    raf = 60.0f * (raf - raf_hour);
    double raf_min  = Math.floor(raf);
    raf = 60.0f * (raf - raf_min);
    double raf_sec  = Math.floor(raf);

    char sign = (decf<0)?'-':'+';
    decf  = Math.abs(decf);
    double decf_deg = Math.floor(decf);
    decf = 60.0f * (decf - decf_deg);
    double decf_min = Math.floor(decf);
    decf = 60.0f * (decf - decf_min);
    double decf_sec = Math.floor(decf);
    */
}

void MainWindow::on_bt_open_clicked()
{
    openSerialPort(ui->cb_serial->itemText(ui->cb_serial->currentIndex()),ui->cb_baudrate->itemText(ui->cb_serial->currentIndex()).toInt());
}

void MainWindow::on_bt_close_clicked()
{
    closeSerialPort();
}

void MainWindow::on_bt_send_clicked()
{
    writeData(ui->tb_send->text().toLocal8Bit()+'\r');
    qDebug() << "Sending: " << ui->tb_send->text().toLocal8Bit()+'\r';
}

void MainWindow::disconnected()
{
    qDebug() << "TCP Client Disconnected";
    ui->lb_server_state->setText("TCP Client Disconnected, waiting connection...");
    ui->lb_loading->setMovie(loading_blue);
}

void MainWindow::on_bt_DTR_clicked()
{
    if (serial->isOpen()){
        serial->setDataTerminalReady(false);
        serial->setDataTerminalReady(true);
    }
}

void MainWindow::on_rb_Sul_clicked(bool checked)
{
    if(checked) norte = false;
}

void MainWindow::on_rB_norte_clicked(bool checked)
{
    if(checked) norte = true;
}
