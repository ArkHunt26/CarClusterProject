#include "mainwindow.h"
#include "ui_mainwindow.h"

// #define rTimIntrval 100

using namespace std;

static int runTimCnt = 0;

constexpr int pT = 20;
constexpr int rTimIntrval = 250;
constexpr int rot_tim_pT = 250;

char buff[10] = "";

typedef enum
{
    ALL_OFF=0,
    NO_PETROL,
    HAND_BRAKE,
    OIL_INDI,
    SEAT_BELT,
    WARNING,
    OTHER
}INDI_TYPE;

typedef enum
{
    LOW_SPEED = 0,
    HIGH_SPEED
}speedStatus;

QString gN;

static float angle = 0;
// static int F_flag =0, R_Flag = 0;

static int rFlag = 0;


static QTimer *PStart_timer;

static QTimer *Rev_Rot_timer;


static QTimer *running_timer;

static QTimer *left_Rot_timer;

static INDI_TYPE indi = ALL_OFF;

static int indiFlag = 0;

static speedStatus speedIndi;


void MainWindow::resourceInit()
{
    QPixmap pix1(":/Resources/Imgs/LeftDial.png");
    int width1 = ui->leftDial->width();
    int height1 = ui->leftDial->height();
    ui->leftDial->setPixmap(pix1.scaled(width1,height1,Qt::KeepAspectRatio));


    QPixmap pix2(":/Resources/Imgs/rightDial2.png");
    int width2 = ui->rightDial->width();
    int height2 = ui->rightDial->height();
    ui->rightDial->setPixmap(pix2.scaled(width2,height2,Qt::KeepAspectRatio));


    QPixmap pix3(":/Resources/Imgs/topConsoleUpdate1.png");
    int width3 = ui->topConsole->width();
    int height3 = ui->topConsole->height();
    ui->topConsole->setPixmap(pix3.scaled(width3,height3,Qt::KeepAspectRatio));


    QPixmap pix4(":/Resources/Imgs/bottomConsoleUpdate1.png");
    int width4 = ui->odometerFrame->width();
    int height4 = ui->odometerFrame->height();
    ui->odometerFrame->setPixmap(pix4.scaled(width4,height4,Qt::KeepAspectRatio));


    QPixmap pix5(":/Resources/Imgs/lvlFull.png");
    int width5 = ui->lvlFullFuel->width();
    int height5 = ui->lvlFullFuel->height();
    ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));

    QPixmap pix6(":/Resources/Imgs/full.png");
    int width6 = ui->oilTempIndi->width();
    int height6 = ui->oilTempIndi->height();
    ui->oilTempIndi->setPixmap(pix6.scaled(width6,height6,Qt::KeepAspectRatio));
    // QPixmap pix7("C:/Users/Rohith/Desktop/qtResources/pics/clusterCarModelImgBgR2.png");

    // QPixmap pix7("C:/Users/Rohith/Downloads/mclaren-removebg-preview.png");
    QPixmap pix7(":/Resources/Imgs/car4-removebg-preview.png");
    int width7 = ui->centerConsole->width();
    int height7 = ui->centerConsole->height();
    ui->centerConsole->setPixmap(pix7.scaled(width7,height7,Qt::KeepAspectRatio));

    // QPixmap pix8("C:/Users/Rohith/Desktop/qtResources/pics/car1-removebg-preview.png");
    // int width8 = ui->centerConsole->width();
    // int height8 = ui->centerConsole->height();
    // ui->centerConsole->setPixmap(pix8.scaled(width8,height8,Qt::KeepAspectRatio));

    Scene1 = new QGraphicsScene(this);
    Scene1->addPixmap(QPixmap(":/Resources/Imgs/needle3.png"));
    ui->leftGView->setScene(Scene1);



    Scene2 = new QGraphicsScene(this);
    Scene2->addPixmap(QPixmap(":/Resources/Imgs/needle3.png"));
    ui->rightGView->setScene(Scene2);


    gN = 'N';
    ui->gearNum->setText(gN);

    ui->fuelLabel->setStyleSheet("color: #3DFF73");
    ui->engLabel->setStyleSheet("color: #3DFF73");

}

