#include "projet.h"
#include "projetManager.h"


QString Projet::getId() const
{
    return id;
}

void Projet::setId(const QString & value)
{
    id = value;
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
   if(!taches.empty()){
       for(std::vector<Tache *>::iterator it = taches.begin(); it != taches.end(); ++it){
            delete (*it);
            it = taches.erase(it);
       }
       taches.clear();
   }
}

Tache *Projet::ajouterTache(const QString & id, const QString & titre, const QDate & dispo, const QDate & deadline, const Duree & dur, const bool & pre)
{
   ProjetManager & pm = ProjetManager::getInstance();
   pm.ajouterTache(this->getId(), id, titre, dispo, deadline, dur, pre);
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

std::vector<Tache *> &Projet::getTaches()
{
    return taches;
}

const std::vector<Tache *> &Projet::getTaches() const
{
    return taches;
}
