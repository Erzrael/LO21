#include "QFileDialog"

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
#include "voirprogrammations.h"
#include "editionTacheCompositeWindow.h"
#include "editionTacheUnitaireWindow.h"
#include "editionProjetWindow.h"
#include "Classe/agenda.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), choixSemaine(QDate::currentDate()),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MAJ_agenda();
    MAJ_treeview_Composition();
}

MainWindow::~MainWindow()
{
   ExportImport_XML save("SAUVEGARDE.xml");
   save.save();
   delete ui;
}

void MainWindow::on_choixDate_dateChanged(const QDate & nouvelleDate)
{
   choixSemaine = nouvelleDate;
   MAJ_agenda();
}

void MainWindow::on_actionOuvrir_un_Fichier_triggered()
{
   QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                             QString(), tr("XML-Files (*.xml);;All Files (*)"));

   // braou extension de fichiers.
   if (!fn.isEmpty()) {
      if ( fn.endsWith(".xml") ) {
         try {
            ProjetManager::getInstance().supprimerTout();
            Agenda::getInstance().supprimerTout();

            ExportImport_XML load(fn);
            load.load();
            QMessageBox::information(this,"BRAVO !!!","Le fichier a bien été importé !");
         } catch (CalendarException e) {
            QMessageBox::warning(this,"Erreur : ",e.getInfo());
         }
      } else {
         QMessageBox::warning(this,"Erreur : ","Extension non reconnue (.xml) ");
      }
   }
}

void MainWindow::on_actionEnregistrer_sous_triggered()
{
   QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                             QString(), tr("XML-Files (*.xml);;All Files (*)"));
   if (fn.isEmpty())
       return;
   if (! (fn.endsWith(".xml", Qt::CaseInsensitive) ) ) {
       QMessageBox::warning(this,"Erreur : ","Extension non reconnue (.xml) ");
       return;
   } else {
      try {
         ExportImport_XML save(fn);
         save.save();
         QMessageBox::information(this,"BRAVO !!!","Le fichier a bien été exporté !");
      } catch (CalendarException e) {
         QMessageBox::warning(this,"Erreur : ",e.getInfo());
      }
   }
}


void MainWindow::on_TabAgenda_cellDoubleClicked(int heure, int jour)
{
   if (heure == 0 ) { // on ne peut pas ajouter une programmation sur la premère ligne du tableau (affiche les dates)
      return;
   }
   //interpréter paramètres
   //qDebug() << "Je me fous de taggle";
   ajoutProgrammation ajout_p_window(this, getDate(jour), getTime(heure) );
   ajout_p_window.setModal(true);
   ajout_p_window.exec();
   MAJ_agenda();
}

void MainWindow::on_TabAgenda_cellClicked(int heure, int jour)
{
//   qDebug() << "Date :: " << getDate(jour).toString("d/MM/yyyy");
//   qDebug() << "Heure :: " << getTime(heure).toString("hh:mm");

   if (ui->TabAgenda->item(heure, jour)->text() == "0")
      return;

   VoirProgrammations v_programmations(this, getDate(jour), getTime(heure));
   v_programmations.setModal(true);
   v_programmations.exec();
   MAJ_agenda();
}

