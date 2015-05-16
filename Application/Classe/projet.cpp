#include "projet.h"
/* Pourquoi repousser l'échéance ? Faut pas le faire nan ? */
void Projet::ajouterTache(Tache * t)
{
   // l'échéance du projet est repoussée si nécessaire
   if(t->getEcheance() > this->getDateDispo()){
      dateDispo = t->getEcheance();
   }
   //la tache est ajoutée au projet
   taches.push_back(t);
}

QDate Projet::getEcheance() const
{
   return echeance;
}

void Projet::setEcheance(const QDate & value)
{
   echeance = value;
}
QDate Projet::getDateDispo() const
{
   return dateDispo;
}

void Projet::setDateDispo(const QDate & value)
{
   dateDispo = value;
}
