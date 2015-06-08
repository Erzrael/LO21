#include "Classe/projetManager.h"
#include "Classe/projet.h"
#include "Classe/tache.h"
#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "ajoutProjetWindow.h"
#include "supprimerProjetWindow.h"
#include "ajoutTacheWindow.h"
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

void MainWindow::on_actionAjouter_une_Tache_triggered()
{
    AjoutTacheWindow ajout_tache_window;
    ajout_tache_window.setModal(true);
    ajout_tache_window.exec();
}

void MainWindow::on_Actualiser_Button_clicked()
{
    ProjetManager& projetmanager = ProjetManager::getInstance();

    for(vector<Projet *>::const_iterator it_projets = projetmanager.getProjets().begin(); it_projets != projetmanager.getProjets().end(); ++it_projets){
        QTreeWidgetItem *treeItem = addTreeRoot((*it_projets)->getId(), (*it_projets)->getTitre());
        for(vector<Tache*>::const_iterator it_taches = (*it_projets)->getTaches().begin(); it_taches != (*it_projets)->getTaches().end(); ++it_taches){
            addTreeChild(treeItem, (*it_taches)->getIdentificateur(), (*it_taches)->getTitre());
        }
    }
}

QTreeWidgetItem* MainWindow::addTreeRoot(QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->TreeWidget);

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    return treeItem;
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent,
                  QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);
}