void MainWindow::on_actionAjouter_un_Projet_triggered()
{
    AjoutProjetWindow ajout_projet_window;
    ajout_projet_window.setModal(true);
    ajout_projet_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionSupprimer_un_Projet_triggered()
{
    SupprimerProjetWindow supprimer_projet_window;
    supprimer_projet_window.setModal(true);
    supprimer_projet_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionSupprimer_une_T_che_triggered()
{
    SupprimerTacheWindow supprimer_tache_window;
    supprimer_tache_window.setModal(true);
    supprimer_tache_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionModifier_une_T_che_triggered()
{
    ChoixTacheWindow choix_tache_window;
    choix_tache_window.setModal(true);
    choix_tache_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionAjouter_une_contrainte_de_pr_c_dence_triggered()
{
    AjoutPrecedenceWindow ajout_precedence_window;
    ajout_precedence_window.setModal(true);
    ajout_precedence_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionSupprimer_une_Contrainte_de_Pr_c_dence_triggered()
{
    SupprimerPrecedenceWindow supprimer_precedence_window;
    supprimer_precedence_window.setModal(true);
    supprimer_precedence_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionAjouter_une_Composition_triggered()
{
    AjoutCompositionWindow ajout_composition_window;
    ajout_composition_window.setModal(true);
    ajout_composition_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionSupprimer_une_Composition_triggered()
{
    SupprimerCompositionWindow supprimer_composition_window;
    supprimer_composition_window.setModal(true);
    supprimer_composition_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::on_actionAjouter_une_Tache_triggered()
{
    AjoutTacheWindow ajout_tache_window;
    ajout_tache_window.setModal(true);
    ajout_tache_window.exec();
    MAJ_treeview_Composition();
}

void MainWindow::MAJ_treeview_Composition()
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

void MainWindow::MAJ_agenda()
{
   // on fait en sorte que le jour de la semaine choisie soit le lundi
   while (choixSemaine.dayOfWeek() != 1 ) {
      // qDebug() << choixSemaine.toString();
      choixSemaine = choixSemaine.addDays(-1);
   }
   QDate jour = choixSemaine;
   QTime debut(0, 0, 0), fin(2,0,0);
   unsigned int nbProgramme;
   for (int colonne = 0 ; colonne < 6 ; colonne ++) {
//      m_pTableWidget->setItem(0, 1, new QTableWidgetItem("Hello"));
      ui->TabAgenda->setItem(0, colonne, new QTableWidgetItem(jour.toString("d/MM/yyyy")) );

      for (int ligne = 1 ; ligne < 13 ; ++ligne) {
         nbProgramme = Agenda::getInstance().chevaucheHoraire(jour, debut, fin);
         ui->TabAgenda->setItem(ligne, colonne, new QTableWidgetItem(QString::number(nbProgramme) ) );
//         if (nbProgramme != 0) {
//            ui->TabAgenda->setItem(ligne, colonne, new QTableWidgetItem(QString::number(nbProgramme) ) );
//            // ui->TabAgenda->item(ligne, colonne)->setCheckState(Qt::Checked);
//         }
         //on passe à la tranche horaire supérieure (+2H)
         debut = debut.addSecs(7200);
         fin = fin.addSecs(7200);
      }


      jour = jour.addDays(1);
   }

   // affichage du reste
   for(int colonne = 0 ; colonne < 6 ; ++colonne ) {

   }
}

QDate MainWindow::getDate(int jour)
{
   QString s = ui->TabAgenda->item(0, jour)->text() ;
   return QDate::fromString(s, "d/MM/yyyy") ;
}

QTime MainWindow::getTime(int heure)
{
   int h = (heure - 1) * 2;
   return QTime(h, 0, 0);
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

void MainWindow::on_TreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int)
{
    ProjetManager& projetmanager = ProjetManager::getInstance();

    if(ui->TreeWidget->itemAbove(ui->TreeWidget->itemAbove(item)) == 0)
    {
        EditionProjetWindow* edition_projet_window = new EditionProjetWindow(projetmanager.getProjet(item->text(0)));
        edition_projet_window->setModal(true);
        edition_projet_window->exec();
        delete edition_projet_window;

    } else {
        try{
            Tache* T = projetmanager.getTache(item->text(0));
            TacheComposite* Compo = dynamic_cast<TacheComposite*>(T);

            if(Compo){
                EditionTacheCompositeWindow* edition_tache_composite_window = new EditionTacheCompositeWindow(Compo);
                edition_tache_composite_window->setModal(true);
                edition_tache_composite_window->exec();
                delete edition_tache_composite_window;
            } else {
                TacheUnitaire* Unitaire = dynamic_cast<TacheUnitaire*>(T);
                EditionTacheUnitaireWindow* edition_tache_unitaire_window = new EditionTacheUnitaireWindow(Unitaire);
                edition_tache_unitaire_window->setModal(true);
                edition_tache_unitaire_window->exec();
                delete edition_tache_unitaire_window;
            }
        } catch (CalendarException e) {
            QMessageBox::warning(this, "Erreur", e.getInfo());
        }
    }

    MAJ_treeview_Composition();
}
