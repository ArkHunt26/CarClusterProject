#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QtSvg/QSvgGenerator>
#include <QThread>
#include <string>
#include <QString>
#include <iostream>
#include <string>
#include <QColor>
#include <QColorDialog>
#include <QStyle>
#include <QGraphicsScene>
#include <QDebug>

#include <QtSvg/QSvgRenderer>

#include <QtGui/QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtGui/QPixmap>

// #include <QLabel>
// // #include <QSvgRenderer>
// #include <QPixmap>
// #include <QPainter>

// #include <QSvgWidget>
// #include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resourceInit();
    void iconsInit();
    void afterEffect();


    void IndiEffects();

    void leftRotation();

    void revRot();

    void rightRotation();


private:
    Ui::MainWindow *ui;

    QGraphicsScene *Scene1;
    QGraphicsScene *Scene2;
};
#endif // MAINWINDOW_H
