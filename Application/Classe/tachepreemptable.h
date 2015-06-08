#ifndef TACHEPREEMPTABLE_H
#define TACHEPREEMPTABLE_H
#include "tacheUnitaire.h"
#include "QString"
#include "QDate"
#include "duree.h"

class TachePreemptable : public TacheUnitaire
{
public:
   /* Les Getters et Setters */
   const bool& getPreempte() const;
   bool getPreempte();

   TachePreemptable(const QString & id, const QString & t, const QDate & dispo, const QDate & deadline, const Duree & dur);

};

#endif // TACHEPREEMPTABLE_H
