#include "agenda.h"
#include "tacheUnitaire.h"

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
 * \return L'adresse de la programmation
 * \return 0 en cas d'échec (la tâche n'est pas encore programmée)
 */
Programmation* Agenda::trouverProgrammation(const TacheUnitaire& t)const{
   const Evenement * t2 = static_cast<const Evenement *> (&t);
   std::list<Programmation *>::const_iterator it ;
    for(it = programmations.begin(); it != programmations.end() ; ++it)
        if (t2 ==(*it)->getEvenement() )
           return *it;
    return 0;
}

std::list<Programmation *> &Agenda::getProgrammation()
{
   return programmations;
}

const std::list<Programmation *> &Agenda::getProgrammation() const
{
   return programmations;
}
/**
 * \TODO faire attention à ce que deux programmations ne puissent pas se chevaucher
 * 
 * \brief Associe une programmation à une tâche passée en argument
 * \details Vérifie si la tâche n'est pas encore programmée, auquel cas lance une exception.
 * 
 * \param t Tache que l'on veut programmer
 * \param d Date à laquelle la tache sera programmée
 * \param h Heure à laquelle la tache sera programmée
 */
Agenda::IteratorJournee Agenda::itJ_begin(QDate journee)
{
   return IteratorJournee(journee, programmations);
}

Agenda::IteratorJournee Agenda::itJ_end(QDate journee)
{
   return IteratorJournee(journee, programmations.begin(), programmations.end());
}

void Agenda::ajouterProgrammation(const TacheUnitaire & t, const QDate& d, const QTime& h){
   // si la tache n'est pas préemptée & que la programmation existe déjà, on ne peut pas la programmer à nouveau
   if (t.getPreempte() == false && trouverProgrammation(t) ) {
       throw CalendarException("erreur, ProgrammationManager, Programmation deja existante");
   }

   int minute_fin = h.minute() + t.getDuree().getMinute();
   int heure_fin = h.hour() + t.getDuree().getHeure() + (minute_fin / 60) ;
   minute_fin = minute_fin % 60;
   if ( !QTime::isValid(heure_fin, minute_fin, 0) ) {
      throw CalendarException("erreur ajouterProgrammation : une programmation ne peut pas être à cheval sur deux jours");
   }

   Programmation * p = new Programmation ( t, d, h, *(new QTime(heure_fin, minute_fin)) );
   list<Programmation *>::iterator iterator = programmations.begin();

   //-On fait avancer l'itérateur jusqu'au jour qui nous intéresse
   while ( iterator != programmations.end() && (*iterator)->getDate() != d) {
      iterator++;
   }

   // on continue jusqu'à atteindre la programmation située juste après celle à insérer c'est à dire soit :
   // la fin de la liste, soit la programmation où ce n'est plus le bon jour, soit la programmation suivante dans le planning
   while ( iterator != programmations.end() && (*iterator)->getDate() == d && !(p->getFin() <= (*iterator)->getFin()) ) {
      // si on est rentré dans la boucle, on doit vérifier que les deux programmations ne se télescopent pas.
      if ( p->getDebut() < (*iterator)->getFin() ) {
         throw CalendarException("Erreur ajouterProgrammation : deux programmations ne peuvent pas se chevaucher");
      }
      ++iterator;
   }
   //insertion de la programmation
   programmations.insert(iterator, p);
}


Agenda::IteratorJournee::IteratorJournee(QDate j, list<Programmation *> & p): journee(j), it_programmation(p.begin()), end(p.end()){}

Agenda::IteratorJournee::IteratorJournee(QDate j, list<Programmation *>::iterator it_programmation, list<Programmation *>::iterator end) :
   journee(j), it_programmation(it_programmation), end(end) {}

Agenda::IteratorJournee &Agenda::IteratorJournee::operator++(int)
{
   do {
      it_programmation ++;
   } while (it_programmation != end && (*it_programmation)->getDate() != journee );

   return *this;
}

bool Agenda::IteratorJournee::operator==(const Agenda::IteratorJournee & other) const
{
   if (&other == this || (this->it_programmation == other.it_programmation)){
       return true;
   } else{
      return false;
   }
}

bool Agenda::IteratorJournee::operator!=(const Agenda::IteratorJournee & other) const
{
   return !(*this == other);
}

Programmation * Agenda::IteratorJournee::operator*() const
{
   return *it_programmation;
}

Agenda &Agenda::getInstance()
{
    static Agenda instanceUnique;
    return instanceUnique;
}
