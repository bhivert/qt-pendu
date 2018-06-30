#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _life(10)
{
    ui->setupUi(this);

    srand(time(NULL));

    QFile       file(":/dics/fr.txt");
    QTextStream fstream(&file);
    QString     line;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;
    while (!fstream.atEnd()) {
        line = fstream.readLine();
        this->_dic.push_back(line);
    }
    this->on_action_New_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void    MainWindow::_setLife() {
    char    buff[BUFSIZ];

    snprintf(buff, BUFSIZ, "%zu", this->_life);
    ui->life->setText(buff);
    snprintf(buff, BUFSIZ, ":/imgs/%zu.png", 10 - this->_life);
    ui->image->setPixmap(QPixmap(buff));
}

void    MainWindow::on_action_New_triggered()
{
    size_t  i = rand() % this->_dic.size();
    this->_word = this->_dic[i];
    this->_life = 10;
    this->_setLife();
    this->_secret = "";
    for (int j = 0; this->_word[j] != '\0'; ++j) {
        this->_secret += (this->_word[j] != '-') ? '*' : '-';
    }
    ui->word->setText(_secret);
}

void    MainWindow::_check_letter(const QString letter) {
    bool        found = false;

    for (int i = 0; i != letter.size(); ++i){
        for (int j = 0; (j = this->_word.indexOf(letter[i], j)) != -1; ++j) {
            this->_secret[j] = this->_word[j];
            found = true;
        }
    }
    if (found) {
        ui->word->setText(this->_secret);
        if (this->_secret == this->_word) {
            QMessageBox gamewone(QMessageBox::Question, "Game Wone !", "Play again ?", QMessageBox::Yes | QMessageBox::No);
            if (gamewone.exec() == QMessageBox::Yes)
                this->on_action_New_triggered();
            else
                this->close();
        }
    } else {
        --this->_life;
        this->_setLife();
        if (!this->_life) {
            QMessageBox gameover(QMessageBox::Question, "Game Over !", \
                "The word was :'" + this->_word + "'\n" + "Do you want retry ?", \
                QMessageBox::Yes | QMessageBox::No);
            if (gameover.exec() == QMessageBox::Yes)
                this->on_action_New_triggered();
            else
                this->close();
        }
    }
}

void    MainWindow::on_A_released() {this->_check_letter("AaÀàÂâÆæ");}
void    MainWindow::on_B_released() {this->_check_letter("Bb");}
void    MainWindow::on_C_released() {this->_check_letter("CcÇç");}
void    MainWindow::on_D_released() {this->_check_letter("Dd");}
void    MainWindow::on_E_released() {this->_check_letter("EeÉéÈèÊêËë");}
void    MainWindow::on_F_released() {this->_check_letter("Ff");}
void    MainWindow::on_G_released() {this->_check_letter("Gg");}
void    MainWindow::on_H_released() {this->_check_letter("Hh");}
void    MainWindow::on_I_released() {this->_check_letter("IiÎîÏï");}
void    MainWindow::on_J_released() {this->_check_letter("Jj");}
void    MainWindow::on_K_released() {this->_check_letter("Kk");}
void    MainWindow::on_L_released() {this->_check_letter("Ll");}
void    MainWindow::on_M_released() {this->_check_letter("Mm");}
void    MainWindow::on_N_released() {this->_check_letter("Nn");}
void    MainWindow::on_O_released() {this->_check_letter("OoÔôŒœ");}
void    MainWindow::on_P_released() {this->_check_letter("Pp");}
void    MainWindow::on_Q_released() {this->_check_letter("Qq");}
void    MainWindow::on_R_released() {this->_check_letter("Rr");}
void    MainWindow::on_S_released() {this->_check_letter("Ss");}
void    MainWindow::on_T_released() {this->_check_letter("Tt");}
void    MainWindow::on_U_released() {this->_check_letter("UuÙùÛûÜü");}
void    MainWindow::on_V_released() {this->_check_letter("Vv");}
void    MainWindow::on_W_released() {this->_check_letter("Ww");}
void    MainWindow::on_X_released() {this->_check_letter("Xx");}
void    MainWindow::on_Y_released() {this->_check_letter("YyŸÿ");}
void    MainWindow::on_Z_released() {this->_check_letter("Zz");}
