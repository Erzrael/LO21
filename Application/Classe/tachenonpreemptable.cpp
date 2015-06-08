#include "tachenonpreemptable.h"
#include "tacheUnitaire.h"

TacheNonPreemptable::TacheNonPreemptable(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline, const Duree &dur) :
      TacheUnitaire(id, t, dispo, deadline, dur)
{
   if(Duree(12,0) < dur)
      throw CalendarException("Erreur - TacheUnitaireNonPreemptable - Durée > 12h");
}

bool TacheNonPreemptable::getPreempte()
{
    return false;
}
