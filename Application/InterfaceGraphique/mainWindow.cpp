#include "Classe/projetManager.h"
#include "Classe/projet.h"
#include "Classe/tache.h"
#include "ExportImport/import_xml.h"
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
#include "ajoutprogrammation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->TabAgenda, SIGNAL( cellDoubleClicked (int, int)), this, SLOT( action_ajoutProgrammation( int jour, int heure) )) ;

    MAJ_treeview();
}

MainWindow::~MainWindow()
{
   ExportImport_XML save("SAUVEGARDE.xml");
   save.save();
   delete ui;
}

void MainWindow::action_ajoutProgrammation(int jour, int heure)
{
   //interpréter paramètres
   ajoutProgrammation ajout_p_window;
   ajout_p_window.setModal(true);
   ajout_p_window.exec();
   //MAJ_agenda()
}

void MainWindow::on_actionAjouter_un_Projet_triggered()
{
    AjoutProjetWindow ajout_projet_window;
    ajout_projet_window.setModal(true);
    ajout_projet_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionSupprimer_un_Projet_triggered()
{
    SupprimerProjetWindow supprimer_projet_window;
    supprimer_projet_window.setModal(true);
    supprimer_projet_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionSupprimer_une_T_che_triggered()
{
    SupprimerTacheWindow supprimer_tache_window;
    supprimer_tache_window.setModal(true);
    supprimer_tache_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionModifier_une_T_che_triggered()
{
    ChoixTacheWindow choix_tache_window;
    choix_tache_window.setModal(true);
    choix_tache_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionAjouter_une_contrainte_de_pr_c_dence_triggered()
{
    AjoutPrecedenceWindow ajout_precedence_window;
    ajout_precedence_window.setModal(true);
    ajout_precedence_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionSupprimer_une_Contrainte_de_Pr_c_dence_triggered()
{
    SupprimerPrecedenceWindow supprimer_precedence_window;
    supprimer_precedence_window.setModal(true);
    supprimer_precedence_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionAjouter_une_Composition_triggered()
{
    AjoutCompositionWindow ajout_composition_window;
    ajout_composition_window.setModal(true);
    ajout_composition_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionSupprimer_une_Composition_triggered()
{
    SupprimerCompositionWindow supprimer_composition_window;
    supprimer_composition_window.setModal(true);
    supprimer_composition_window.exec();
    MAJ_treeview();
}

void MainWindow::on_actionAjouter_une_Tache_triggered()
{
    AjoutTacheWindow ajout_tache_window;
    ajout_tache_window.setModal(true);
    ajout_tache_window.exec();
    MAJ_treeview();
}

void MainWindow::on_Actualiser_Button_clicked()
{
   ui->TreeWidget->clear();
    ProjetManager& projetmanager = ProjetManager::getInstance();
    vector<QTreeWidgetItem*> afficher;

    for(vector<Projet *>::const_iterator it_projets = projetmanager.getProjets().begin(); it_projets != projetmanager.getProjets().end(); ++it_projets){
        QTreeWidgetItem *treeItem = addTreeRoot((*it_projets)->getId(), (*it_projets)->getTitre());
        afficher.push_back(treeItem);
        vector<Tache*> A_afficher = (*it_projets)->getTaches();
        vector<Tache*>::iterator it_taches = A_afficher.begin();
        // Affichage des tâches directement reliées au projet
        while(it_taches != A_afficher.end()){
            if((*it_taches)->getPere() == 0){
                afficher.push_back(addTreeChild(treeItem, (*it_taches)->getIdentificateur(), (*it_taches)->getTitre()));
                it_taches = A_afficher.erase(it_taches);
            } else {
                ++it_taches;
            }
        }

        // Affichage des compositions
        it_taches = A_afficher.begin();
        while(!A_afficher.empty()){
            QTreeWidgetItem* item = trouver(afficher, (*it_taches)->getPere()->getIdentificateur());
            if(item){
                afficher.push_back(addTreeChild(item, (*it_taches)->getIdentificateur(), (*it_taches)->getTitre()));
                it_taches = A_afficher.erase(it_taches);
            } else {
                ++it_taches;
            }
            if(it_taches == A_afficher.end())
                it_taches = A_afficher.begin();
        }
    }
}

void MainWindow::MAJ_treeview()
{
   ui->TreeWidget->clear();
    ProjetManager& projetmanager = ProjetManager::getInstance();
    vector<QTreeWidgetItem*> afficher;

    for(vector<Projet *>::const_iterator it_projets = projetmanager.getProjets().begin(); it_projets != projetmanager.getProjets().end(); ++it_projets){
        QTreeWidgetItem *treeItem = addTreeRoot((*it_projets)->getId(), (*it_projets)->getTitre());
        afficher.push_back(treeItem);
        vector<Tache*> A_afficher = (*it_projets)->getTaches();
        vector<Tache*>::iterator it_taches = A_afficher.begin();
        // Affichage des tâches directement reliées au projet
        while(it_taches != A_afficher.end()){
            if((*it_taches)->getPere() == 0){
                afficher.push_back(addTreeChild(treeItem, (*it_taches)->getIdentificateur(), (*it_taches)->getTitre()));
                it_taches = A_afficher.erase(it_taches);
            } else {
                ++it_taches;
            }
        }

        // Affichage des compositions
        it_taches = A_afficher.begin();
        while(!A_afficher.empty()){
            QTreeWidgetItem* item = trouver(afficher, (*it_taches)->getPere()->getIdentificateur());
            if(item){
                afficher.push_back(addTreeChild(item, (*it_taches)->getIdentificateur(), (*it_taches)->getTitre()));
                it_taches = A_afficher.erase(it_taches);
            } else {
                ++it_taches;
            }
            if(it_taches == A_afficher.end())
                it_taches = A_afficher.begin();
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

QTreeWidgetItem* MainWindow::addTreeChild(QTreeWidgetItem *parent,
                  QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);

    return treeItem;
}

QTreeWidgetItem * MainWindow::trouver(std::vector<QTreeWidgetItem *> tab, QString id)
{
    for(vector<QTreeWidgetItem*>::const_iterator it = tab.begin(); it != tab.end(); ++it){
        if(id == (*it)->text(0)){
            qDebug()<<"Je retourne le widget parent";
            return *it;
        }
    }
    qDebug()<<"Je retourne 0";
    return 0;
}
