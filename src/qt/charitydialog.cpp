#include "charitydialog.h"
#include "ui_charitydialog.h"

#include "clientmodel.h"
#include "notificator.h"
#include "version.h"

#include "wallet.h"
#include "walletdb.h"
#include "main.h"
#include "init.h"

charityDialog::charityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charityDialog)
{
    ui->setupUi(this);
}

charityDialog::~charityDialog()
{
    delete ui;
}

void charityDialog::setModel(ClientModel *model)
{

}

void charityDialog::on_buttonBox_accepted()
{
    CBitcoinAddress address = ui->charityAddressEdit->text().toStdString();
    Notificator *notificator;
    notificator = new Notificator();

    if (!address.IsValid())
    {
        notificator->notify(Notificator::Warning, tr("Invalid!"), tr("Ensure you are using a proper BUZZ address."));
    }

    QString str = ui->charityPercentEdit->text();
    bool fIntConversion;
    unsigned int nCharityPercent = str.toInt(&fIntConversion, 10);

    if (nCharityPercent <= 0)
    {
        notificator->notify(Notificator::Warning, tr("Invalid!"), tr("expected valid percentage, please try again."));
    }

    if (pwalletMain->IsLocked())
    {
        notificator->notify(Notificator::Warning, tr("Error!"), tr("Please unlock your wallet first."));
    }

    if (nCharityPercent <= 0)
    {
        pwalletMain->fStakeForCharity = false;
        pwalletMain->StakeForCharityAddress = "";
        pwalletMain->nStakeForCharityPercent = 0;
        notificator->notify(Notificator::Information, tr("Success!"), tr("Stake for Charity Disabled"));
        close();
    } else {
        pwalletMain->StakeForCharityAddress = address;
        pwalletMain->nStakeForCharityPercent = nCharityPercent;
        pwalletMain->fStakeForCharity = true;
    }

    CWalletDB walletdb(pwalletMain->strWalletFile);

    LOCK(pwalletMain->cs_wallet);
    {

        if (pwalletMain->fFileBacked)
        {
            walletdb.WriteStakeForCharityEnabled(nCharityPercent <= 0 ? false : true);
            walletdb.WriteStakeForCharityPercentage(nCharityPercent);
            walletdb.WriteStakeForCharityAddress(address.ToString());
            notificator->notify(Notificator::Information, tr("Success!"), tr("Stake for Charity settings saved to wallet.dat!"));
        } else {  
            notificator->notify(Notificator::Warning, tr("Failure!"), tr("Stake for Charity settings NOT saved to wallet.dat!"));
        }
    }
    close();
}

void charityDialog::on_buttonBox_rejected()
{
    close();
}
