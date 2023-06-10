#ifndef PRODLIST_H
#define PRODLIST_H

#include <QWidget>

namespace Ui {
class ProdList;
}

class ProdList : public QWidget
{
    Q_OBJECT

public:
    explicit ProdList(QWidget *parent = nullptr);
    ~ProdList();

private:
    Ui::ProdList *ui;
};

#endif // PRODLIST_H
