#ifndef REVENUE_H
#define REVENUE_H

#include <QWidget>

namespace Ui {
class Revenue;
}

class Revenue : public QWidget
{
    Q_OBJECT

public:
    explicit Revenue(QWidget *parent = nullptr);
    ~Revenue();

private:
    Ui::Revenue *ui;
};

#endif // REVENUE_H
