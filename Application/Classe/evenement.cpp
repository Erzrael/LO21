#include "evenement.h"


Evenement::Evenement(Duree d) : duree(d){}

Duree Evenement::getDuree() const
{
   return duree;
}

void Evenement::setDuree(const Duree & value)
{
   duree = value;
}
