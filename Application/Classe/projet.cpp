#include "projet.h"
#include "projetManager.h"
#include "agenda.h"


QString &Projet::getId(){
    return id;
}

const QString &Projet::getId() const
{
    return id;
}

void Projet::setId(const QString & value)
{
    if (ProjetManager::getInstance().isProjetExistant(value))
        throw CalendarException("erreur ProjetManager : projet id déjà existante");
    id = value;
}

QString & Projet::getTitre()
{
    return titre;
}

const QString & Projet::getTitre() const
{
    return titre;
}

void Projet::setTitre(const QString &value)
{
    titre = value;
}

Projet::Projet(const QString id_p, const QString ti, const QDate &dispo, const QDate &deadline):
    id(id_p), titre(ti), dateDispo(dispo), echeance(deadline) {
    qDebug()<<"Création d'un objet Projet \n";
}

Projet::Projet(const Projet &p)
{
    if(this != &p) {
        this->setDisponibilite(p.getDisponibilite());
        this->setEcheance(p.getEcheance());
        this->taches = getTaches();
    }
}

Projet &Projet::operator=(const Projet &obj)
{
    if(this != &obj)
    {
        this->setDisponibilite(obj.getDisponibilite());
        this->setEcheance(obj.getEcheance());
        this->taches = obj.getTaches();
    }
    return *this;
}

Projet::~Projet() {
   qDebug()<<"Destruction d'un objet Projet";

   while(!taches.empty()){
       Tache* t = taches.back();      
       this->supprimerTache(t->getIdentificateur());
    }
}

void Projet::ajouterTache(Tache &t)
{
   // l'échéance du projet est repoussée si nécessaire
   if(t.getEcheance() > this->getEcheance()){
      echeance = t.getEcheance();
   }
   //la tache est ajoutée au projet
   taches.push_back(&t);
}

QDate& Projet::getEcheance()
{
   return echeance;
}

const QDate& Projet::getEcheance() const
{
   return echeance;
}

void Projet::setEcheance(const QDate &value)
{
   echeance = value;
}

QDate& Projet::getDisponibilite()
{
   return dateDispo;
}

const QDate& Projet::getDisponibilite() const
{
   return dateDispo;
}

void Projet::setDisponibilite(const QDate &value)
{
   dateDispo = value;
}

const std::vector<Tache *> &Projet::getTaches() const
{
    return taches;
}

Tache* Projet::trouverTache(const QString &id)
{
    if(this->getTaches().empty())
        return 0;
    else {
        for(std::vector<Tache*>::const_iterator it = this->getTaches().begin(); it != this->getTaches().end(); ++it)
        {
            if(id == (*it)->getIdentificateur())
                return (*it);
        }
    }
    return 0;
}

const Tache* Projet::trouverTache(const QString& id) const{
    return trouverTache(id);
}

void Projet::supprimerTache(const QString &id)
{
    // Recherche de la tâche à supprimer dans le vector<Tache*> de projet
    std::vector<Tache *>::iterator it_taches = taches.begin();
    while(id != (*it_taches)->getIdentificateur() && it_taches != taches.end())
        ++it_taches;

    // On recherche le père de la tâche à supprimer
    if(it_taches != taches.end()){
        TacheComposite* Pere = dynamic_cast<TacheComposite*>((*it_taches)->getPere());
        // Si le père est une tâche composite, il faut supprimer le lien de composition
        if(Pere != 0){
            std::vector<Tache *>::iterator it_compo = Pere->getComposition().begin();
            while((*it_compo)->getIdentificateur() != id)
                ++it_compo;
            Pere->getComposition().erase(it_compo);
        }

        // Pour chaque tache précédente père, on parcourt le vector<Tache*> de précédence
        // et quand les IDs sont les mêmes, on supprime le lien.
        std::vector<Tache*>::iterator it_prece = (*it_taches)->getMere().begin();
        while(it_prece != (*it_taches)->getMere().end()){
            std::vector<Tache*>::iterator it_prece_pere = (*it_prece)->getPrecedence().begin();
            while(it_prece_pere != (*it_prece)->getPrecedence().end()){
                if((*it_prece_pere)->getIdentificateur() == id)
                    (*it_prece)->getPrecedence().erase(it_prece_pere);
                else
                    ++it_prece_pere;
            }
            ++it_prece;
        }

        TacheComposite* A_supprimer = dynamic_cast<TacheComposite*>(*it_taches);

        // Si la tâche à supprimer est une tâche composite, il faut supprimer chacune de ses tâches filles
        if(A_supprimer != 0){
            std::vector<Tache *>::iterator it_compo = A_supprimer->getComposition().begin();
            while(it_compo != A_supprimer->getComposition().end()){
                this->supprimerTache((*it_compo)->getIdentificateur());
            }
        }

        // Enfin, on supprime la tâche finale
        delete *it_taches;
        taches.erase(it_taches);
    } else {
        throw CalendarException("La tâche n'existe pas");
    }
}