int rotationDirection = 1;
static int ggFlag = 0;
void MainWindow::iconsInit()
{
    ////ROTATE ANIMATION STARTS
    ///

    // static float angle = 0;
    // static int F_flag =0, R_Flag = 0;

    // static int rFlag = 0;

    PStart_timer = new QTimer(this);

    // static QTimer *PStart_timer = new QTimer(this);


    PStart_timer->setInterval(pT);
    connect(PStart_timer, &QTimer::timeout, this, [this]{
        // ui->leftGView->rotate(rotationDirection * angle);
        // ui->rightGView->rotate(rotationDirection * angle);
            // ui->leftGView->rotate(angle);
            // ui->rightGView->rotate(angle);
        // PStart_timer->start();

        // if(rFlag == 1)
        // {
            if(angle < 7.2 && rFlag == 0)
            {
                // INDILIGHTINGS(INDI_ON);
                angle += 0.1;

                ui->leftGView->rotate(angle);
                ui->rightGView->rotate(angle);

                ui->seatIndi->show();
                ui->oilindi->show();
                ui->hBrakeIndi->show();
                ui->warningIndi->show();
                ui->petrolindi->show();
                ui->rightIndi->show();
                ui->leftIndi->show();
            }
            else if(ggFlag == 0)
            {
                ui->leftGView->resetTransform();
                ui->rightGView->resetTransform();
                angle = 0;
                rFlag = 1;
                ggFlag = 1;
                ui->seatIndi->hide();
                ui->oilindi->hide();
                ui->hBrakeIndi->hide();
                ui->warningIndi->hide();
                ui->petrolindi->hide();
                ui->rightIndi->hide();
                ui->leftIndi->hide();
                PStart_timer->stop();

                rotationDirection *= -1;
            }
        // }

            // // if(rFlag==1)
            // {
            //     runTimCnt++;


            //     switch(runTimCnt)
            //     {
            //     case 1:
            //         ui->seatIndi->hide();
            //         ui->oilindi->hide();
            //         ui->hBrakeIndi->hide();
            //         ui->warningIndi->hide();
            //         ui->petrolindi->hide();
            //         ui->rightIndi->show();
            //         ui->leftIndi->show();
            //         break;

            //     case 2:
            //         ui->petrolindi->show();
            //         ui->hBrakeIndi->hide();
            //         ui->oilindi->hide();
            //         ui->seatIndi->hide();
            //         ui->warningIndi->hide();
            //         ui->rightIndi->hide();
            //         ui->leftIndi->hide();
            //         break;

            //     case 3:
            //         ui->petrolindi->hide();
            //         ui->hBrakeIndi->show();
            //         ui->oilindi->hide();
            //         ui->seatIndi->hide();
            //         ui->warningIndi->hide();
            //         ui->rightIndi->show();
            //         ui->leftIndi->hide();
            //         break;

            //     case 4:
            //         ui->petrolindi->hide();
            //         ui->hBrakeIndi->hide();
            //         ui->oilindi->show();
            //         ui->seatIndi->hide();
            //         ui->warningIndi->hide();
            //         ui->rightIndi->hide();
            //         ui->leftIndi->hide();
            //         break;

            //     case 5:
            //         ui->petrolindi->hide();
            //         ui->hBrakeIndi->hide();
            //         ui->oilindi->hide();
            //         ui->seatIndi->show();
            //         ui->warningIndi->hide();
            //         ui->rightIndi->hide();
            //         ui->leftIndi->show();
            //         break;

            //     case 6:
            //         ui->petrolindi->hide();
            //         ui->hBrakeIndi->hide();
            //         ui->oilindi->hide();
            //         ui->seatIndi->hide();
            //         ui->warningIndi->show();
            //         ui->rightIndi->hide();
            //         ui->leftIndi->hide();
            //         break;

            //     default:
            //         indiFlag = 0;
            //         break;

            //     }
            // }

    });
    PStart_timer->start();
}

