#include "tache.h"
#include <Classe/projet.h>
#include <Classe/projetManager.h>

const std::vector<Tache *> &Tache::getMere() const
{
    return mere;
}

std::vector<Tache *> &Tache::getMere()
{
    return mere;
}

Tache::Tache(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline):
    identificateur(id),titre(t),disponibilite(dispo),echeance(deadline), mere_compo(0){
    qDebug()<<"Création d'un objet Tache \n";
}

Tache::Tache(const Tache& t){
    if(this != &t) {
        this->setDisponibilite(t.getDisponibilite());
        this->setEcheance(t.getEcheance());
        this->setIdentificateur(t.getIdentificateur());
        this->setTitre(t.getTitre());
        this->precedence = t.getPrecedence();
        this->mere = t.getMere();
        this->setMere_Compo(t.getMere_Compo());
    }
}

Tache& Tache::operator=(const Tache& obj){
    if(this != &obj)
    {
        this->setDisponibilite(obj.getDisponibilite());
        this->setEcheance(obj.getEcheance());
        this->setIdentificateur(obj.getIdentificateur());
        this->setTitre(obj.getTitre());
        this->precedence = obj.getPrecedence();
        this->mere = obj.getMere();
        this->setMere_Compo(obj.getMere_Compo());
    }
    return *this;
}

Tache::~Tache(){
    qDebug()<<"Destruction d'un objet Tache\n";
}

QString &Tache::getIdentificateur()
{
    return identificateur;
}

const QString &Tache::getIdentificateur() const
{
    return identificateur;
}

void Tache::setIdentificateur(const QString &value)
{
    if (ProjetManager::getInstance().isTacheExistante(value))
        throw CalendarException("erreur ProjetManager : tache id déjà existante");
    identificateur = value;
}

QString &Tache::getTitre()
{
    return titre;
}

const QString &Tache::getTitre() const
{
    return titre;
}

void Tache::setTitre(const QString &value)
{
    titre = value;
}

QDate &Tache::getDisponibilite()
{
    return disponibilite;
}

const QDate &Tache::getDisponibilite() const
{
    return disponibilite;
}

void Tache::setDisponibilite(const QDate &value)
{
    disponibilite = value;
}

QDate &Tache::getEcheance()
{
    return echeance;
}

const QDate &Tache::getEcheance() const
{
    return echeance;
}

void Tache::setEcheance(const QDate &value)
{
    if(this->getMere().empty()){
        if(value < this->getDisponibilite())
            throw CalendarException("La date d'échéance voulue n'est pas correct vis à vis de la disponibilité");
    } else {
        QDate temp(9999,12,31);
        for(std::vector<Tache*>::const_iterator it_precedence = this->getMere().begin(); it_precedence != this->getMere().end(); ++it_precedence){
            if(temp > (*it_precedence)->getEcheance())
                temp = (*it_precedence)->getEcheance();
        }

        if(temp < value)
            throw CalendarException("La date d'échéance voulue n'est pas correct vis à vis des précédences");
    }

    TacheComposite* Composite = dynamic_cast<TacheComposite*>(this);

    if(Composite){
        if(value > Composite->getMere_Compo()->getEcheance())
            throw CalendarException("La date d'échéance voulue n'est pas correct vis à vis des compositions");
    }

    // Si on arrive ici, c'est qu'aucun problème n'a été détecté.
    echeance = value;
}

std::vector<Tache*>& Tache::getPrecedence()
{
    return precedence;
}

const std::vector<Tache*>& Tache::getPrecedence() const
{
    return precedence;
}

Tache *Tache::getMere_Compo() const
{
    return mere_compo;
}

void Tache::setMere_Compo(Tache *value)
{
    mere_compo = value;
}

void Tache::ajouterPrecedence(Tache &t)
{
    if(this->verifierPrecedence(t)){
        this->getPrecedence().push_back(&t);
        t.getMere().push_back(this);
        qDebug()<<"Ajout précédence réussi \n";
    }else{
        qDebug()<<"Ajout précédence failed \n";
        throw CalendarException("Une tache ne peut pas avoir une tache parente en prérequis");
    }
}

