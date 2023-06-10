#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
//    _logo = new CustomWidget(ui->Widget);
}

about::~about()
{
    delete ui;
}