void MainWindow::afterEffect()
{
    running_timer = new QTimer(this);

    // static QTimer *PStart_timer = new QTimer(this);


    running_timer->setInterval(rTimIntrval);
    connect(running_timer, &QTimer::timeout, this, [this]{

        if(rFlag == 1)
            runTimCnt++;

        if(runTimCnt == 1)
        {

            // iFlag = 1;
            // indi++;
            indiFlag++;
            ui->seatIndi->show();
            ui->oilindi->show();
            ui->hBrakeIndi->show();
            ui->warningIndi->show();
            ui->petrolindi->show();
            ui->rightIndi->show();
            ui->leftIndi->show();
        }
        else
        {
            // iFlag = 0;

            ui->seatIndi->hide();
            ui->oilindi->hide();
            ui->hBrakeIndi->hide();
            ui->warningIndi->hide();
            ui->petrolindi->hide();
            ui->rightIndi->hide();
            ui->leftIndi->hide();
            runTimCnt = 0;

        }

        if(indiFlag == 1)
        {
            QPixmap pix5(":/Resources/Imgs/full.png");
            int width5 = ui->lvlFullFuel->width();
            int height5 = ui->lvlFullFuel->height();
            ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            ui->fuelLabel->setStyleSheet("color: #3DFF73");

            QPixmap pix6(":/Resources/Imgs/full.png");
            int width6 = ui->oilTempIndi->width();
            int height6 = ui->oilTempIndi->height();
            ui->oilTempIndi->setPixmap(pix6.scaled(width6,height6,Qt::KeepAspectRatio));
            ui->engLabel->setStyleSheet("color: #3DFF73");
            // ui->engLabel->setStyleSheet("font-weight: bold;");
            ui->oilindi->hide();

            ui->petrolindi->hide();
        }
        if(indiFlag == 2)
        {
            QPixmap pix5(":/Resources/Imgs/fullmOne.png");
            int width5 = ui->lvlFullFuel->width();
            int height5 = ui->lvlFullFuel->height();
            ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            ui->fuelLabel->setStyleSheet("color: #3DFF73");

            QPixmap pix6(":/Resources/Imgs/fullmOne.png");
            int width6 = ui->oilTempIndi->width();
            int height6 = ui->oilTempIndi->height();
            ui->oilTempIndi->setPixmap(pix6.scaled(width6,height6,Qt::KeepAspectRatio));
            ui->engLabel->setStyleSheet("color: #3DFF73");
            // ui->engLabel->setStyleSheet("font-weight: bold;");
            ui->oilindi->hide();

            ui->petrolindi->hide();
        }
        if(indiFlag == 3)
        {
            QPixmap pix5(":/Resources/Imgs/fullmTwo.png");
            int width5 = ui->lvlFullFuel->width();
            int height5 = ui->lvlFullFuel->height();
            ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            ui->fuelLabel->setStyleSheet("color: #3DFF73");

            QPixmap pix6(":/Resources/Imgs/fullmTwo.png");
            int width6 = ui->oilTempIndi->width();
            int height6 = ui->oilTempIndi->height();
            ui->oilTempIndi->setPixmap(pix6.scaled(width6,height6,Qt::KeepAspectRatio));
            ui->engLabel->setStyleSheet("color: #3DFF73");
            // ui->engLabel->setStyleSheet("font-weight: bold;");
            ui->oilindi->hide();

            ui->petrolindi->hide();
        }
        if(indiFlag == 4)
        {
            QPixmap pix5(":/Resources/Imgs/quaterY.png");
            int width5 = ui->lvlFullFuel->width();
            int height5 = ui->lvlFullFuel->height();
            ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            ui->fuelLabel->setStyleSheet("color: #FBFF3D");

            QPixmap pix6(":/Resources/Imgs/quaterY.png");
            int width6 = ui->oilTempIndi->width();
            int height6 = ui->oilTempIndi->height();
            ui->oilTempIndi->setPixmap(pix6.scaled(width6,height6,Qt::KeepAspectRatio));
            ui->engLabel->setStyleSheet("color: #FBFF3D");
            // ui->engLabel->setStyleSheet("font-weight: bold;");
            ui->oilindi->hide();

            ui->petrolindi->hide();

        }
        if(indiFlag == 5)
        {
            QPixmap pix5(":/Resources/Imgs/lessY.png");
            int width5 = ui->lvlFullFuel->width();
            int height5 = ui->lvlFullFuel->height();
            ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            ui->fuelLabel->setStyleSheet("color: #FBFF3D");

            QPixmap pix6(":/Resources/Imgs/lessY.png");
            int width6 = ui->oilTempIndi->width();
            int height6 = ui->oilTempIndi->height();
            ui->oilTempIndi->setPixmap(pix6.scaled(width6,height6,Qt::KeepAspectRatio));
            ui->engLabel->setStyleSheet("color: #FBFF3D");
            // ui->engLabel->setStyleSheet("font-weight: bold;");
            ui->oilindi->hide();

            ui->petrolindi->hide();

        }
        if(indiFlag == 6)
        {
            QPixmap pix5(":/Resources/Imgs/veryLess.png");
            int width5 = ui->lvlFullFuel->width();
            int height5 = ui->lvlFullFuel->height();
            ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            // ui->fuelLabel->setStyleSheet("{color: #F91818}");
            ui->fuelLabel->setStyleSheet("color: #F91818;");


            // QColor color = QColorDialog::getColor(Qt::red, this);
            // QPalette palette = ui->fuelLabel->palette();
            // palette.setColor(QPalette::WindowText, color);
            // ui->fuelLabel->setPalette(palette);

            QPixmap pix6(":/Resources/Imgs/veryLess.png");
            int width6 = ui->oilTempIndi->width();
            int height6 = ui->oilTempIndi->height();
            ui->oilTempIndi->setPixmap(pix6.scaled(width6,height6,Qt::KeepAspectRatio));
            ui->engLabel->setStyleSheet("color: #F91818;");
            // ui->engLabel->setStyleSheet("font-weight: bold;");
            ui->oilindi->show();

            ui->petrolindi->show();
        }



        if(indiFlag > 6)
        {
            indiFlag = 0;
        }

        switch (indiFlag) {
        case 0:
            ui->seatIndi->hide();
            ui->oilindi->hide();
            ui->hBrakeIndi->hide();
            ui->warningIndi->hide();
            ui->petrolindi->hide();
            ui->rightIndi->show();
            ui->leftIndi->show();
            gN = 'R';

            // QPixmap pix5(":/Resources/Imgs/full.png");
            // int width5 = ui->lvlFullFuel->width();
            // int height5 = ui->lvlFullFuel->height();
            // ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            // ui->fuelLabel->setStyleSheet("color: #3DFF73");
            // ui->petrolindi->hide();
            break;

        case 1:
            ui->petrolindi->show();
            ui->hBrakeIndi->hide();
            ui->oilindi->hide();
            ui->seatIndi->hide();
            ui->warningIndi->hide();
            ui->rightIndi->hide();
            ui->leftIndi->hide();

            gN = '1';

            // pix5(":/Resources/Imgs/fullmOne.png");
            // width5 = ui->lvlFullFuel->width();
            // height5 = ui->lvlFullFuel->height();
            // ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            // ui->fuelLabel->setStyleSheet("color: #3DFF73");
            // ui->petrolindi->hide();
            break;

        case 2:
            ui->petrolindi->hide();
            ui->hBrakeIndi->show();
            ui->oilindi->hide();
            ui->seatIndi->hide();
            ui->warningIndi->hide();
            ui->rightIndi->show();
            ui->leftIndi->hide();

            gN = '2';

            // pix5(":/Resources/Imgs/fullmTwo.png");
            // width5 = ui->lvlFullFuel->width();
            // height5 = ui->lvlFullFuel->height();
            // ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            // ui->fuelLabel->setStyleSheet("color: #3DFF73");
            // ui->petrolindi->hide();
            break;

        case 3:
            ui->petrolindi->hide();
            ui->hBrakeIndi->hide();
            ui->oilindi->show();
            ui->seatIndi->hide();
            ui->warningIndi->hide();
            ui->rightIndi->hide();
            ui->leftIndi->hide();

            gN = '3';

            // pix5(":/Resources/Imgs/quaterY.png");
            // width5 = ui->lvlFullFuel->width();
            // height5 = ui->lvlFullFuel->height();
            // ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            // ui->fuelLabel->setStyleSheet("color: #FBFF3D");
            // ui->petrolindi->hide();
            break;

        case 4:
            ui->petrolindi->hide();
            ui->hBrakeIndi->hide();
            ui->oilindi->hide();
            ui->seatIndi->show();
            ui->warningIndi->hide();
            ui->rightIndi->hide();
            ui->leftIndi->show();

            gN = '4';

            // pix5(":/Resources/Imgs/lessY.png");
            // width5 = ui->lvlFullFuel->width();
            // height5 = ui->lvlFullFuel->height();
            // ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            // ui->fuelLabel->setStyleSheet("color: #FBFF3D");
            // ui->petrolindi->hide();
            break;

        case 5:
            gN = '5';

            // ui->petrolindi->hide();
            // ui->hBrakeIndi->hide();
            // ui->oilindi->hide();
            // ui->seatIndi->hide();
            // ui->warningIndi->show();
            // ui->rightIndi->hide();
            // ui->leftIndi->hide();

            // pix5(":/Resources/Imgs/veryLess.png");
            // width5 = ui->lvlFullFuel->width();
            // height5 = ui->lvlFullFuel->height();
            // ui->lvlFullFuel->setPixmap(pix5.scaled(width5,height5,Qt::KeepAspectRatio));
            // // ui->fuelLabel->setStyleSheet("{color: #F91818}");
            // ui->fuelLabel->setStyleSheet("color: #F91818;");

            // ui->petrolindi->show();

            break;

        default:
            indiFlag = 0;
            break;
        }

        ui->gearNum->setText(gN);


    });
    running_timer->start();

}

