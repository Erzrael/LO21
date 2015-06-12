#include "programmation.h"


Programmation::Programmation(const Evenement & t, const QDate & d, const QTime & t_debut, const QTime & t_fin) :
   evenement(&t), date(d), debut(t_debut), fin(t_fin)
{

}

Programmation::~Programmation()
{
   Evenement * e = const_cast<Evenement *> (evenement);
   e->suppressionProgrammation();
}

const Evenement *Programmation::getEvenement() const
{
   return evenement;
}

QDate Programmation::getDate() const { return date; }

Duree Programmation::getDuree() const
{
   int time = debut.secsTo(fin); // duree en seconde
   time = time / 60; //conversion en minutes

   return Duree(time);
}

QTime Programmation::getDebut() const { return debut; }

QTime Programmation::getFin() const { return fin; }
