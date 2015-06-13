#include "evenement.h"
#include "Classe/projetManager.h"
#include "Classe/agenda.h"


Evenement::Evenement(Duree d) : duree(d){}

Evenement::~Evenement()
{

}
/*
const QString & Evenement::getID() const
{
   static QString braou("Evènement ponctuel");
   return braou ;
}*/

Duree Evenement::getDuree() const
{
   return duree;
}

void Evenement::setDuree(const Duree & value)
{
   Agenda::getInstance().supprimerProgrammation(*this);
   duree = value;
}

void Evenement::suppressionProgrammation()
{
   this->~Evenement();
}


EvenementClassique::EvenementClassique(Duree d, QString nom) : Evenement(d), nom(nom) {
   if ( ProjetManager::getInstance().isTacheExistante(nom) ) {
      throw CalendarException ("Erreur : une tâche existe déjà avec ce nom");
   }
   // vérification unicité dans l'agenda ?
}

const QString &EvenementClassique::getID() const
{
   return nom;
}
