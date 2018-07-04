#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void    on_A_clicked();
    void    on_B_clicked();
    void    on_C_clicked();
    void    on_D_clicked();
    void    on_E_clicked();
    void    on_F_clicked();
    void    on_G_clicked();
    void    on_H_clicked();
    void    on_I_clicked();
    void    on_J_clicked();
    void    on_K_clicked();
    void    on_L_clicked();
    void    on_M_clicked();
    void    on_N_clicked();
    void    on_O_clicked();
    void    on_P_clicked();
    void    on_Q_clicked();
    void    on_R_clicked();
    void    on_S_clicked();
    void    on_T_clicked();
    void    on_U_clicked();
    void    on_V_clicked();
    void    on_W_clicked();
    void    on_X_clicked();
    void    on_Y_clicked();
    void    on_Z_clicked();

    void    on_action_New_triggered();

    void    on_action_Score_triggered();

    void on_actionConfi_guration_triggered();

private:
    Ui::MainWindow          *ui;

    std::vector<QString>    _dic;
    QString                 _word;
    QString                 _secret;
    size_t                  _life;

    void                    _check_letter(const QString letter);
    void                    _setLife();
};

#endif // MAINWINDOW_H
