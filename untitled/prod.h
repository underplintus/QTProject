#ifndef PROD_H
#define PROD_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class prod;
}

class prod : public QWidget
{
    Q_OBJECT

public:
    explicit prod(QWidget *parent = nullptr, QList<QString> exax = {});
    ~prod();

private:
    Ui::prod *ui;
    QStringListModel *lstModel;
};

#endif // PROD_H
