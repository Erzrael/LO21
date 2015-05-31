#include "programmation.h"


Programmation::Programmation(const Evenement & t, const QDate & d, const QTime & t_debut, const QTime & t_fin) :
   evenement(&t), date(d), debut(t_debut), fin(t_fin)
{

}

const Evenement *Programmation::getEvenement() const
{
   return evenement;
}

QDate Programmation::getDate() const { return date; }

QTime Programmation::getDebut() const { return debut; }

QTime Programmation::getFin() const { return fin; }
