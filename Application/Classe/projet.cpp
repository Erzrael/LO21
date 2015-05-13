#include "projet.h"

void Projet::ajouterTache(Tache * t)
{
   // l'échéance du projet est repoussée si nécessaire
   if(t->getEcheance() > this->getDateDispo()){
      dateDispo = t->getEcheance();
   }
   //la tache est ajoutée au projet
   taches.push_back(t);
}

QDate projet::getEcheance() const
{
   return echeance;
}

void projet::setEcheance(const QDate & value)
{
   echeance = value;
}
QDate projet::getDateDispo() const
{
   return dateDispo;
}

void projet::setDateDispo(const QDate & value)
{
   dateDispo = value;
}
