#ifndef AGENDA_H
#define AGENDA_H
#include "programmation.h"
#include <vector>

class Agenda
{
private:
   vector <Programmation*> programmations ;
public:
   void ajouterProgrammation(const Tache& t, const QDate& d, const QTime& h);
   Programmation* trouverProgrammation(const Tache& t)const;

};

#endif // AGENDA_H