void MainWindow::leftRotation()
{
    ////ROTATE ANIMATION STARTS
    ///

    // static float angle = 0;
    // static int F_flag =0, R_Flag = 0;

    // static int rFlag = 0;

    left_Rot_timer = new QTimer(this);

    // static QTimer *PStart_timer = new QTimer(this);


    left_Rot_timer->setInterval(rot_tim_pT);
    connect(left_Rot_timer, &QTimer::timeout, this, [this]{
        ui->leftGView->rotate(angle);
        ui->rightGView->rotate(angle);
        // PStart_timer->start();

        if(angle >5)
        {
            ui->shiftUp->show();
        }
        else
        {
            ui->shiftUp->hide();
        }

        if(angle <4)
        {
            speedIndi = LOW_SPEED;
            QPixmap pix7(":/Resources/Imgs/car4-removebg-preview.png");
            int width7 = ui->centerConsole->width();
            int height7 = ui->centerConsole->height();
            ui->centerConsole->setPixmap(pix7.scaled(width7,height7,Qt::KeepAspectRatio));
        }
        else
        {
            speedIndi = HIGH_SPEED;
            QPixmap pix8(":/Resources/Imgs/car3-removebg-preview.png");
            int width8 = ui->centerConsole->width();
            int height8 = ui->centerConsole->height();
            ui->centerConsole->setPixmap(pix8.scaled(width8,height8,Qt::KeepAspectRatio));
        }


        if(angle < 7.2)
        {
            // INDILIGHTINGS(INDI_ON);
            angle += 0.1;

            ui->seatIndi->show();
            ui->oilindi->show();
            ui->hBrakeIndi->show();
            ui->warningIndi->show();
            ui->petrolindi->show();
            ui->rightIndi->show();
            ui->leftIndi->show();
            char daBuff[10];
            sprintf(daBuff,"%d\0",(int)(angle*10.8));

            QString mm = QString(daBuff);
            ui->speed->setText(mm);
        }
        else
        {
            ui->leftGView->resetTransform();
            ui->rightGView->resetTransform();
            angle = 0;
            // rFlag = 1;
            ui->seatIndi->hide();
            ui->oilindi->hide();
            ui->hBrakeIndi->hide();
            ui->warningIndi->hide();
            ui->petrolindi->hide();
            ui->rightIndi->hide();
            ui->leftIndi->hide();
            PStart_timer->stop();
        }

        /////// ODOMETER  //////////////////
        ///
        static int preDist=0;
        preDist = preDist + angle;

        // char disBuff[10];
        // sprintf(daBuff,"%d\0",preDist);
        // QString disMeasurement = QString(daBuff);
        ui->odometer->display(preDist);


        // //////////////////////////////////////////
        // ///
        // // static QString gN;
        // if(strcmp(bufrr,"G-1")==0)
        // {
        //     gN = 'R';
        //     // ui->gearNum->setText('R');
        // }
        // if(strcmp(bufrr,"G0")==0)
        // {
        //     gN = 'N';

        //     // ui->gearNum->setText('N');
        // }
        // if(strcmp(bufrr,"G1")==0)
        // {
        //     gN = '1';

        //     // ui->gearNum->setText('1');
        // }
        // if(strcmp(bufrr,"G2")==0)
        // {
        //     gN = '2';

        //     // ui->gearNum->setText('2');
        // }
        // if(strcmp(bufrr,"G3")==0)
        // {
        //     gN = '3';

        //     // ui->gearNum->setText('3');
        // }
        // if(strcmp(bufrr,"G4")==0)
        // {
        //     gN = '4';

        //     // ui->gearNum->setText('4');
        // }
        // if(strcmp(bufrr,"G5")==0)
        // {
        //     gN = '5';

        //     // ui->gearNum->setText('5');
        // }
        // if(strcmp(bufrr,"G6")==0)
        // {
        //     gN = '6';

        //     // ui->gearNum->setText('6');
        // }

        // ui->gearNum->setText(gN);
    });
    left_Rot_timer->start();
}

