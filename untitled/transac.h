#ifndef TRANSAC_H
#define TRANSAC_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class transac;
}

class transac : public QWidget
{
    Q_OBJECT

public:
    explicit transac(QWidget *parent = nullptr, QList<QString> ex = {});
    ~transac();

private:
    Ui::transac *ui;
    QStringListModel *listModel;

};

#endif // TRANSAC_H
