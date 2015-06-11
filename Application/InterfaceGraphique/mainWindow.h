#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

class QTreeWidgetItem;
class Tache;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTreeWidgetItem *addTreeRoot(QString name, QString description);
    QTreeWidgetItem *addTreeChild(QTreeWidgetItem *parent,
                      QString name, QString description);
    QTreeWidgetItem *trouver(std::vector<QTreeWidgetItem*> tab, QString id);

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

    void action_ajoutProgrammation(int heure = 0, int jour = 0);
    void action_voirProgrammations(int heure = 0, int jour = 0);
private:
    void MAJ_treeview();
    void MAJ_agenda();

    QDate getDate(int jour);
    QTime getTime(int heure);

    QDate choixSemaine;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
