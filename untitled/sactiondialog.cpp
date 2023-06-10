#include "sactiondialog.h"
#include "ui_sactiondialog.h"

sactiondialog::sactiondialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sactiondialog)
{
    ui->setupUi(this);
    proxyModel->setSourceModel(model);
    ui->sactionView->setModel(proxyModel);
    ui->sactionView->setSortingEnabled(true);
}

sactiondialog::~sactiondialog()
{
    delete ui;
}
