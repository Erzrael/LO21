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
    void on_actionAjouter_un_Projet_triggered();

    void on_actionSupprimer_un_Projet_triggered();

    void on_actionSupprimer_une_T_che_triggered();

    void on_actionModifier_une_T_che_triggered();

    void on_actionAjouter_une_contrainte_de_pr_c_dence_triggered();

    void on_actionSupprimer_une_Contrainte_de_Pr_c_dence_triggered();

    void on_actionAjouter_une_Composition_triggered();

    void on_actionSupprimer_une_Composition_triggered();

    void on_actionAjouter_une_Tache_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
