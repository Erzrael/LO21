#include "projet.h"
#include "projetManager.h"


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
       /* C'est moche, mais je ne sais pas comment faire autrement... */
       Tache* t = taches.back();
       if(t->getIdentificateur() != "")
           delete taches.back();
       taches.pop_back();
    }
}

Tache *Projet::ajouterTache(const QString & id, const QString & titre, const QDate & dispo, const QDate & deadline, const Duree & dur, const bool & pre)
{
   ProjetManager & pm = ProjetManager::getInstance();
   return pm.ajouterTache(this->getId(), id, titre, dispo, deadline, dur, pre);
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
