#ifndef TACHENONPREEMPTABLE_H
#define TACHENONPREEMPTABLE_H

class TacheUnitaire;

class TacheNonPreemptable : public TacheUnitaire
{
public:
   bool getPreempte();

   TacheNonPreemptable(const QString & id, const QString & t, const QDate & dispo, const QDate & deadline, const Duree & dur);
};

#endif // TACHENONPREEMPTABLE_H
