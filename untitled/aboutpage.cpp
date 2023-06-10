#include "aboutpage.h"
#include "ui_aboutpage.h"

AboutPage::AboutPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutPage)
{
    ui->setupUi(this);

    icon = new Icon(ui->widgetIcon);

    ui->verticalLayout->addWidget(icon);


    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(icon->sizePolicy().hasHeightForWidth());
    icon->setSizePolicy(sizePolicy);
}

AboutPage::~AboutPage()
{
    delete ui;
}
