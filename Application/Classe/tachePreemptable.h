/*! \file
 * \brief contient la déclaration de la classe TachePreemptable
 *
 *
 */
#ifndef TACHEPREEMPTABLE_H
#define TACHEPREEMPTABLE_H

#include "QString"
#include "QDate"
#include "duree.h"

class TacheUnitaire;

/*! \brief classe représentant une tache préemptable
 * une tâche préemptable peut être associée à plusieurs programmations
 */
class TachePreemptable : public TacheUnitaire
{
public:
   /* Les Getters et Setters */
   const bool& getPreempte() const; /*!< \return true */
   bool getPreempte(); /*!< \return true */

   TachePreemptable(const QString & id, const QString & t, const QDate & dispo, const QDate & deadline, const Duree & dur); /*!< constructeur */

};

#endif // TACHEPREEMPTABLE_H
