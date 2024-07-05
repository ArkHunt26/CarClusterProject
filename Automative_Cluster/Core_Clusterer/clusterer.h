#ifndef CLUSTERER_H
#define CLUSTERER_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QString>
#include<QDebug>
#include "simulation.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Clusterer;
}
QT_END_NAMESPACE

class Clusterer : public QMainWindow
{
    Q_OBJECT

public:
    Clusterer(QWidget *parent = nullptr);
    ~Clusterer();
    QGraphicsScene *scene;
    QGraphicsScene *scene1;

public slots:
    void onParkSignal();
    void onLeftIndicator();
    void onRightIndicator();
    void onSafetyBelt(const int &val,const int &identify);
    void onDoor(const int &val1,const int &identityy);
    void onPower(const bool &state);
    void onHigh();
    void onSpeed(int position);
    void onFuel(int position);
    void onRpm(int position);
private slots:

    //void on_Speed_sliderMoved(int position);



    //void on_PushButton_clicked();


    //void on_Beam_Button_clicked();

    //void on_Fuel_Guage_sliderMoved(int position);

private:
    Ui::Clusterer *ui;
};
#endif // CLUSTERER_H
