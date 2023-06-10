#include "produc.h"
#include "ui_produc.h"

produc::produc(QWidget *parent, QList<QString> exam) :
    QWidget(parent),
    ui(new Ui::produc), lstModel(new QStringListModel)
{
    ui->setupUi(this);

    lstModel->setStringList(exam);
    ui->producView->setModel(lstModel);
}

produc::~produc()
{
    delete ui;
}



