#include "agenda.h"
#include "tacheUnitaire.h"
#include "tachePreemptable.h"

Agenda::Agenda() {}

Agenda::~Agenda(){
   qDebug()<<"Destruction de Agenda";

   while(!programmations.empty()){
      delete programmations.back();
      programmations.pop_back();
   }
}

vector<Programmation *> & Agenda::trouverProgrammation(const Evenement& t)const{
   vector<Programmation *> * listeProgrammation = new vector<Programmation *>();

   std::list<Programmation *>::const_iterator it ;

   for(it = programmations.begin(); it != programmations.end() ; ++it)
      if (&t ==(*it)->getEvenement() )
         listeProgrammation->push_back(*it);

   return *listeProgrammation;
}

void Agenda::supprimerTout()
{
   while(!programmations.empty()){
      delete programmations.back();
      programmations.pop_back();
   }
}

unsigned int Agenda::chevaucheHoraire(const QDate & date, const QTime & debut, const QTime & fin)
{
   int result = 0;

   std::list<Programmation *>::iterator it ;

   for(it = programmations.begin(); it != programmations.end() ; ++it)
      if ( chevauche(date, debut, fin, it) )
         result ++;

   return result;

}

vector<const Programmation *> &Agenda::tabChevaucheHoraire(const QDate & date, const QTime & debut, const QTime & fin)
{
   vector<const Programmation *> * tab = new vector<const Programmation *>;
   std::list<Programmation *>::iterator it ;

   for(it = programmations.begin(); it != programmations.end() ; ++it)
      if ( chevauche(date, debut, fin, it) )
         tab->push_back( (*it));

   return *tab;
}

std::list<Programmation *> &Agenda::getProgrammation()
{
   return programmations;
}

const std::list<Programmation *> &Agenda::getProgrammation() const
{
   return programmations;
}

void Agenda::ajouterProgrammation(const TachePreemptable & t, const QDate& d, const QTime& h, const Duree duree){
   Duree d_totale = Duree(duree);

   vector <Programmation *> & listeProgrammation = trouverProgrammation(t);
   std::vector<Programmation *>::const_iterator it ;

   //On vérifie que la durée totale des taches programmée n'est pas supérieure à la durée de la tache préempée
   for(it = listeProgrammation.begin(); it != listeProgrammation.end() ; ++it ) {
      d_totale.setDuree( d_totale.getDureeEnMinutes() + (*it)->getDuree().getDureeEnMinutes() );
   }
   if ( t.getDuree() < d_totale ) {
      throw CalendarException("erreur AjouterProgrammation : durée totale supérieure à la durée de la tâche") ;
   }

   int minutes = duree.getDureeEnMinutes();
   QTime * fin = new QTime(h.addSecs( minutes * 60) );
   // qDebug() << "minutes" << minutes << "Time :" << *fin;

   ajouterProgrammation( t, d, h, *fin );
}

void Agenda::ajouterProgrammation(const TacheUnitaire & t, const QDate& d, const QTime& h){
   vector <Programmation *> & listeProgrammation = trouverProgrammation(t);
   // si la programmation existe déjà, on ne peut pas la programmer à nouveau
   if (listeProgrammation.size() != 0 ) {
      throw CalendarException("erreur ajouterProgrammation, cette fonction ne peut être appelée que si la tâche n'a jamais été programmée");
   }

   int minute_fin = h.minute() + t.getDuree().getMinute();
   int heure_fin = h.hour() + t.getDuree().getHeure() + (minute_fin / 60) ;
   minute_fin = minute_fin % 60;
   if ( !QTime::isValid(heure_fin, minute_fin, 0) ) {
      throw CalendarException("erreur ajouterProgrammation : une programmation ne peut pas être à cheval sur deux jours");
   }

   ajouterProgrammation(t, d, h, *(new QTime(heure_fin, minute_fin)) );
}

