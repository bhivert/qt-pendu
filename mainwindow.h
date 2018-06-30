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
    void    on_A_released();
    void    on_B_released();
    void    on_C_released();
    void    on_D_released();
    void    on_E_released();
    void    on_F_released();
    void    on_G_released();
    void    on_H_released();
    void    on_I_released();
    void    on_J_released();
    void    on_K_released();
    void    on_L_released();
    void    on_M_released();
    void    on_N_released();
    void    on_O_released();
    void    on_P_released();
    void    on_Q_released();
    void    on_R_released();
    void    on_S_released();
    void    on_T_released();
    void    on_U_released();
    void    on_V_released();
    void    on_W_released();
    void    on_X_released();
    void    on_Y_released();
    void    on_Z_released();

    void    on_action_New_triggered();

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
