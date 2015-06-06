#ifndef AGENDA_H
#define AGENDA_H
#include "programmation.h"
#include "tacheUnitaire.h"
#include "QDate"
#include <list>

class Agenda
{
private:
   list<Programmation*> programmations ;

   // design pattern singleton
   Agenda();
   ~Agenda();
   Agenda(const Agenda & foo);
   Agenda & operator=(const Agenda & foo);

public:
   class IteratorJournee{
   private:
      QDate journee;
      list<Programmation *>::iterator it_programmation;
      list<Programmation *>::iterator end;

      IteratorJournee(QDate j, list<Programmation *> & p);
      IteratorJournee(QDate j, list<Programmation *>::iterator it_programmation, list<Programmation *>::iterator end);
      friend class Agenda;
   public:
      IteratorJournee& operator++(int);
      bool operator==(const IteratorJournee &other) const;
      bool operator!=(const IteratorJournee &other) const;
      Programmation* operator*() const;
   };
   IteratorJournee itJ_begin(QDate journee);
   IteratorJournee itJ_end(QDate journee);

   static Agenda &getInstance();



   void ajouterProgrammation(const TacheUnitaire & t, const QDate& d, const QTime& h);
   Programmation* trouverProgrammation(const TacheUnitaire & t)const;

   std::list<Programmation *> & getProgrammation();
   const std::list<Programmation *> & getProgrammation() const;

};

#endif // AGENDA_H