void Agenda::ajouterProgrammation(const Evenement & t, const QDate& d, const QTime& debut, const QTime & fin)
{
   list<Programmation *>::iterator iterator = programmations.begin();

   //-On fait avancer l'itérateur jusqu'au jour qui nous intéresse
   while ( iterator != programmations.end() && (*iterator)->getDate() != d ) {
      iterator++;
   }

   // on continue jusqu'à atteindre la programmation située juste après celle à insérer c'est à dire soit :
   // la fin de la liste, soit la programmation où ce n'est plus le bon jour, soit la programmation suivante dans le planning
   while ( iterator != programmations.end() && (*iterator)->getDate() == d && debut > (*iterator)->getFin() ) {
      if ( Agenda::chevauche(d, debut, fin, iterator)) {
         throw CalendarException("Erreur AjoutProgrammation : deux prog ne peuvent se chevaucher (le cheval c'est génial)");
      }
      ++iterator;
   }
   // on vérifie les chevauchements
   if ( Agenda::chevauche(d, debut, fin, iterator)) {
      throw CalendarException("Erreur AjoutProgrammation : deux prog ne peuvent se chevaucher (le cheval c'est génial)");
   }

   //insertion de la programmation
   programmations.insert(iterator, new Programmation(t, d, debut, fin) );
}

bool Agenda::chevauche(const QDate& d, const QTime& debut, const QTime & fin, list<Programmation *>::iterator position){
   if (position == programmations.end() )
      return false;

//   qDebug() << "chevauche :" << d.toString() << debut.toString() << fin.toString() << " et "
//            << (*position)->getDate().toString() << (*position)->getDebut().toString() << (*position)->getFin().toString() ;
   if ( position != programmations.end() && d == (*position)->getDate() ) {
//      qDebug() << "je vérifie les chevauchements SALOPE" ;
      if ( (debut >= (*position)->getDebut() && debut < (*position)->getFin() ) ||
           (fin > (*position)->getDebut() && fin <= (*position)->getFin() ) ||
           ((*position)->getDebut() >= debut && (*position)->getDebut() < fin ) ||
           ((*position)->getFin() > debut && (*position)->getFin() <=  fin ) ) {
         //qDebug() << "Se chevauchent" ;
         return true;
      }
   }
   //qDebug() << "ne se chevauchent pas";
   return false;
}

Agenda &Agenda::getInstance()
{
   static Agenda instanceUnique;
   return instanceUnique;
}

void Agenda::supprimerProgrammation(const QDate & d, const QTime & h)
{
   std::list<Programmation *>::iterator it ;

   for(it = programmations.begin(); it != programmations.end() ; ++it)
      if ( (*it)->getDate() == d && (*it)->getDebut() == h ) {
         delete (*it);
         programmations.erase(it);
         return ;
      }

   throw CalendarException("La programmation que vous voulez supprimer n'existe pas");
}

void Agenda::supprimerProgrammation(const Evenement & t)
{
   vector<Programmation *> tab = this->trouverProgrammation(t);
   while ( !tab.empty() ) {
      supprimerProgrammation( tab.back()->getDate(), tab.back()->getDebut() );
      tab.pop_back();
   }
}

void Agenda::ajouterProgrammation(const QString & nomDeLEventClassique, const QDate & d, const QTime & h, const Duree duree)
{
   EvenementClassique & evt = *(new EvenementClassique(duree, nomDeLEventClassique) );

   int minute_fin = h.minute() + duree.getMinute();
   int heure_fin = h.hour() + duree.getHeure() + (minute_fin / 60) ;
   minute_fin = minute_fin % 60;
   if ( !QTime::isValid(heure_fin, minute_fin, 0) ) {
      throw CalendarException("erreur ajouterProgrammation : une programmation ne peut pas être à cheval sur deux jours");
   }

   ajouterProgrammation(evt, d, h, *(new QTime(heure_fin, minute_fin)) );

}
