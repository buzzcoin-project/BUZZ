#ifndef DISCLAIMER_H
#define DISCLAIMER_H

#include <QDialog>

namespace Ui {
class disclaimer;
}
class WalletModel;

class disclaimer : public QDialog
{
    Q_OBJECT

public:
    explicit disclaimer(QWidget *parent = 0);
    ~disclaimer();

    void setModel(WalletModel *model);
private slots:
    void accept();
    void reject();
    void stateChanged(int s);
    void performAction();

private:
    Ui::disclaimer *ui;
    WalletModel *model;
};

#endif // DISCLAIMER_H


