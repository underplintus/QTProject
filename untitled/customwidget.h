#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QPainter>

class customwidget : public QWidget
{
    Q_OBJECT
public:
    explicit customwidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // CUSTOMWIDGET_H
