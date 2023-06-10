#include "prodlist.h"
#include "ui_prodlist.h"

ProdList::ProdList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProdList)
{
    ui->setupUi(this);
}

ProdList::~ProdList()
{
    delete ui;
}
