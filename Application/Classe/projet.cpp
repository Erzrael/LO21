#include "tache.h"
#include "tacheComposite.h"
#include "tacheUnitaire.h"
#include "projet.h"

Projet::Projet(const QString &identificateur, const QString &ti, const QDate &dispo, const QDate &deadline):
    dateDispo(dispo), echeance(deadline), id(identificateur), titre(ti) {
    qDebug()<<"Création d'un objet Projet \n";
}

Projet::Projet(const Projet &p)
{
    if(this != &p) {
        this->setID(p.getID());
        this->setTitre(p.getTitre());
        this->setDisponibilite(p.getDisponibilite());
        this->setEcheance(p.getEcheance());
        this->taches = getTaches();
    }
}

Projet &Projet::operator=(const Projet &obj)
{
    if(this != &obj)
    {
        this->setID(obj.getID());
        this->setTitre(obj.getTitre());
        this->setDisponibilite(obj.getDisponibilite());
        this->setEcheance(obj.getEcheance());
        this->taches = obj.getTaches();
    }
    return *this;
}

Projet::~Projet()
{
    qDebug()<<"Destruction d'un objet Projet";
}

/*void Projet::ajouterTache(Tache &t)
{
   // l'échéance du projet est repoussée si nécessaire
   if(t.getEcheance() > this->getEcheance()){
      echeance = t.getEcheance();
   }
   //la tache est ajoutée au projet
   taches.push_back(&t);
}*/

TacheComposite * Projet::ajouterTache(const QString& id, const QString& titre, const QDate& dispo, const QDate& deadline){
    // Si la tâche fait déjà partie du projet
    std::vector<Tache *>::const_iterator it = taches.begin();

    while(it != taches.end()){
        if((*it)->getIdentificateur() == id){
            qDebug()<<"La tâche existe déjà";
            return 0;
        }
        it++;
    }
    // l'échéance du projet est repoussée si nécessaire
    if(deadline > this->echeance){
        qDebug()<<"Echéance du projet repoussée";
        this->echeance = deadline;
    }
    //la tache est ajoutée au projet
    qDebug()<<"Création + ajout Tache au projet";
    TacheComposite * t = new TacheComposite(id,titre,dispo,deadline);
    taches.push_back(t);
    return t;
}

TacheUnitaire *Projet::ajouterTache(const QString &id, const QString &titre, const QDate &dispo, const QDate &deadline, const Duree &dur, const bool &pre)
{
    // Si la tâche fait déjà partie du projet
    std::vector<Tache *>::const_iterator it = taches.begin();

    while(it != taches.end()){
        if((*it)->getIdentificateur() == id){
            qDebug()<<"La tâche existe déjà";
            return 0;
        }
        it++;
    }
    // l'échéance du projet est repoussée si nécessaire
    if(deadline > this->echeance){
        qDebug()<<"Echéance du projet repoussée";
        this->echeance = deadline;
    }
    //la tache est ajoutée au projet
    qDebug()<<"Création + ajout Tache au projet";
    TacheUnitaire * t = new TacheUnitaire(id,titre,dispo,deadline,dur,pre);
    taches.push_back(t);
    return t;
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

const unsigned int Projet::nbTaches() const
{
    return taches.size();
}

QString& Projet::getID(){
    return id;
}

const QString& Projet::getID() const{
    return id;
}

void Projet::setID(const QString &value){
    id = value;
}

QString& Projet::getTitre(){
    return id;
}

const QString& Projet::getTitre() const{
    return id;
}

void Projet::setTitre(const QString &value){
    id = value;
}

Projet::DisponibiliteFilterIterator::DisponibiliteFilterIterator(vector<Tache *> u, const QDate &d)
    :listeTaches(u),tacheIterator(u.begin()),dispo(d){
    while(tacheIterator != listeTaches.end() && dispo < (*tacheIterator)->getDisponibilite()){
       tacheIterator ++ ;
    }
}

void Projet::DisponibiliteFilterIterator::next()
{
    if (isDone())
        throw CalendarException("error, next on an iterator which is done");
    do {
        tacheIterator ++;
    }while(tacheIterator != listeTaches.end() && dispo<(*tacheIterator)->getDisponibilite());
}
