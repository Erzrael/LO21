#ifndef TACHENONPREEMPTABLE_H
#define TACHENONPREEMPTABLE_H

class TacheUnitaire;

/*! \brief classe représentant une tache non préemptable
 * une tache non préemptable ne peut avoir qu'une seule programmation associée
 * Hérite de TacheUnitaire
 */
class TacheNonPreemptable : public TacheUnitaire
{
public:
   bool getPreempte(); /*!< \return false \exception CalendarException si erreur (durée > 12h) */

   TacheNonPreemptable(const QString & id, const QString & t, const QDate & dispo, const QDate & deadline, const Duree & dur); /*!< constructeur */
};

#endif // TACHENONPREEMPTABLE_H
