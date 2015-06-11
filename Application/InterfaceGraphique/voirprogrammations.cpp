#include "voirprogrammations.h"
#include "ui_voirprogrammations.h"
#include <QTime>
#include <Classe/agenda.h>

VoirProgrammations::VoirProgrammations(QWidget *parent, QDate date, QTime h_debut) :
   QDialog(parent),
   ui(new Ui::VoirProgrammations)
{
   ui->setupUi(this);

   QTime h_fin = h_debut.addSecs(7200);
   Agenda & agenda = Agenda::getInstance();

   vector<const Evenement *> tab = agenda.tabChevaucheHoraire(date, h_debut, h_fin);

   for ( vector<const Evenement *>::iterator it = tab.begin() ; it != tab.end() ; it ++ ) {
      ui->listTache->addItem( (*it)->getID() );
   }

}

VoirProgrammations::~VoirProgrammations()
{
   delete ui;
}
