/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *lb_int_pulse;
    QVBoxLayout *verticalLayout;
    QLabel *lb_server_state;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_loading;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rb_Sul;
    QRadioButton *rB_norte;
    QDoubleSpinBox *sp_angle;
    QComboBox *cb_serial;
    QComboBox *cb_baudrate;
    QPushButton *bt_open;
    QPushButton *bt_DTR;
    QPushButton *bt_close;
    QLineEdit *tb_send;
    QPushButton *bt_send;
    QPlainTextEdit *pl_recieved_serial_port;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *lb_pulse;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 533);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/meridian.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lb_int_pulse = new QLabel(centralWidget);
        lb_int_pulse->setObjectName(QString::fromUtf8("lb_int_pulse"));

        horizontalLayout_3->addWidget(lb_int_pulse);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lb_server_state = new QLabel(centralWidget);
        lb_server_state->setObjectName(QString::fromUtf8("lb_server_state"));
        lb_server_state->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_server_state);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lb_loading = new QLabel(centralWidget);
        lb_loading->setObjectName(QString::fromUtf8("lb_loading"));
        lb_loading->setMaximumSize(QSize(150, 150));
        lb_loading->setScaledContents(true);
        lb_loading->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lb_loading);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rb_Sul = new QRadioButton(centralWidget);
        rb_Sul->setObjectName(QString::fromUtf8("rb_Sul"));
        rb_Sul->setChecked(true);

        horizontalLayout_2->addWidget(rb_Sul);

        rB_norte = new QRadioButton(centralWidget);
        rB_norte->setObjectName(QString::fromUtf8("rB_norte"));

        horizontalLayout_2->addWidget(rB_norte);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);

        sp_angle = new QDoubleSpinBox(centralWidget);
        sp_angle->setObjectName(QString::fromUtf8("sp_angle"));
        sp_angle->setAlignment(Qt::AlignCenter);
        sp_angle->setDecimals(4);
        sp_angle->setMinimum(-100.000000000000000);
        sp_angle->setSingleStep(0.001000000000000);
        sp_angle->setValue(-0.427000000000000);

        verticalLayout->addWidget(sp_angle);

        cb_serial = new QComboBox(centralWidget);
        cb_serial->setObjectName(QString::fromUtf8("cb_serial"));

        verticalLayout->addWidget(cb_serial);

        cb_baudrate = new QComboBox(centralWidget);
        cb_baudrate->setObjectName(QString::fromUtf8("cb_baudrate"));

        verticalLayout->addWidget(cb_baudrate);

        bt_open = new QPushButton(centralWidget);
        bt_open->setObjectName(QString::fromUtf8("bt_open"));

        verticalLayout->addWidget(bt_open);

        bt_DTR = new QPushButton(centralWidget);
        bt_DTR->setObjectName(QString::fromUtf8("bt_DTR"));

        verticalLayout->addWidget(bt_DTR);

        bt_close = new QPushButton(centralWidget);
        bt_close->setObjectName(QString::fromUtf8("bt_close"));
        bt_close->setEnabled(false);

        verticalLayout->addWidget(bt_close);

        tb_send = new QLineEdit(centralWidget);
        tb_send->setObjectName(QString::fromUtf8("tb_send"));

        verticalLayout->addWidget(tb_send);

        bt_send = new QPushButton(centralWidget);
        bt_send->setObjectName(QString::fromUtf8("bt_send"));
        bt_send->setEnabled(false);
        bt_send->setCheckable(false);
        bt_send->setAutoDefault(false);
        bt_send->setFlat(false);

        verticalLayout->addWidget(bt_send);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        pl_recieved_serial_port = new QPlainTextEdit(centralWidget);
        pl_recieved_serial_port->setObjectName(QString::fromUtf8("pl_recieved_serial_port"));

        gridLayout_2->addWidget(pl_recieved_serial_port, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lb_pulse = new QLabel(centralWidget);
        lb_pulse->setObjectName(QString::fromUtf8("lb_pulse"));

        horizontalLayout_4->addWidget(lb_pulse);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        bt_send->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MeridianController", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "conv.Intpusels in steps is:", nullptr));
        lb_int_pulse->setText(QApplication::translate("MainWindow", "0", nullptr));
        lb_server_state->setText(QApplication::translate("MainWindow", "TCP Server State:", nullptr));
        lb_loading->setText(QApplication::translate("MainWindow", "loading...", nullptr));
        label->setText(QApplication::translate("MainWindow", "Position:", nullptr));
        rb_Sul->setText(QApplication::translate("MainWindow", "Sul", nullptr));
        rB_norte->setText(QApplication::translate("MainWindow", "Norte", nullptr));
        bt_open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        bt_DTR->setText(QApplication::translate("MainWindow", "DTR", nullptr));
        bt_close->setText(QApplication::translate("MainWindow", "Close", nullptr));
        bt_send->setText(QApplication::translate("MainWindow", "Send", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Puselsis:", nullptr));
        lb_pulse->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
