#ifndef SACTIONDIALOG_H
#define SACTIONDIALOG_H

#include <QDialog>

namespace Ui {
class sactiondialog;
}

class sactiondialog : public QDialog
{
    Q_OBJECT

public:
    explicit sactiondialog(QWidget *parent = nullptr);
    ~sactiondialog();

private:
    Ui::sactiondialog *ui;
};

#endif // SACTIONDIALOG_H
