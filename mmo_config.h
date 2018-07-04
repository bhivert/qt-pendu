#ifndef MMO_CONFIG_H
#define MMO_CONFIG_H

#include <QDialog>

namespace Ui {
class Mmo_config;
}

class Mmo_config : public QDialog
{
    Q_OBJECT

public:
    explicit Mmo_config(QWidget *parent = 0);
    ~Mmo_config();

private:
    Ui::Mmo_config *ui;
};

#endif // MMO_CONFIG_H