bool Tache::verifierPrecedence(Tache &t) const
{
    // On vérifie que l'on ajoute pas une même tâche en précédence d'elle-même
    if(this == &t){
        qDebug()<<"Je retourne faux";
        return false;
    }
    // On vérifie que les dates d'échéances correspondent
    if(t.getEcheance() > this->getEcheance()){
        qDebug()<<"Je retourne faux";
        return false;
    }
    // On vérifie que t ne fait pas déjà partie des précédences existantes
    for(std::vector<Tache*>::const_iterator it_prece = this->getPrecedence().begin(); it_prece != this->getPrecedence().end(); ++it_prece)
        if((*it_prece)->getIdentificateur() == t.getIdentificateur()){
            qDebug()<<"Je retourne faux";
            return false;
        }

    // Vérifier pour les taches composites
    TacheComposite* Compo = dynamic_cast<TacheComposite*>(&t);

    if(Compo){
        for(std::vector<Tache*>::const_iterator it = Compo->getComposition().begin(); it != Compo->getComposition().end(); ++it){
            if(!verifierPrecedence(**it))
                return false;
        }
    }

    // On vérifie la même chose pour les taĉhes précédentes mères de this et en prenant compte du cas des compositions
    std::vector<Tache*> tache_mere = this->getMere();

    for(std::vector<Tache*>::const_iterator it = tache_mere.begin(); it != tache_mere.end(); ++it){
        TacheComposite* item = dynamic_cast<TacheComposite*>(*it);

        if(item){
            for(std::vector<Tache*>::const_iterator it_compo = item->getComposition().begin(); it_compo != item->getComposition().end(); ++it_compo)
                if(!(*it)->verifierPrecedence(t))
                    return false;
        }

        if(!(*it)->verifierPrecedence(t))
            return false;

    }

    // Si on sort de la boucle, cela veut dire que tout est bon
    return true;
}


void Tache::supprimerPrecedence(const QString &id)
{
    std::vector<Tache*>::iterator iterator_precedence = this->getPrecedence().begin();

    while(iterator_precedence != this->getPrecedence().end() && (*iterator_precedence)->getIdentificateur() != id){
        ++iterator_precedence;
    }

    if(iterator_precedence != this->getPrecedence().end()){
        std::vector<Tache*>::iterator it_mere_prece = (*iterator_precedence)->getMere().begin();
        bool suppression = false;
        while((it_mere_prece != (*iterator_precedence)->getMere().end()) && !suppression){

            if((*it_mere_prece)->getIdentificateur() == this->getIdentificateur()){
                (*iterator_precedence)->getMere().erase(it_mere_prece);
                suppression = true;
            }
        }

        this->getPrecedence().erase(iterator_precedence);
    } else
        throw CalendarException("La précédence n'a pas été supprimée");
}

unsigned int Tache::nbPrerequis() const
{
    return precedence.size();
}

Tache *Tache::getPere()
{
    ProjetManager& projetManager = ProjetManager::getInstance();
    std::vector<Projet *>::const_iterator it_projets = projetManager.getProjets().begin();

    while((it_projets != projetManager.getProjets().end()) && (((*it_projets)->trouverTache(this->getIdentificateur())) == 0))
        ++it_projets;

    if(it_projets == projetManager.getProjets().end())
        return 0;

    std::vector<Tache *>::const_iterator it_taches = (*it_projets)->getTaches().begin();

    while(it_taches != (*it_projets)->getTaches().end()){
        TacheComposite* composite = dynamic_cast<TacheComposite*>(*it_taches);
        if(composite != 0){
            std::vector<Tache *>::const_iterator it_compo = composite->getComposition().begin();

            while(it_compo != composite->getComposition().end()){
                if(this->getIdentificateur() == (*it_compo)->getIdentificateur())
                    return composite;
                ++it_compo;
            }
        }
        ++it_taches;
    }
    return 0;
}

Projet* Tache::getProjet()
{
    ProjetManager& projetManager = ProjetManager::getInstance();
    std::vector<Projet *>::iterator it_projets = projetManager.getProjets().begin();
    while((it_projets != projetManager.getProjets().end()) && ((*it_projets)->trouverTache(this->getIdentificateur()) == 0)){
        ++it_projets;
    }

    if(it_projets != projetManager.getProjets().end())
        return *it_projets;
    else
        return 0;
}
