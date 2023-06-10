#include "transac.h"
#include "ui_transac.h"

transac::transac(QWidget *parent, QList<QString> ex) :
    QWidget(parent),
    ui(new Ui::transac), listModel(new QStringListModel)
{
    ui->setupUi(this);

    listModel->setStringList(ex);
    ui->transacView->setModel(listModel);
}

transac::~transac()
{
    delete ui;
}
