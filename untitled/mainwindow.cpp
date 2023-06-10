#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new TableModel), proxyModel(new ProxyModel)
{
    ui->setupUi(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);


    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::createMenus()
{
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);

}
void MainWindow::createActions()
{
    aboutAction = new QAction(tr("&Info"),this);

    connect(aboutAction,&QAction::triggered,this,&MainWindow::on_about);
}



void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
//    QList<QString> targetLine = (*proxyModel)[index.row()];

    QModelIndex index0 = proxyModel->index(index.row(), 0);
    QVariant qwert0 = proxyModel->data(index0);

    QModelIndex index1 = proxyModel->index(index.row(), 1);
    QVariant qwert1 = proxyModel->data(index1);

    QModelIndex index2 = proxyModel->index(index.row(), 2);
    QVariant qwert2 = proxyModel->data(index2);

    QModelIndex index3 = proxyModel->index(index.row(), 3);
    QVariant qwert3 = proxyModel->data(index3);

    QModelIndex index4 = proxyModel->index(index.row(), 4);
    QVariant qwert4 = proxyModel->data(index4);

    QModelIndex index5 = proxyModel->index(index.row(), 5);
    QVariant qwert5 = proxyModel->data(index5);

    QModelIndex index6 = proxyModel->index(index.row(), 6);
    QVariant qwert6 = proxyModel->data(index6);

    QModelIndex index7 = proxyModel->index(index.row(), 7);
    QVariant qwert7 = proxyModel->data(index7);


    ui->oneLine->setText(qwert0.toString());
    ui->stockLine->setText(qwert1.toString());
    ui->descriptionLine->setText(qwert2.toString());
    ui->twoLine->setText(qwert3.toString());
    ui->dateLine->setText(qwert4.toString());
    ui->priceLine->setText(qwert5.toString());
    ui->threeLine->setText(qwert6.toString());
    ui->countryLine->setText(qwert7.toString());
}


void MainWindow::on_addRow_clicked()
{
//    model->addRow(QList<QString>());
    AddRowDialog dialog;
    if (dialog.exec())
    {
        model->addRow(dialog.getRowData());
    }
    if (dialog.close()){}
}


void MainWindow::on_deleteRow_2_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    qDebug() << select->selectedIndexes();
    if (select->hasSelection())
        model->deleteRow(proxyModel->mapToSource(select->selectedIndexes()[0]).row());
//        model->deleteRow(select->selectedIndexes()[0].row());
}



void MainWindow::on_pushButton_clicked()     //search button
{
    QString needToSearch = ui->searchLineEdit->text();
    proxyModel->setCustomerID(needToSearch);
}


void MainWindow::on_resetButton_clicked()
{
   proxyModel->setCustomerID("");
}


void MainWindow::on_transactionButton_clicked()
{
    transac* tran = new transac(nullptr, model->tranList());
    tran->setAttribute(Qt::WA_DeleteOnClose);
    tran->show();

}


void MainWindow::on_prodListButton_clicked()
{
    produc* prod = new produc(nullptr, model->producView());
    prod->setAttribute(Qt::WA_DeleteOnClose);
    prod->show();
}

void MainWindow::on_about()
{
    AboutPage* widget = new AboutPage;
    widget->show();

}


