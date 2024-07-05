#include "clusterer.h"
#include <QApplication>
#include<QPushButton>
#include<QTimer>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clusterer w;
    Simulation s;
    QObject::connect(&s, &Simulation::parksignal,&w,&Clusterer::onParkSignal);
    QObject::connect(&s,&Simulation::left_Indicator,&w,&Clusterer::onLeftIndicator);
    QObject::connect(&s,&Simulation::right_Indicator,&w,&Clusterer::onRightIndicator);
    QObject::connect(&s,&Simulation::safetyBelt,&w,&Clusterer::onSafetyBelt);
    QObject::connect(&s,&Simulation::door,&w,&Clusterer::onDoor);
    QObject::connect(&s,&Simulation::power,&w,&Clusterer::onPower);
    QObject::connect(&s,&Simulation::high,&w,&Clusterer::onHigh);
    QObject::connect(&s,&Simulation::speed,&w,&Clusterer::onSpeed);
    QObject::connect(&s,&Simulation::fuel,&w,&Clusterer::onFuel);
    QObject::connect(&s,&Simulation::rpm,&w,&Clusterer::onRpm);
    w.show();
   s.show();
    return a.exec();
}
