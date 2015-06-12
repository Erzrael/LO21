#include "evenement.h"


Evenement::Evenement(Duree d) : duree(d){}

Evenement::~Evenement()
{

}

const QString & Evenement::getID() const
{
   static QString braou("Evènement ponctuel");
   return braou ;
}

Duree Evenement::getDuree() const
{
   return duree;
}

void Evenement::setDuree(const Duree & value)
{
   duree = value;
}

void Evenement::suppressionProgrammation()
{
   this->~Evenement();
}
