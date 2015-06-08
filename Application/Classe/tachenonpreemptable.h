#ifndef TACHENONPREEMPTABLE_H
#define TACHENONPREEMPTABLE_H
#include "tacheUnitaire.h"

class TacheNonPreemptable : public TacheUnitaire
{
public:
   bool getPreempte();

   TacheNonPreemptable(const QString & id, const QString & t, const QDate & dispo, const QDate & deadline, const Duree & dur);
};

#endif // TACHENONPREEMPTABLE_H
