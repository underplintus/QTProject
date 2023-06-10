#include "transaction.h"
#include "ui_transaction.h"

Transaction::Transaction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transaction)
{
    ui->setupUi(this);
}

Transaction::~Transaction()
{
    delete ui;
}
