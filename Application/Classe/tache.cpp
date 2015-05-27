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
    identificateur(id),titre(t),disponibilite(dispo),echeance(deadline), mere(0){
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

unsigned int Tache::nbPrerequis() const
{
    return precedence.size();
}
