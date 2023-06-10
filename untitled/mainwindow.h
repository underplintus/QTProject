#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include "proxymodel.h"
#include "transac.h"
#include "produc.h"
#include "aboutpage.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_about();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_addRow_clicked();

    void on_deleteRow_2_clicked();

    void on_pushButton_clicked();   //search button

    void on_resetButton_clicked();

    void on_transactionButton_clicked();

    void on_prodListButton_clicked();



private:
    QMenu *helpMenu;
    QAction *aboutAction;

    void createMenus();
    void createActions();


private:

    Ui::MainWindow *ui;
    TableModel *model;
    ProxyModel *proxyModel;

};
#endif // MAINWINDOW_H
