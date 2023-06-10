#include "prod.h"
#include "ui_prod.h"

prod::prod(QWidget *parent, QList<QString> exax) :
    QWidget(parent),
    ui(new Ui::prod), lstModel(new QStringListModel)
{
    ui->setupUi(this);
    lstModel->setStringList(exax);
    ui->prodView->setModel(lstModel);
}

prod::~prod()
{
    delete ui;
}
