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


/**
 * \brief Renvoie l'adresse de la programmation associée à une tâche
 * \details Cette fonction utilise l'itérator natif de vector pour parcourir le vector de pointeur de Programmation.
 * Cette fonction est notamment utilisée afin de vérifier l'existence ou non de la programmation associée à une tâche.
 *
 * \param t Tâche dont on veut trouver la programmation
 * \return Un vector contenant toutes les programmations associées à la tâche (vector vide en cas d'échec)
 */
vector<Programmation *> & Agenda::trouverProgrammation(const TacheUnitaire& t)const{
   vector<Programmation *> * listeProgrammation = new vector<Programmation *>();

   const Evenement * t2 = static_cast<const Evenement *> (&t);
   std::list<Programmation *>::const_iterator it ;

   for(it = programmations.begin(); it != programmations.end() ; ++it)
      if (t2 ==(*it)->getEvenement() )
         listeProgrammation->push_back(*it);

   return *listeProgrammation;
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

//Agenda::IteratorJournee Agenda::itJ_begin(QDate journee)
//{
//   return IteratorJournee(journee, programmations);
//}
//
//Agenda::IteratorJournee Agenda::itJ_end(QDate journee)
//{
//   return IteratorJournee(journee, programmations.begin(), programmations.end());
//}

void Agenda::ajouterProgrammation(const TachePreemptable & t, const QDate& d, const QTime& h, const Duree duree){
   Duree d_totale = Duree(duree);

   vector <Programmation *> & listeProgrammation = trouverProgrammation(t);
   std::vector<Programmation *>::const_iterator it ;

   //On vérifie que la durée totale des taches programmée n'est pas supérieur à la durée de la tache préempée
   for(it = listeProgrammation.begin(); it != listeProgrammation.end() ; ++it ) {
      d_totale.setDuree( d_totale.getDureeEnMinutes() + (*it)->getDuree().getDureeEnMinutes() );
   }
   if ( t.getDuree() < d_totale ) {
   //if ( d_totale < t.getDuree() ) {
      throw CalendarException("erreur AjouterProgrammation : durée totale supérieure à la durée de la tâche") ;
   }

   int minutes = duree.getDureeEnMinutes();
   QTime * fin = new QTime(h.addSecs( minutes * 60) );
   // qDebug() << "minutes" << minutes << "Time :" << *fin;
   /*int minute_fin = h.minute() + duree.getMinute();
   int surplus = minute_fin / 60;
   int heure_fin = h.hour() + duree.getHeure() + (minute_fin / 60) ;
   qDebug() << "heure :" << heure_fin << "minute :" << minute_fin ;
   minute_fin = minute_fin % 60;
   if ( !QTime::isValid(heure_fin, minute_fin, 0) ) {
      throw CalendarException("erreur ajouterProgrammation : une programmation ne peut pas être à cheval sur deux jours");
   }*/

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

void Agenda::ajouterProgrammation(const TacheUnitaire & t, const QDate& d, const QTime& debut, const QTime & fin)
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

//Agenda::IteratorJournee::IteratorJournee(QDate j, list<Programmation *> & p): journee(j), it_programmation(p.begin()), end(p.end()){}
//
//Agenda::IteratorJournee::IteratorJournee(QDate j, list<Programmation *>::iterator it_programmation, list<Programmation *>::iterator end) :
//   journee(j), it_programmation(it_programmation), end(end) {}
//
//Agenda::IteratorJournee &Agenda::IteratorJournee::operator++(int)
//{
//   do {
//      it_programmation ++;
//   } while (it_programmation != end && (*it_programmation)->getDate() != journee );
//
//   return *this;
//}
//
//bool Agenda::IteratorJournee::operator==(const Agenda::IteratorJournee & other) const
//{
//   if (&other == this || (this->it_programmation == other.it_programmation)){
//      return true;
//   } else{
//      return false;
//   }
//}
//
//bool Agenda::IteratorJournee::operator!=(const Agenda::IteratorJournee & other) const
//{
//   return !(*this == other);
//}
//
//Programmation * Agenda::IteratorJournee::operator*() const
//{
//   return *it_programmation;
//}

Agenda &Agenda::getInstance()
{
   static Agenda instanceUnique;
   return instanceUnique;
}

void Agenda::supprimerProgramation(const QDate & d, const QTime & h)
{
   std::list<Programmation *>::const_iterator it ;

   for(it = programmations.begin(); it != programmations.end() ; ++it)
      if ( (*it)->getDate() == d && (*it)->getDebut() == h ) {
         delete (*it);
         return ;
      }

   throw CalendarException("La programmation que vous voulez supprimer n'existe pas");
}
