#include "projetmanager.h"
#include <QDebug>

ProjetManager::TacheIterator& ProjetManager::TacheIterator::operator++(int){
  // qDebug()<<"operator++\n";
   ++tacheIterator;
   if(tacheIterator == ((*projetIterator)->getTaches()).end()){
       //qDebug()<<"++projetIterator\n";
        ++projetIterator;
        tacheIterator = (*projetIterator)->getTaches().begin();
    }
    return *this;
}

bool ProjetManager::TacheIterator::operator==(const ProjetManager::TacheIterator &other) const
{
    if (&other == this || (this->projetIterator == other.projetIterator && this->tacheIterator == other.tacheIterator)){
        return true;
    } else{
        return false;
    }
}

bool ProjetManager::TacheIterator::operator!=(const ProjetManager::TacheIterator &other) const
{
    return !(*this == other);
}

Tache* ProjetManager::TacheIterator::operator*() const{
    return *tacheIterator;
}


ProjetManager::ProjetManager() {}

ProjetManager::~ProjetManager() {}

ProjetManager &ProjetManager::getInstance()
{
    static ProjetManager instanceUnique;
    return instanceUnique;
}

Projet *ProjetManager::ajouterProjet(const QDate &dispo, const QDate &deadline)
{
    Projet *p = new Projet(dispo,deadline);
    projets.push_back(p);
    return p;
}

ProjetManager::TacheIterator ProjetManager::tache_begin()
{
    return ProjetManager::TacheIterator(projets);
}

ProjetManager::TacheIterator ProjetManager::tache_end()
{
    vector<Projet *>::iterator it = projets.end();
    --it;
    return ProjetManager::TacheIterator(it, (*it)->getTaches().end());
}

ProjetManager::TacheIterator::TacheIterator(vector<Projet *>::iterator it_p, vector<Tache *>::iterator it_t):
    projetIterator(it_p),
    tacheIterator(it_t) {

}

ProjetManager::TacheIterator::TacheIterator(vector<Projet *> & p):
    projetIterator(p.begin()),
    tacheIterator((*projetIterator)->getTaches().begin()){
   //qDebug()<<"TacheIterator"<<*projetIterator<<","<<*tacheIterator<<"\n";
}
