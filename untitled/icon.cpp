#include "icon.h"


Icon::Icon(QWidget *parent)
    : QWidget{parent}
{

}


void Icon::paintEvent(QPaintEvent*)
{
    int values[10] = {10, 20, 5, 12, 25, 20, 14, 7 ,19, 13};
    const int vertStep = 10;
    const int horStep = 37;
    const int sX = 140;
    const int sY = 30 * vertStep + 70;

    QPainter painter(this);
    painter.setBrush(Qt::GlobalColor::white);
    painter.drawRect(QRect(0, 0, this->width() - 1, this->height() - 1));

    // horiz and vert axis
    painter.setPen(QColor(30, 30, 30));
    painter.drawLine(sX + 14, sY, sX + 14, sY - (30 * vertStep + 50));
    painter.drawLine(sX + 14, sY, sX + horStep * 10, sY);

    //extra lines
    painter.setPen(QColor(70, 100, 220));
    painter.drawLine(sX + 14, sY - 10 * vertStep, sX + horStep * 10, sY - 10 * vertStep);
    painter.drawLine(sX + 14, sY - 20 * vertStep, sX + horStep * 10, sY - 20 * vertStep);
    painter.drawLine(sX + 14, sY - 30 * vertStep, sX + horStep * 10, sY - 30 * vertStep);

    //counting coordinates
    QPoint valuesPoints[10];
    for (int i = 0; i < 10; i++)
    {
        valuesPoints[i] = QPoint(sX + i * horStep + 15, sY - values[i] * vertStep);
    }


    QPoint poligonPoints[13];
    for (int i = 0; i < 10; i++)
    {
        poligonPoints[i] = valuesPoints[i];
    }

    poligonPoints[10] = QPoint(valuesPoints[9].x(), sY);
    poligonPoints[11] = QPoint(sX + 14, sY);
    poligonPoints[12] = QPoint(sX + 14, valuesPoints[0].y());

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(120, 150, 230));
    painter.drawPolygon(poligonPoints, 13);

    //lines between points
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(QColor(50, 50, 200));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawPolyline(valuesPoints, 10);


    //drawing ellipses
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(50, 50, 200));
    for (int i = 0; i < 10; i++)
    {
        painter.drawEllipse(valuesPoints[i], 5, 5);
    }

}
