#include "clusterer.h"
#include "ui_clusterer.h"
#include <QPushButton>
#include<QDebug>
#include<QTimer>
#include<QPixmap>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QTransform>
#include<QGraphicsScene>

Clusterer::Clusterer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clusterer)
{
    ui->setupUi(this);


    scene=new QGraphicsScene(this);
    //scene->addPixmap(QPixmap(QCoreApplication::applicationDirPath() + "C:/Users/Nuthan Kumar HR/Documents/Clusterer/Needle_C.jpeg"));
    scene->addPixmap(QPixmap("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Needle2.png"));
    ui->Needle->setScene(scene);

    scene1=new QGraphicsScene(this);
    //scene->addPixmap(QPixmap(QCoreApplication::applicationDirPath() + "C:/Users/Nuthan Kumar HR/Documents/Clusterer/Needle_C.jpeg"));
    scene1->addPixmap(QPixmap("C:/Users/Nuthan Kumar HR/Documents/Clusterer/RPM.png"));
    ui->Needle_RPM->setScene(scene1);

    QPixmap pix("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Speedometer.jpeg");
    ui->Accelerator->setPixmap((pix.scaled(391,291,Qt::KeepAspectRatio)));

    QPixmap pix0("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Seat_View1.png");
    ui->Car_View->setPixmap((pix0.scaled(81,111,Qt::KeepAspectRatio)));

    QPixmap pix1("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Group 3.png");
    ui->RPM->setPixmap((pix1.scaled(391,291,Qt::KeepAspectRatio)));

    QPixmap pix3("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Line.png");
    ui->Design->setPixmap((pix3.scaled(621,20,Qt::KeepAspectRatio)));

    QPixmap pix4("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Line.png");
    ui->Design_Down->setPixmap((pix3.scaled(621,20,Qt::KeepAspectRatio)));

    // QPixmap pix2("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Carr.png");
    // ui->Car->setPixmap((pix2.scaled(300,470,Qt::KeepAspectRatio)));


    //ui->onPower->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/PowerOn.png"));
    ui->PushLeft->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Left.png"));
    ui->PushRight->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Right.png"));
    ui->PushParking->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Downloads/Parking.png"));
    ui->Engine->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Downloads/Engine.png"));
    ui->Seat_1->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png"));
    ui->Seat_2->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png"));
    ui->Seat_3->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png"));
    ui->Seat_4->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png"));
    ui->Seat_5->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png"));
    ui->Left_Door_Signal->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png"));
    ui->Front_Left_Door_Signal->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png"));
    ui->Right_Door_Signal->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png"));
    ui->Front_Right_Door_Signal->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png"));
    ui->PushLeft->hide();
    ui->PushParking->hide();
    ui->PushRight->hide();
    ui->PushLeft->hide();
    ui->PushRight->hide();
    ui->PushParking->hide();
    ui->Engine->hide();
    ui->Fuel->hide();
    ui->Left_Door_Signal->hide();
    ui->Right_Door_Signal->hide();
    ui->Front_Left_Door_Signal->hide();
    ui->Front_Right_Door_Signal->hide();
    // ui->Left_Indicator->hide();
    // ui->Right_Button->hide();
    // ui->ParkingButton->hide();
    ui->Beam_Button->hide();
    ui->lcdNumber->setEnabled(false);
    ui->lcdNumber_2->setEnabled(false);
    // ui->horizontalSlider->setEnabled(false);
    // ui->Fuel_Guage_LCD->setEnabled(false);
    // ui->Fuel_Guage->setEnabled(false);
}

Clusterer::~Clusterer()
{
    delete ui;
}

void Clusterer::onSpeed(int position)
{
    ui->lcdNumber->display(position);
    if(position <=20)
        ui->lcdNumber_2->display("1");
    else if(position <=40)
        ui->lcdNumber_2->display("2");
    else if(position <=60)
        ui->lcdNumber_2->display("3");
    else if(position <=80)
        ui->lcdNumber_2->display("4");
    else if(position <=280)
        ui->lcdNumber_2->display("5");

    QGraphicsScene* scene3= new QGraphicsScene(this);
    scene3->addPixmap(QPixmap("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Needle2.png"));

    ui->Needle->setScene(scene3);
    ui->Needle->rotate(45);

}

