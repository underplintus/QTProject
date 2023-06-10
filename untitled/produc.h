#ifndef PRODUC_H
#define PRODUC_H

#include <QWidget>
#include <QStringListModel>


namespace Ui {
class produc;
}

class produc : public QWidget
{
    Q_OBJECT

public:
    explicit produc(QWidget *parent = nullptr, QList<QString> exam = {});
    ~produc();

private slots:


private:
    Ui::produc *ui;
    QStringListModel *lstModel;
};

#endif // PRODUC_H
