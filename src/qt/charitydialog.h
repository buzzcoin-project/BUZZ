#ifndef CHARITYDIALOG_H
#define CHARITYDIALOG_H

#include <QDialog>

namespace Ui {
class charityDialog;
}
class ClientModel;

class charityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit charityDialog(QWidget *parent = 0);
    ~charityDialog();

    void setModel(ClientModel *model);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::charityDialog *ui;
};

#endif // CHARITYDIALOG_H
