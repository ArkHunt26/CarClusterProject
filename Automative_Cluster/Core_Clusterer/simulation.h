#ifndef SIMULATION_H
#define SIMULATION_H

#include <QDialog>
#include "clusterer.h"

namespace Ui {
class Simulation;
}

class Simulation : public QDialog
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = nullptr);
    ~Simulation();

signals:
    void parksignal();
    void left_Indicator();
    void right_Indicator();
    void safetyBelt(const int &val,const int &identify);
    void door(const int &val1,const int &identityy);
    void power(const bool &state);
    void high();
    void speed(int position);
    void fuel(int position);
    void rpm(int position);

private slots:
    void on_Parking_Simulation_clicked();

    void on_Left_Indicator_clicked();

    void on_Right_Indicator_clicked();

    //void on_Door_status_clicked();

    void on_PowerButton_clicked();

    void on_High_Beam_clicked();

    void on_Speed_Button_sliderMoved(int position);

    void on_Fuel_Level_sliderMoved(int position);

    void on_Front_Window_clicked();

    void on_Driver_Seat_clicked();

    void on_Back_Left_clicked();

    void on_Back_Center_clicked();

    void on_Back_Right_clicked();

    //void on_Right_Door_clicked();

    void on_Right_Door_clicked();

    void on_Left_Door_clicked();

    void on_Driver_Door_clicked();

    void on_Front_Door_clicked();

    void on_RPM_Meter_sliderMoved(int position);

private:
    Ui::Simulation *ui;
};

#endif // SIMULATION_H
