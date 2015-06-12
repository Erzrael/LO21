#include "ajoutprogrammation.h"
#include "ui_ajoutprogrammation.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"
#include "Classe/agenda.h"
#include "Classe/duree.h"

ajoutProgrammation::ajoutProgrammation(QWidget * parent, QDate date, QTime h_debut):
   QDialog(parent),
   ui(new Ui::ajoutProgrammation)
{
   ui->setupUi(this);
   //initialisation d'après les paramètres
   ui->date->setDate(date);
   ui->heure_debut->setTime(h_debut);

   ProjetManager &projetmanager = ProjetManager::getInstance();
   Agenda & agenda = Agenda::getInstance();

   //on ne peut sélectionner que les taches ajoutables : les taches unitaires, les préemptables ou celles qui n'ont pas encore été programmées
   for(ProjetManager::TacheIterator it = projetmanager.tache_begin(); it != projetmanager.tache_end(); it++) {
      TacheUnitaire * tu = dynamic_cast<TacheUnitaire *> (*it) ;
      if (tu) {
         if(tu->getPreempte() == true || agenda.trouverProgrammation(*tu).empty()) {
            ui->tache_box->addItem((*it)->getIdentificateur());
         }
      }
   }
}
ajoutProgrammation::~ajoutProgrammation()
{
   delete ui;
}

void ajoutProgrammation::on_cancel_ok_accepted()
{
   Agenda & agenda = Agenda::getInstance();
   ProjetManager &projetmanager = ProjetManager::getInstance();

   if ( ui->selection_type->currentIndex() == 0 ) { // on veut insérer une tâche
      TacheUnitaire* unitaire = static_cast<TacheUnitaire*>(projetmanager.getTache(ui->tache_box->currentText()));

      // s'il n'y a pas de durée ou que la tache n'est pas préemtable
      if ( unitaire->getPreempte() == false || ( ui->duree->time().hour() == 0 && ui->duree->time().minute() == 0 ) ) {
         try {
            agenda.ajouterProgrammation(*unitaire, ui->date->date(), ui->heure_debut->time());
            QMessageBox::information(this,"Succès","Programmation Ajoutée");
         } catch (CalendarException e) {
            QMessageBox::warning(this,"Erreur : ",e.getInfo());
         }
      } else {
         //TachePreemptable * p = unitaire ;
         TachePreemptable * p = reinterpret_cast<TachePreemptable*>( unitaire );
         //      int heure = ui->duree->time().hour();
         //      int minute = ui->duree->time().minute();
         try {
            QTime foutoidemaggle(ui->duree->time());
            Duree dbraou(foutoidemaggle.hour(), foutoidemaggle.minute());
            agenda.ajouterProgrammation(*p, ui->date->date(), ui->heure_debut->time(), dbraou);
            QMessageBox::information(this,"Succès","Programmation Ajoutée");
         } catch (CalendarException e) {
            QMessageBox::warning(this,"Erreur : ",e.getInfo());
         }
      }
   } else if (ui->selection_type->currentIndex() == 1 ) { // on veut insérer un évènement traditionnel
      // s'il n'y a pas de durée, erreur
      if ( ui->duree->time().hour() == 0 && ui->duree->time().minute() == 0 ) {
         QMessageBox::warning(this,"Erreur ", "veuillez indiquer une durée");
      } else {
         try {
            QTime foutoidemaggle(ui->duree->time());
            Duree dbraou(foutoidemaggle.hour(), foutoidemaggle.minute());
            agenda.ajouterProgrammation( ui->nom_evt->text(), ui->date->date(), ui->heure_debut->time(), dbraou);
         } catch (CalendarException e) {
            QMessageBox::warning(this,"Erreur : ",e.getInfo());
         }
      }
   } else {
      QMessageBox::warning(this,"Erreur ", "Désolée Sacha, cette fonctionnalité du Pokétache n'est pas encore implémentée !");
   }
}
