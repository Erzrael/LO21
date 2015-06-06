#include "tache.h"
#include <Classe/projet.h>
#include <Classe/projetManager.h>

Tache *Tache::getMere() const
{
    return mere;
}

void Tache::setMere(Tache *value)
{
    mere = value;
}

Tache::Tache(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline):
    identificateur(id),titre(t),disponibilite(dispo),echeance(deadline), mere(0), mere_compo(0){
    qDebug()<<"Création d'un objet Tache \n";
}

Tache::Tache(const Tache& t){
    if(this != &t) {
        this->setDisponibilite(t.getDisponibilite());
        this->setEcheance(t.getEcheance());
        this->setIdentificateur(t.getIdentificateur());
        this->setTitre(t.getTitre());
        this->precedence = t.getPrecedence();
        this->setMere(t.getMere());
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
        this->setMere(obj.getMere());
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
        t.setMere(this);
        qDebug()<<"Ajout précédence réussi \n";
    }else{
        qDebug()<<"Ajout précédence failed \n";
        throw CalendarException("Une tache ne peut pas avoir une tache parente en prérequis");
    }
}

bool Tache::verifierPrecedence(const Tache &t) const
{
    if(this == &t){
        qDebug()<<"Je retourne faux";
        return false;
    } else if(t.getEcheance() > this->getEcheance()){
        qDebug()<<"Je retourne faux";
        return false;
    } else if(t.getMere_Compo() != 0){
        qDebug()<<"Je retourne faux";
        return false;
    } else {
        Tache* tache_mere = this->getMere();
            while(tache_mere != 0)
            {
                if(tache_mere == &t)
                    return false;

                tache_mere = tache_mere->getMere();
            }
            return true;
    }
}

bool Tache::verifierComposition(const Tache &t) const
{
    if(this == &t){
        qDebug()<<"Je retourne faux";
        return false;
    } else if(t.getEcheance() > this->getEcheance()){
        qDebug()<<"Je retourne faux";
        return false;
    } else if(t.getMere_Compo() != 0){
        qDebug()<<"Je retourne faux";
        return false;
    } else {
        Tache* tache_mere = this->getMere_Compo();
            while(tache_mere != 0)
            {
                if(tache_mere == &t)
                    return false;

                tache_mere = tache_mere->getMere_Compo();
            }
            return true;
    }
}

unsigned int Tache::nbPrerequis() const
{
    return precedence.size();
}

Tache *Tache::getPere() //Problème dans getPere
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