void MainWindow::revRot()
{
    ////ROTATE ANIMATION STARTS
    ///

    // static float angle = 0;
    // static int F_flag =0, R_Flag = 0;

    // static int rFlag = 0;

    Rev_Rot_timer = new QTimer(this);

    // static QTimer *PStart_timer = new QTimer(this);


    Rev_Rot_timer->setInterval(pT);
    connect(Rev_Rot_timer, &QTimer::timeout, this, [this]{
        // ui->leftGView->rotate(rotationDirection * angle);
        // ui->rightGView->rotate(rotationDirection * angle);
            ui->leftGView->rotate(angle);
            ui->rightGView->rotate(angle);
        // PStart_timer->start();

        if(rFlag == 1)
        {
            if(angle >= 0)
            {
                // INDILIGHTINGS(INDI_ON);
                angle -= 0.1;

                ui->seatIndi->show();
                ui->oilindi->show();
                ui->hBrakeIndi->show();
                ui->warningIndi->show();
                ui->petrolindi->show();
                ui->rightIndi->show();
                ui->leftIndi->show();
            }
            else
            {
                ui->leftGView->resetTransform();
                ui->rightGView->resetTransform();
                // angle = 0;
                rFlag = 2;
                ui->seatIndi->hide();
                ui->oilindi->hide();
                ui->hBrakeIndi->hide();
                ui->warningIndi->hide();
                ui->petrolindi->hide();
                ui->rightIndi->hide();
                ui->leftIndi->hide();
                Rev_Rot_timer->stop();

                rotationDirection *= -1;
            }
        }

    });
    Rev_Rot_timer->start();
}

