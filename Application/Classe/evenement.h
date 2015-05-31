#ifndef EVENEMENT_H
#define EVENEMENT_H

#include "QTime"
#include "duree.h"

class Evenement
{
protected:
   Duree duree;
   Evenement(Duree d);
public:

   Duree getDuree() const;
   void setDuree(const Duree & value);
};

#endif // EVENEMENT_H
