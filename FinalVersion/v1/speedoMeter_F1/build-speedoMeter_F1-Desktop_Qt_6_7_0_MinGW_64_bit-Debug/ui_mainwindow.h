/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lvlFullFuel;
    QPushButton *leftIndi;
    QLabel *topConsole;
    QPushButton *petrolindi;
    QPushButton *seatIndi;
    QPushButton *hBrakeIndi;
    QLabel *odometerFrame;
    QLCDNumber *odometer;
    QPushButton *shiftUp;
    QLabel *leftDial;
    QPushButton *warningIndi;
    QLabel *fuelLabel;
    QLabel *rightDial;
    QGraphicsView *leftGView;
    QLabel *engLabel;
    QPushButton *rightIndi;
    QPushButton *oilindi;
    QLabel *centerConsole;
    QLabel *gearNum;
    QLabel *oilTempIndi;
    QGraphicsView *rightGView;
    QLabel *speed;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(971, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lvlFullFuel = new QLabel(centralwidget);
        lvlFullFuel->setObjectName("lvlFullFuel");
        lvlFullFuel->setGeometry(QRect(40, 40, 331, 331));
        leftIndi = new QPushButton(centralwidget);
        leftIndi->setObjectName("leftIndi");
        leftIndi->setGeometry(QRect(270, 20, 81, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../qtResources/pics/leftIndi.svg"), QSize(), QIcon::Normal, QIcon::Off);
        leftIndi->setIcon(icon);
        leftIndi->setIconSize(QSize(70, 70));
        leftIndi->setFlat(true);
        topConsole = new QLabel(centralwidget);
        topConsole->setObjectName("topConsole");
        topConsole->setGeometry(QRect(270, 20, 440, 60));
        petrolindi = new QPushButton(centralwidget);
        petrolindi->setObjectName("petrolindi");
        petrolindi->setGeometry(QRect(370, 30, 42, 42));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../qtResources/pics/nopetrol.svg"), QSize(), QIcon::Normal, QIcon::Off);
        petrolindi->setIcon(icon1);
        petrolindi->setFlat(true);
        seatIndi = new QPushButton(centralwidget);
        seatIndi->setObjectName("seatIndi");
        seatIndi->setGeometry(QRect(520, 30, 40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../../qtResources/pics/seatBelt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        seatIndi->setIcon(icon2);
        seatIndi->setIconSize(QSize(22, 22));
        seatIndi->setFlat(true);
        hBrakeIndi = new QPushButton(centralwidget);
        hBrakeIndi->setObjectName("hBrakeIndi");
        hBrakeIndi->setGeometry(QRect(420, 30, 40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../../../qtResources/pics/handBrakesIndicator.svg"), QSize(), QIcon::Normal, QIcon::Off);
        hBrakeIndi->setIcon(icon3);
        hBrakeIndi->setIconSize(QSize(25, 25));
        hBrakeIndi->setFlat(true);
        odometerFrame = new QLabel(centralwidget);
        odometerFrame->setObjectName("odometerFrame");
        odometerFrame->setGeometry(QRect(270, 320, 440, 60));
        odometer = new QLCDNumber(centralwidget);
        odometer->setObjectName("odometer");
        odometer->setGeometry(QRect(430, 330, 101, 41));
        odometer->setStyleSheet(QString::fromUtf8(""));
        odometer->setFrameShape(QFrame::NoFrame);
        odometer->setDigitCount(6);
        shiftUp = new QPushButton(centralwidget);
        shiftUp->setObjectName("shiftUp");
        shiftUp->setGeometry(QRect(750, 170, 41, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../../../qtResources/pics/gearChange.svg"), QSize(), QIcon::Normal, QIcon::Off);
        shiftUp->setIcon(icon4);
        shiftUp->setFlat(true);
        leftDial = new QLabel(centralwidget);
        leftDial->setObjectName("leftDial");
        leftDial->setGeometry(QRect(20, 20, 360, 360));
        warningIndi = new QPushButton(centralwidget);
        warningIndi->setObjectName("warningIndi");
        warningIndi->setGeometry(QRect(560, 30, 40, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../../../qtResources/pics/warningIndi.svg"), QSize(), QIcon::Normal, QIcon::Off);
        warningIndi->setIcon(icon5);
        warningIndi->setIconSize(QSize(25, 25));
        warningIndi->setFlat(true);
        fuelLabel = new QLabel(centralwidget);
        fuelLabel->setObjectName("fuelLabel");
        fuelLabel->setGeometry(QRect(260, 260, 51, 31));
        fuelLabel->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";"));
        rightDial = new QLabel(centralwidget);
        rightDial->setObjectName("rightDial");
        rightDial->setGeometry(QRect(590, 20, 360, 360));
        leftGView = new QGraphicsView(centralwidget);
        leftGView->setObjectName("leftGView");
        leftGView->setGeometry(QRect(20, 20, 360, 360));
        engLabel = new QLabel(centralwidget);
        engLabel->setObjectName("engLabel");
        engLabel->setGeometry(QRect(820, 260, 91, 31));
        engLabel->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
""));
        rightIndi = new QPushButton(centralwidget);
        rightIndi->setObjectName("rightIndi");
        rightIndi->setGeometry(QRect(620, 20, 81, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../../../qtResources/pics/rightIndi2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        rightIndi->setIcon(icon6);
        rightIndi->setIconSize(QSize(70, 70));
        rightIndi->setFlat(true);
        oilindi = new QPushButton(centralwidget);
        oilindi->setObjectName("oilindi");
        oilindi->setGeometry(QRect(470, 30, 40, 40));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../../../qtResources/pics/oil_Indi.svg"), QSize(), QIcon::Normal, QIcon::Off);
        oilindi->setIcon(icon7);
        oilindi->setIconSize(QSize(30, 30));
        oilindi->setFlat(true);
        centerConsole = new QLabel(centralwidget);
        centerConsole->setObjectName("centerConsole");
        centerConsole->setGeometry(QRect(330, 100, 311, 231));
        gearNum = new QLabel(centralwidget);
        gearNum->setObjectName("gearNum");
        gearNum->setGeometry(QRect(740, 170, 61, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        gearNum->setFont(font);
        gearNum->setStyleSheet(QString::fromUtf8("font: 22pt \"Segoe UI\";\n"
"color: rgb(255, 34, 14);"));
        gearNum->setAlignment(Qt::AlignCenter);
        oilTempIndi = new QLabel(centralwidget);
        oilTempIndi->setObjectName("oilTempIndi");
        oilTempIndi->setGeometry(QRect(610, 40, 331, 331));
        rightGView = new QGraphicsView(centralwidget);
        rightGView->setObjectName("rightGView");
        rightGView->setGeometry(QRect(590, 20, 360, 360));
        speed = new QLabel(centralwidget);
        speed->setObjectName("speed");
        speed->setGeometry(QRect(170, 170, 61, 61));
        speed->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI\";\n"
"color: rgb(255, 34, 14);"));
        speed->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        petrolindi->raise();
        seatIndi->raise();
        hBrakeIndi->raise();
        odometer->raise();
        warningIndi->raise();
        leftGView->raise();
        oilindi->raise();
        centerConsole->raise();
        rightGView->raise();
        rightDial->raise();
        leftDial->raise();
        topConsole->raise();
        odometerFrame->raise();
        lvlFullFuel->raise();
        oilTempIndi->raise();
        shiftUp->raise();
        speed->raise();
        gearNum->raise();
        leftIndi->raise();
        rightIndi->raise();
        fuelLabel->raise();
        engLabel->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lvlFullFuel->setText(QString());
        leftIndi->setText(QString());
        topConsole->setText(QString());
        petrolindi->setText(QString());
        seatIndi->setText(QString());
        hBrakeIndi->setText(QString());
        odometerFrame->setText(QString());
        shiftUp->setText(QString());
        leftDial->setText(QString());
        warningIndi->setText(QString());
        fuelLabel->setText(QCoreApplication::translate("MainWindow", "Fuel", nullptr));
        rightDial->setText(QString());
        engLabel->setText(QCoreApplication::translate("MainWindow", "Eng Temp", nullptr));
        rightIndi->setText(QString());
        oilindi->setText(QString());
        centerConsole->setText(QString());
        gearNum->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        oilTempIndi->setText(QString());
        speed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