void MainWindow::rightRotation()
{

}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _sleep(1000);
    resourceInit();
    iconsInit();
        // if(rFlag==1)
        // {
        //     revRot();
        // }
    afterEffect();

    leftRotation();
    rightRotation();


    // ////ROTATE ANIMATION STARTS
    // ///

    // // static float angle = 0;
    // // static int F_flag =0, R_Flag = 0;

    // // static int rFlag = 0;

    // PStart_timer = new QTimer(this);

    // // static QTimer *PStart_timer = new QTimer(this);


    // PStart_timer->setInterval(pT);
    // connect(PStart_timer, &QTimer::timeout, this, [this]{
    //     // ui->leftGView->rotate(rotationDirection * angle);
    //     // ui->rightGView->rotate(rotationDirection * angle);
    //     ui->leftGView->rotate(angle);
    //     ui->rightGView->rotate(angle);
    //     // PStart_timer->start();

    //     // if(rFlag == 1)
    //     {
    //         if(angle < 7.2 && rFlag == 0)
    //         {
    //             // INDILIGHTINGS(INDI_ON);
    //             angle += 0.1;

    //             ui->seatIndi->show();
    //             ui->oilindi->show();
    //             ui->hBrakeIndi->show();
    //             ui->warningIndi->show();
    //             ui->petrolindi->show();
    //             ui->rightIndi->show();
    //             ui->leftIndi->show();
    //         }
    //         else
    //         {
    //             ui->leftGView->resetTransform();
    //             ui->rightGView->resetTransform();
    //             angle = 0;
    //             rFlag = 1;
    //             ui->seatIndi->hide();
    //             ui->oilindi->hide();
    //             ui->hBrakeIndi->hide();
    //             ui->warningIndi->hide();
    //             ui->petrolindi->hide();
    //             ui->rightIndi->hide();
    //             ui->leftIndi->hide();
    //             PStart_timer->stop();

    //             rotationDirection *= -1;
    //         }
    //     }

    // });
    // PStart_timer->start();

    // running_timer = new QTimer(this);

    // // static QTimer *PStart_timer = new QTimer(this);


    // running_timer->setInterval(rTimIntrval);
    // connect(running_timer, &QTimer::timeout, this, [this]{

    //     if(rFlag == 1)
    //         runTimCnt++;

    //     if(runTimCnt == 1)
    //     {

    //         // iFlag = 1;
    //         // indi++;
    //         indiFlag++;
    //         ui->seatIndi->show();
    //         ui->oilindi->show();
    //         ui->hBrakeIndi->show();
    //         ui->warningIndi->show();
    //         ui->petrolindi->show();
    //         ui->rightIndi->show();
    //         ui->leftIndi->show();
    //     }
    //     else
    //     {
    //         // iFlag = 0;

    //         ui->seatIndi->hide();
    //         ui->oilindi->hide();
    //         ui->hBrakeIndi->hide();
    //         ui->warningIndi->hide();
    //         ui->petrolindi->hide();
    //         ui->rightIndi->hide();
    //         ui->leftIndi->hide();
    //         runTimCnt = 0;

    //     }

    //     if(indiFlag > 6)
    //     {
    //         indiFlag = 0;
    //     }

    //     switch (indiFlag) {
    //     case 0:
    //         ui->seatIndi->hide();
    //         ui->oilindi->hide();
    //         ui->hBrakeIndi->hide();
    //         ui->warningIndi->hide();
    //         ui->petrolindi->hide();
    //         ui->rightIndi->show();
    //         ui->leftIndi->show();
    //         break;

    //     case 1:
    //         ui->petrolindi->show();
    //         ui->hBrakeIndi->hide();
    //         ui->oilindi->hide();
    //         ui->seatIndi->hide();
    //         ui->warningIndi->hide();
    //         ui->rightIndi->hide();
    //         ui->leftIndi->hide();
    //         break;

    //     case 2:
    //         ui->petrolindi->hide();
    //         ui->hBrakeIndi->show();
    //         ui->oilindi->hide();
    //         ui->seatIndi->hide();
    //         ui->warningIndi->hide();
    //         ui->rightIndi->show();
    //         ui->leftIndi->hide();
    //         break;

    //     case 3:
    //         ui->petrolindi->hide();
    //         ui->hBrakeIndi->hide();
    //         ui->oilindi->show();
    //         ui->seatIndi->hide();
    //         ui->warningIndi->hide();
    //         ui->rightIndi->hide();
    //         ui->leftIndi->hide();
    //         break;

    //     case 4:
    //         ui->petrolindi->hide();
    //         ui->hBrakeIndi->hide();
    //         ui->oilindi->hide();
    //         ui->seatIndi->show();
    //         ui->warningIndi->hide();
    //         ui->rightIndi->hide();
    //         ui->leftIndi->show();
    //         break;

    //     case 5:
    //         ui->petrolindi->hide();
    //         ui->hBrakeIndi->hide();
    //         ui->oilindi->hide();
    //         ui->seatIndi->hide();
    //         ui->warningIndi->show();
    //         ui->rightIndi->hide();
    //         ui->leftIndi->hide();
    //         break;

    //     default:
    //         indiFlag = 0;
    //         break;
    //     }



    // });
    // running_timer->start();


    // ////ROTATE ANIMATION STARTS
    // ///

    // // static float angle = 0;
    // // static int F_flag =0, R_Flag = 0;

    // // static int rFlag = 0;

    // left_Rot_timer = new QTimer(this);

    // // static QTimer *PStart_timer = new QTimer(this);


    // left_Rot_timer->setInterval(rot_tim_pT);
    // connect(left_Rot_timer, &QTimer::timeout, this, [this]{
    //     ui->leftGView->rotate(angle);
    //     // ui->rightGView->rotate(angle);
    //     // PStart_timer->start();

    //     if(angle < 7.2)
    //     {
    //         // INDILIGHTINGS(INDI_ON);
    //         angle += 0.1;

    //         ui->seatIndi->show();
    //         ui->oilindi->show();
    //         ui->hBrakeIndi->show();
    //         ui->warningIndi->show();
    //         ui->petrolindi->show();
    //         ui->rightIndi->show();
    //         ui->leftIndi->show();
    //     }
    //     else
    //     {
    //         ui->leftGView->resetTransform();
    //         ui->rightGView->resetTransform();
    //         angle = 0;
    //         // rFlag = 1;
    //         ui->seatIndi->hide();
    //         ui->oilindi->hide();
    //         ui->hBrakeIndi->hide();
    //         ui->warningIndi->hide();
    //         ui->petrolindi->hide();
    //         ui->rightIndi->hide();
    //         ui->leftIndi->hide();
    //         PStart_timer->stop();
    //     }
    // });
    // left_Rot_timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
