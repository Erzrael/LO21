#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include "tache.h"

class Programmation
{
   const Tache* tache;
   QDate date;
   QTime horaire;
public:
   Programmation(const Tache& t, const QDate& d, const QTime& h):tache(&t), date(d), horaire(h){}

   const Tache* getTache() const { return tache; }
   QDate getDate() const { return date; }
   QTime getHoraire() const { return horaire; }
};

#endif // PROGRAMMATION_H
