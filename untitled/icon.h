#ifndef ICON_H
#define ICON_H

#include <QWidget>
#include <QPainter>

class Icon : public QWidget
{
    Q_OBJECT
public:
    explicit Icon(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

};

#endif // ICON_H
