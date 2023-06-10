#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
}

QList<QString> AddRowDialog::getRowData()
{
    QList<QString> newList(8, "No data");
    newList[0] = ui->line1->text();
    newList[3] = ui->line2->text();
    newList[6] = ui->line3->text();
    newList[7] = ui->line4->text();
    return newList;
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}
