#ifndef EVENEMENT_H
#define EVENEMENT_H

#include "QTime"
#include "duree.h"

class Evenement
{
protected:
   Duree duree;
   Evenement(Duree d);

   ~Evenement();
public:
   virtual const QString & getID() const;
   Duree getDuree() const;
   void setDuree(const Duree & value);

   virtual void suppressionProgrammation();

};

#endif // EVENEMENT_H
