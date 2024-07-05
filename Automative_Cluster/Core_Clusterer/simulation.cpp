#include "simulation.h"
#include "ui_simulation.h"
#include <QTimer>

static int count = 0;
static int count1 = 0;
Simulation::Simulation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Simulation)
{
    ui->setupUi(this);
    ui->PowerButton->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/PowerOff.png"));

    ui->Back_Center->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png"));
    ui->Back_Left->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png"));
    ui->Back_Right->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png"));
    ui->Front_Window->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png"));
    ui->Driver_Seat->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png"));
    //ui->Right_Door->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-door.png"));
    ui->High_Beam->setEnabled(false);
    ui->Right_Indicator->setEnabled(false);
    ui->Parking_Simulation->setEnabled(false);
    ui->Left_Indicator->setEnabled(false);
    ui->Speed_Button->setEnabled(false);
    ui->Fuel_Level->setEnabled(false);
    ui->Back_Center->setEnabled(false);
    ui->Back_Left->setEnabled(false);
    ui->Back_Right->setEnabled(false);
    ui->Front_Window->setEnabled(false);
    ui->Driver_Seat->setEnabled(false);
    ui->Right_Door->setEnabled(false);
    ui->Left_Door->setEnabled(false);
    ui->Front_Door->setEnabled(false);
    ui->Driver_Door->setEnabled(false);
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::on_Parking_Simulation_clicked()
{
    emit parksignal();

}


void Simulation::on_Left_Indicator_clicked()
{
    emit left_Indicator();
}


void Simulation::on_Right_Indicator_clicked()
{
    emit right_Indicator();

}

void Simulation::on_PowerButton_clicked()
{


        static int active = 1;
        if(active ==1){
        ui->PowerButton->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Desktop/puneeth/S2V_Automaation/QT_CLUSTER/Cluster/On.png"));
            ui->High_Beam->setEnabled(true);
            ui->Right_Indicator->setEnabled(true);
            ui->Parking_Simulation->setEnabled(true);
            ui->Left_Indicator->setEnabled(true);
            ui->Speed_Button->setEnabled(true);
            ui->Fuel_Level->setEnabled(true);
            ui->Back_Center->setEnabled(true);
            ui->Back_Left->setEnabled(true);
            ui->Back_Right->setEnabled(true);
            ui->Front_Window->setEnabled(true);
            ui->Driver_Seat->setEnabled(true);
            ui->Right_Door->setEnabled(true);
            ui->Left_Door->setEnabled(true);
            ui->Front_Door->setEnabled(true);
            ui->Driver_Door->setEnabled(true);
        emit power(true);
        active =0;
    }
    else
        {
    ui->PowerButton->setIcon(QIcon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/PowerOff.png"));
        ui->High_Beam->setEnabled(false);
        ui->Right_Indicator->setEnabled(false);
        ui->Parking_Simulation->setEnabled(false);
        ui->Left_Indicator->setEnabled(false);
        ui->Speed_Button->setEnabled(false);
        ui->Fuel_Level->setEnabled(false);
        ui->Back_Center->setEnabled(false);
        ui->Back_Left->setEnabled(false);
        ui->Back_Right->setEnabled(false);
        ui->Front_Window->setEnabled(false);
        ui->Driver_Seat->setEnabled(false);
        ui->Right_Door->setEnabled(false);
        ui->Left_Door->setEnabled(false);
        ui->Front_Door->setEnabled(false);
        ui->Driver_Door->setEnabled(false);
        emit power(false);
        active=1;
    }
}


void Simulation::on_High_Beam_clicked()
{
    emit high();
}



void Simulation::on_Speed_Button_sliderMoved(int position)
{
    emit speed(position);
}


void Simulation::on_Fuel_Level_sliderMoved(int position)
{
    emit fuel(position);
}


void Simulation::on_Front_Window_clicked()
{
  static int active=1;
        if(active==1)
        {
            QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-seat.png");
            ui->Front_Window->setIcon(icon);
            ui->Front_Window->show();
            count++;
            emit safetyBelt(count,2);
            active=2;
        }
        else if(active==2)
        {
            QIcon icon1("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png");
            ui->Front_Window->setIcon(icon1);
            ui->Front_Window->show();
            count--;
            emit safetyBelt(count,20);
            active = 1;
        }

}



void Simulation::on_Driver_Seat_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-seat.png");
        ui->Driver_Seat->setIcon(icon);
        ui->Driver_Seat->show();
        count++;
        emit safetyBelt(count,1);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon1("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png");
        ui->Driver_Seat->setIcon(icon1);
        ui->Driver_Seat->show();
        count--;
        emit safetyBelt(count,10);
        active = 1;
    }
}




void Simulation::on_Back_Left_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-seat.png");
        ui->Back_Left->setIcon(icon);
        ui->Back_Left->show();
        count++;
        emit safetyBelt(count,3);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon1("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png");
        ui->Back_Left->setIcon(icon1);
        ui->Back_Left->show();
        count--;
        emit safetyBelt(count,30);
        active = 1;
    }
}



void Simulation::on_Back_Center_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-seat.png");
        ui->Back_Center->setIcon(icon);
        ui->Back_Center->show();
        count++;
        emit safetyBelt(count,4);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon1("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png");
        ui->Back_Center->setIcon(icon1);
        ui->Back_Center->show();
        count--;
        emit safetyBelt(count,40);
        active = 1;
    }
}


void Simulation::on_Back_Right_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-seat.png");
        ui->Back_Right->setIcon(icon);
        ui->Back_Right->show();
        count++;
        emit safetyBelt(count,5);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon1("C:/Users/Nuthan Kumar HR/Documents/Clusterer/passenger.png");
        ui->Back_Right->setIcon(icon1);
        ui->Back_Right->show();
        count--;
        emit safetyBelt(count,50);
        active = 1;
    }
}


void Simulation::on_Right_Door_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-door.png");
        ui->Right_Door->setIcon(icon);
        ui->Right_Door->show();
        count1++;
        emit door(count1,1);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon(" ");
        ui->Right_Door->setIcon(icon);
        ui->Right_Door->show();
        count1--;
        emit door(count1,10);
        active=1;
    }
}


void Simulation::on_Left_Door_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-door1.png");
        ui->Left_Door->setIcon(icon);
        ui->Left_Door->show();
        count1++;
        emit door(count1,2);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon(" ");
        ui->Left_Door->setIcon(icon);
        ui->Left_Door->show();
        count1--;
        emit door(count1,20);
        active=1;
    }
}

void Simulation::on_Driver_Door_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-door.png");
        ui->Driver_Door->setIcon(icon);
        ui->Driver_Door->show();
        count1++;
        emit door(count1,3);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon(" ");
        ui->Driver_Door->setIcon(icon);
        ui->Driver_Door->show();
        count1--;
        emit door(count1,30);
        active=1;
    }
}



void Simulation::on_Front_Door_clicked()
{
    static int active=1;
    if(active==1)
    {
        QIcon icon("C:/Users/Nuthan Kumar HR/Documents/Clusterer/car-door1.png");
        ui->Front_Door->setIcon(icon);
        ui->Front_Door->show();
        count1++;
        emit door(count1,4);
        active=2;
    }
    else if(active==2)
    {
        QIcon icon(" ");
        ui->Front_Door->setIcon(icon);
        ui->Front_Door->show();
        count1--;
        emit door(count1,40);
        active=1;
    }
}


void Simulation::on_RPM_Meter_sliderMoved(int position)
{
    emit rpm(position);
}

