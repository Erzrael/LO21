#include "agenda.h"

Programmation* Agenda::trouverProgrammation(const Tache& t)const{
    for(vector<*Tache>::iterator it = programmations.begin(); it!=v.end(); ++it)
        if (&t==*it->getTache()) return *it;
    return 0;
}

void Agenda::ajouterProgrammation(const Tache& t, const QDate& d, const QTime& h){
    if (trouverProgrammation(t)) throw CalendarException("erreur, ProgrammationManager, Programmation deja existante");
    Programmation* newt=new Programmation(t,d,h);
    programmations.push_back(newt);
}
