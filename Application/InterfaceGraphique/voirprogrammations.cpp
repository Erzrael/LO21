#include "voirprogrammations.h"
#include "ui_voirprogrammations.h"
#include <QTime>
#include <Classe/agenda.h>
#include "ajoutprogrammation.h"

VoirProgrammations::VoirProgrammations(QWidget *parent, QDate date, QTime h_debut) :
   QDialog(parent),
   ui(new Ui::VoirProgrammations), date(date), time(h_debut)
{
   ui->setupUi(this);

   QTime h_fin = h_debut.addSecs(7200);
   Agenda & agenda = Agenda::getInstance();

   vector<const Programmation *> tab = agenda.tabChevaucheHoraire(date, h_debut, h_fin);
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
