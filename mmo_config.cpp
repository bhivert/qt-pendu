#include "mmo_config.h"
#include "ui_mmo_config.h"

#include <QtNetwork/QtNetwork>
#include <QRegExp>

Mmo_config::Mmo_config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mmo_config)
{
    ui->setupUi(this);

    QRegExp ipv4("^[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}$");
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (auto it = ipAddressesList.begin(); it != ipAddressesList.end(); ++it) {
        if (ipv4.exactMatch(it->toString()))
            ui->ipList->addItem(it->toString());
    }
}

Mmo_config::~Mmo_config()
{
    delete ui;
}
