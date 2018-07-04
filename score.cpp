#include "score.h"
#include "ui_score.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QTableWidgetItem>

static QStringList _headers = {"Mot", "Coupa restant"};

Score::Score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Score)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, 300);
    ui->tableWidget->setHorizontalHeaderLabels(_headers);

    QFile       file("score.csv");
    QTextStream fstream(&file);
    QString     line;
    int         i = 0;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;
    while (!fstream.atEnd()) {
        ui->tableWidget->setRowCount(i + 1);
        line = fstream.readLine();
        QStringList sp = line.split(';');
        QTableWidgetItem *tmp = new QTableWidgetItem(sp[0]);
        ui->tableWidget->setItem(i, 0, tmp);
        tmp = new QTableWidgetItem(sp[1]);
        ui->tableWidget->setItem(i, 1, tmp);
        ++i;
    }
}

Score::~Score()
{
    delete ui;
}
