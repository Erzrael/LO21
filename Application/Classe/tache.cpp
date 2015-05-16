#include "tache.h"

Tache::Tache(const QString &id, const QString &t, const QDate &dispo, const QDate &deadline):
    identificateur(id),titre(t),disponibilite(dispo),echeance(deadline){
    qDebug()<<"Création d'un objet Tache \n";
}

Tache::Tache(const Tache& t){
    if(this != &t) {
        this->setDisponibilite(t.getDisponibilite());
        this->setEcheance(t.getEcheance());
        this->setIdentificateur(t.getIdentificateur());
        this->setTitre(t.getTitre());
        this->precedence = t.getPrecedence();
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
    if(t.getEcheance() <= this->getEcheance()){
        if(this->getPrecedence().size() == this->getPrecedence().capacity())
            this->getPrecedence().reserve(this->getPrecedence().capacity()+5);
        this->getPrecedence().push_back(&t);
        qDebug()<<"Ajout précédence réussi \n";
    }else{
        qDebug()<<"Ajout précédence failed \n";
    }
}

