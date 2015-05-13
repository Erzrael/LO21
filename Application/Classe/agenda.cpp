#include "agenda.h"

Programmation* Agenda::trouverProgrammation(const Tache& t)const{
   std::vector<Programmation *>::const_iterator it ;
    for(it = programmations.begin(); it != programmations.end() ; ++it)
        if (&t==(*it)->getTache())
           return *it;
    return 0;
}

std::vector<Programmation *> &Agenda::getProgrammation()
{
   return programmations;
}

const std::vector<Programmation *> &Agenda::getProgrammation() const
{
   return programmations;
}

void Agenda::ajouterProgrammation(const Tache& t, const QDate& d, const QTime& h){
    if (trouverProgrammation(t)) throw CalendarException("erreur, ProgrammationManager, Programmation deja existante");
    Programmation* newt=new Programmation(t,d,h);
    programmations.push_back(newt);
}
