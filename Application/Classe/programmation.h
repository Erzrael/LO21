#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include "tache.h"
#include "evenement.h"

class Programmation
{
   const Evenement* evenement;

   QDate date;
   QTime debut;
   QTime fin;
   Programmation(const Evenement& t, const QDate& d, const QTime& t_debut, const QTime& t_fin);

   friend class Agenda;
public:

   const Evenement* getEvenement() const;
   QDate getDate() const;
   Duree getDuree() const;
   QTime getDebut() const;
   QTime getFin() const;
};

#endif // PROGRAMMATION_H
