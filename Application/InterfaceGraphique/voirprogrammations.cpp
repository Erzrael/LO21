#include "voirprogrammations.h"
#include "ui_voirprogrammations.h"
#include <QTime>
#include <Classe/agenda.h>
#include <Classe/projetManager.h>
#include "ajoutprogrammation.h"

VoirProgrammations::VoirProgrammations(QWidget *parent, QDate date, QTime h_debut) :
   QDialog(parent),
   ui(new Ui::VoirProgrammations), date(date), time(h_debut)
{
   ui->setupUi(this);

   load_tab();

}

VoirProgrammations::~VoirProgrammations()
{
   delete ui;
}

void VoirProgrammations::on_ajouterProg_clicked()
{
   ajoutProgrammation ajout_p_window(this, date, time );
   ajout_p_window.setModal(true);
   ajout_p_window.exec();

}

void VoirProgrammations::on_suppr_clicked()
{
   int ligne = ui->eventTab->currentRow();
   QTime debut = QTime::fromString( ui->eventTab->item(ligne, 1)->text() );

   //qDebug() << "suppression "
   try {
      Agenda::getInstance().supprimerProgramation( date, debut );
      QMessageBox::information(this, "Bravo !", "Programmation supprimée");
      ui->eventTab->removeRow(ligne);
   } catch (CalendarException e) {
      QMessageBox::warning(this,"Erreur",e.getInfo());
   }


   // load_tab();

}

void VoirProgrammations::load_tab()
{
   QTime h_fin = time.addSecs(7200);
   Agenda & agenda = Agenda::getInstance();

   vector<const Programmation *> tab = agenda.tabChevaucheHoraire(date, time, h_fin);
   int i = 0;
   for ( vector<const Programmation *>::iterator it = tab.begin() ; it != tab.end() ; it ++ ) {
      //ui->listTache->addItem( (*it)->getID() );
      ui->eventTab->insertRow(i);
      ui->eventTab->setItem(i, 0, new QTableWidgetItem( (*it)->getEvenement()->getID() ));
      ui->eventTab->setItem(i, 1, new QTableWidgetItem( (*it)->getDebut().toString() ));
      ui->eventTab->setItem(i, 2, new QTableWidgetItem( (*it)->getFin().toString() ));
      i++;
   }
}
