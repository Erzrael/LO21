#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "ajoutProjetWindow.h"
#include "supprimerProjetWindow.h"
#include "ajoutTacheUnitaireWindow.h"
#include "ajoutTacheCompositeWindow.h"
#include "supprimerTacheWindow.h"
#include "choixTacheWindow.h"
#include "ajoutPrecedenceWindow.h"
#include "supprimerPrecedenceWindow.h"
#include "ajoutCompositionWindow.h"
#include "supprimerCompositionWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAjouter_un_Projet_triggered()
{
    AjoutProjetWindow ajout_projet_window;
    ajout_projet_window.setModal(true);
    ajout_projet_window.exec();
}

void MainWindow::on_actionSupprimer_un_Projet_triggered()
{
    SupprimerProjetWindow supprimer_projet_window;
    supprimer_projet_window.setModal(true);
    supprimer_projet_window.exec();
}

void MainWindow::on_actionAjouter_une_T_che_Unitaire_triggered()
{
    AjoutTacheUnitaireWindow ajout_tache_unitaire_window;
    ajout_tache_unitaire_window.setModal(true);
    ajout_tache_unitaire_window.exec();
}


void MainWindow::on_actionAjouter_une_T_che_Composite_triggered()
{
    AjoutTacheCompositeWindow ajout_tache_composite_window;
    ajout_tache_composite_window.setModal(true);
    ajout_tache_composite_window.exec();
}

void MainWindow::on_actionSupprimer_une_T_che_triggered()
{
    SupprimerTacheWindow supprimer_tache_window;
    supprimer_tache_window.setModal(true);
    supprimer_tache_window.exec();
}

void MainWindow::on_actionModifier_une_T_che_triggered()
{
    ChoixTacheWindow choix_tache_window;
    choix_tache_window.setModal(true);
    choix_tache_window.exec();
}

void MainWindow::on_actionAjouter_une_contrainte_de_pr_c_dence_triggered()
{
    AjoutPrecedenceWindow ajout_precedence_window;
    ajout_precedence_window.setModal(true);
    ajout_precedence_window.exec();
}

void MainWindow::on_actionSupprimer_une_Contrainte_de_Pr_c_dence_triggered()
{
    SupprimerPrecedenceWindow supprimer_precedence_window;
    supprimer_precedence_window.setModal(true);
    supprimer_precedence_window.exec();
}

void MainWindow::on_actionAjouter_une_Composition_triggered()
{
    AjoutCompositionWindow ajout_composition_window;
    ajout_composition_window.setModal(true);
    ajout_composition_window.exec();
}

void MainWindow::on_actionSupprimer_une_Composition_triggered()
{
    SupprimerCompositionWindow supprimer_composition_window;
    supprimer_composition_window.setModal(true);
    supprimer_composition_window.exec();
}
