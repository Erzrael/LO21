#include "tacheUnitaire.h"
#include "tachePreemptable.h"

TachePreemptable::TachePreemptable(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline, const Duree &dur) :
   TacheUnitaire(id, t, dispo, deadline, dur)
{
}

bool TachePreemptable::getPreempte()
{
    return true;
}
