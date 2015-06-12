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
   virtual const QString & getID() const = 0;
   Duree getDuree() const;
   void setDuree(const Duree & value);

   virtual void suppressionProgrammation();

};

class EvenementClassique : public Evenement {
protected:
   QString nom;

   EvenementClassique(Duree d, QString nom);
   friend class Agenda;
public:
   // Evenement interface
   const QString &getID() const;
};

#endif // EVENEMENT_H