void Clusterer::onPower(const bool &state)
{
    if(state==true)
    {
    ui->Engine->show();
    ui->Fuel->show();
    // ui->LeftButton->show();
    // ui->Right_Button->show();
    // ui->ParkingButton->show();
    ui->Beam_Button->show();
    ui->lcdNumber->setEnabled(true);
    ui->lcdNumber_2->setEnabled(true);
    // ui->horizontalSlider->setEnabled(true);
    // ui->Fuel_Guage_LCD->setEnabled(true);
    // ui->Fuel_Guage->setEnabled(true);
    ui->Fuel->setEnabled(true);
    }

    else{
        ui->Engine->hide();
        ui->Fuel->setEnabled(false);
        ui->Beam_Button->hide();
        ui->lcdNumber->setEnabled(false);
        ui->lcdNumber_2->setEnabled(false);
        ui->Fuel_Guage_LCD->setEnabled(false);
        ui->Fuel->setEnabled(false);
        ui->PushLeft->hide();
        ui->PushRight->hide();
        ui->PushParking->hide();
        ui->Safety_Belt->hide();
        ui->Car_Door->hide();
    }

}


void Clusterer::onHigh()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Beam.png");
        ui->Beam_Button->setIcon(icon);
        ui->Beam_Button->show();
        active=2;
    }
    else if(active==2)
    {
        QIcon icon1("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dip.png");
        ui->Beam_Button->setIcon(icon1);
        ui->Beam_Button->show();
        active = 3;
    }
    else
    {
        ui->Beam_Button->hide();
        active = 1;
    }
}


void Clusterer::onFuel(int position)
{
    static bool belowThreshold=false;
    static QTimer *timer=nullptr;
    //static int state=0;
    ui->Fuel_Guage_LCD->display(position);

    if(position<=25)
    {

        if(!belowThreshold)
        {
        belowThreshold = true;

        if(!timer)
            {

                timer = new QTimer(this);
                connect(timer,&QTimer::timeout,this,[this]{
                    if(ui->Fuel->isVisible())
                        ui->Fuel->hide();
                    else
                        ui->Fuel->show();

                });
                timer->start(500);
            }
        }
        ui->Fuel->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Red11.png"));

    }



    else if(position<=60)
    {
        if(belowThreshold)
        {
            belowThreshold=false;
            if(timer)
            {
                timer->stop();
                delete timer;
                timer=nullptr;
            }
            ui->Fuel->show();
        }
        ui->Fuel->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/fuel.png"));
    }
    else
    {
        if(belowThreshold)
        {
            belowThreshold=false;
            if(timer)
            {
                timer->stop();
                delete timer;
                timer=nullptr;

            }
            ui->Fuel->show();
        }
        ui->Fuel->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Green11.png"));
    }
}


void Clusterer::onParkSignal()
{
    //ui->PushParking->show();
    static bool state = true;
    static QTimer *timer=nullptr;
    if(state)
    {
        ui->PushParking->hide();
        if(!timer)
        {
            timer = new QTimer(this);
            connect(timer,&QTimer::timeout,this,[this]{
                if(ui->PushParking->isVisible())
                    ui->PushParking->hide();
                else
                    ui->PushParking->show();

            });
            timer->start(500);
        }

        state=false;
    }
    else{
        ui->PushParking->hide();
        if(timer)
        {
            timer->stop();
            delete timer;
            timer=nullptr;
        }
        state=true;
    }

}
void Clusterer::onLeftIndicator()
{
    static bool state = true;
    static QTimer *timer=nullptr;

    if(state)
    {
        ui->PushLeft->hide();

        if(!timer)
        {
            timer = new QTimer(this);
            connect(timer,&QTimer::timeout,this,[this]{
                if(ui->PushLeft->isVisible())
                    ui->PushLeft->hide();
                else
                    ui->PushLeft->show();
            });
            timer->start(500);

        }
        state=false;
    }
    else
    {
        ui->PushLeft->hide();
        if(timer)
        {
            timer->stop();
            delete timer;
            timer=nullptr;
        }
        state=true;
    }
}

void Clusterer::onRightIndicator()
{
    static bool state = true;
    static QTimer *timer=nullptr;

    if(state)
    {
        ui->PushRight->hide();
        if(!timer)
        {
            timer = new QTimer(this);
            connect(timer,&QTimer::timeout,this,[this]{
                if(ui->PushRight->isVisible())
                    ui->PushRight->hide();
                else
                    ui->PushRight->show();
            });
            timer->start(500);

        }
        state=false;
    }
    else
    {

        ui->PushRight->hide();
        if(timer)
        {
            timer->stop();
            delete timer;
            timer=nullptr;

            // state=!state;


        }
        state=true;
    }
}

