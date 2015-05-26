#include "projetManager.h"

ProjetManager::TacheIterator& ProjetManager::TacheIterator::operator++(int){
//    if (*this == this->end() ){
//        throw CalendarException("++ on a ending TacheIterator");
//    }
    if(tacheIterator != (*projetIterator)->getTaches().end()){
        ++tacheIterator;
    } else {
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

Projet *ProjetManager::ajouterProjet(const QString& identificateur, const QString& ti, const QDate &dispo, const QDate &deadline)
{
    Projet *p = new Projet(identificateur, ti, dispo, deadline);
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

const unsigned int ProjetManager::nbProjets() const
{
    return projets.size();
}

ProjetManager::TacheIterator::TacheIterator(vector<Projet *>::iterator it_p, vector<Tache *>::iterator it_t):
    projetIterator(it_p),
    tacheIterator(it_t) {

}

ProjetManager::TacheIterator::TacheIterator(vector<Projet *> p):
    projetIterator(p.begin()),
    tacheIterator((*projetIterator)->getTaches().begin()){
}
