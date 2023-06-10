#include "revenue.h"
#include "ui_revenue.h"

Revenue::Revenue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Revenue)
{
    ui->setupUi(this);
}

Revenue::~Revenue()
{
    delete ui;
}