void Clusterer::onSafetyBelt(const int &val,const int &identify)
{
    if(val != 0)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt1.png");
        ui->Safety_Belt->setIcon(icon);
        ui->Safety_Belt->show();
        int seat = identify;
        switch(seat)
        {
        case 1:{

            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/circle.png");
            ui->Seat_1->setIcon(icon);
            ui->Seat_1->show();
            break;
        }
        case 10:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png");
            ui->Seat_1->setIcon(icon);
            ui->Seat_1->show();
            break;
        }
        case 2:{

            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/circle.png");
            ui->Seat_2->setIcon(icon);
            ui->Seat_2->show();
            break;
        }
        case 20:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png");
            ui->Seat_2->setIcon(icon);
            ui->Seat_2->show();
            break;
        }
        case 3:{

            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/circle.png");
            ui->Seat_3->setIcon(icon);
            ui->Seat_3->show();
            break;
        }
        case 30:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png");
            ui->Seat_3->setIcon(icon);
            ui->Seat_3->show();
            break;
        }
        case 4:{

            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/circle.png");
            ui->Seat_4->setIcon(icon);
            ui->Seat_4->show();
            break;
        }
        case 40:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png");
            ui->Seat_4->setIcon(icon);
            ui->Seat_4->show();
            break;
        }
        case 5:{

            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/circle.png");
            ui->Seat_5->setIcon(icon);
            ui->Seat_5->show();
            break;
        }
        case 50:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png");
            ui->Seat_5->setIcon(icon);
            ui->Seat_5->show();
            break;
        }
        }
    }
    else
    {
        ui->Safety_Belt->hide();
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/SeatBelt_1.png");
        ui->Seat_1->setIcon(icon);
        ui->Seat_2->setIcon(icon);
        ui->Seat_3->setIcon(icon);
        ui->Seat_4->setIcon(icon);
        ui->Seat_5->setIcon(icon);

    }


}

void Clusterer::onDoor(const int &val1,const int &identityy)
{
    if(val1 !=0)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/DoorWarning.png");
        ui->Car_Door->setIcon(icon);
        ui->Car_Door->show();
        int doors;
        doors=identityy;

        switch(doors)
        {
        case 1:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png");
            ui->Left_Door_Signal->setIcon((icon));
            ui->Left_Door_Signal->show();
            break;
        }

        case 10:
        {
            QIcon icon(" ");
            ui->Left_Door_Signal->setIcon((icon));
            ui->Left_Door_Signal->show();
            break;
        }
        case 2:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png");
            ui->Right_Door_Signal->setIcon((icon));
            ui->Right_Door_Signal->show();
            break;
        }

        case 20:
        {
            QIcon icon(" ");
            ui->Right_Door_Signal->setIcon((icon));
            ui->Right_Door_Signal->show();
            break;
        }
        case 3:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png");
            ui->Front_Left_Door_Signal->setIcon((icon));
            ui->Front_Left_Door_Signal->show();
            break;
        }

        case 30:
        {
            QIcon icon(" ");
            ui->Front_Left_Door_Signal->setIcon((icon));
            ui->Front_Left_Door_Signal->show();
            break;
        }
        case 4:
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/Dot.png");
            ui->Front_Right_Door_Signal->setIcon((icon));
            ui->Front_Right_Door_Signal->show();
            break;
        }

        case 40:
        {
            QIcon icon(" ");
            ui->Front_Right_Door_Signal->setIcon((icon));
            ui->Front_Right_Door_Signal->show();
            break;
        }
        }

    }
    else
    {
        ui->Car_Door->hide();
        QIcon icon(" ");
        ui->Left_Door_Signal->setIcon(icon);
        ui->Right_Door_Signal->setIcon(icon);
        ui->Front_Left_Door_Signal->setIcon(icon);
        ui->Front_Right_Door_Signal->setIcon(icon);
    }
}

void Clusterer::onRpm(int position)
{

    QGraphicsScene* scene5= new QGraphicsScene(this);
    scene5->addPixmap(QPixmap("C:/Users/Nuthan Kumar HR/Documents/Clusterer/RPM.png"));

    ui->Needle_RPM->setScene(scene5);
    ui->Needle_RPM->rotate(position);
}






