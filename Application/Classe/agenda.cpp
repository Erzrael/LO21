#include "agenda.h"
/**
 * \brief Renvoie l'adresse de la programmation associée à une tâche
 * \details Cette fonction utilise l'itérator natif de vector pour parcourir le vector de pointeur de Programmation.
 * Cette fonction est notamment utilisée afin de vérifier l'existence ou non de la programmation associée à une tâche.
 * 
 * \param t Tâche dont on veut trouver la programmation
 * \return L'adresse de la programmation
 * \return 0 en cas d'échec (la tâche n'est pas encore programmée)
 */
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
/**
 * \TODO faire attention à ce que deux programmations ne puissent pas se chevaucher
 * 
 * \brief Associe une programmation à une tâche passée en argument
 * \details Vérifie si la tâche n'est pas encore programmée, auquel cas lance une exception.
 * 
 * \param t Tache que l'on veut programmer
 * \param d Date à laquelle la tache sera programmée
 * \param h Heure à laquelle la tache sera programmée
 */
void Agenda::ajouterProgrammation(const Tache& t, const QDate& d, const QTime& h){
    if (trouverProgrammation(t)) throw CalendarException("erreur, ProgrammationManager, Programmation deja existante");
    programmations.push_back(new Programmation(t,d,h));
}
