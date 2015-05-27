#include "projetManager.h"

ProjetManager* ProjetManager::instanceUnique = 0;

ProjetManager::TacheIterator& ProjetManager::TacheIterator::operator++(int){
//    if (*this == this->end() ){
//        throw CalendarException("++ on a ending TacheIterator");
//    }
    if(tacheIterator != ((*projetIterator)->getTaches().end())--){
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

ProjetManager::~ProjetManager(){
    for(std::vector<Projet *>::iterator it = projets.begin(); it != projets.end(); ++it)
        delete (*it);
    projets.clear();
}

ProjetManager &ProjetManager::getInstance()
{
    static ProjetManager instanceUnique;
    return instanceUnique;
}

Projet *ProjetManager::ajouterProjet(const QString& identificateur, const QString& ti, const QDate &dispo, const QDate &deadline)
{
    /*Si le projet existe déjà
    if (ProjetManager::getInstance().isProjetExistant(identificateur)){
        throw CalendarException("erreur ProjetManager : projet id déjà existant");
        return 0;
    }*/
    Projet *p = new Projet(identificateur, ti, dispo, deadline);
    projets.push_back(p);
    return p;
}
/*
bool ProjetManager::isTacheExistante(const QString &id) const
{
    return trouverTache(id)!=0;
}

bool ProjetManager::isProjetExistant(const QString &id) const
{
    return trouverProjet(id)!=0;
}

Tache &ProjetManager::getTache(const QString &id)
{
    Tache* t = trouverTache(id);
    if (!t)
        throw CalendarException("erreur, ProjetManager, tache inexistante");
    return *t;
}

const Tache& ProjetManager::getTache(const QString& id) const{
    return const_cast<ProjetManager*>(this)->getTache(id);
}

Projet &ProjetManager::getProjet(const QString &id)
{
    Projet* p = trouverProjet(id);
    if (!p)
        throw CalendarException("erreur, ProjetManager, projet inexistant");
    return *p;
}

const Projet &ProjetManager::getProjet(const QString &id) const
{
    return const_cast<ProjetManager*>(this)->getProjet(id);
}


void ProjetManager::supprimerTache(const QString &id)
{
    Tache& t = ProjetManager::getInstance().getTache(id);
    delete &t;
}

void ProjetManager::supprimerProjet(const QString &id)
{
    Projet& p = ProjetManager::getInstance().getProjet(id);
    delete &p;
}

bool ProjetManager::empty() const
{
    ProjetManager &projetManager = ProjetManager::getInstance();

    if(projetManager.projets.empty())
        return true;
    for(std::vector<Projet *>::const_iterator it = projets.begin(); it != projets.end(); ++it)
        if(!((*it)->getTaches().empty()))
            return false;
    return true;
}

Projet* ProjetManager::trouverProjet(const QString &id) const
{
    for(std::vector<Projet *>::const_iterator it = projets.begin(); it != projets.end(); ++it)
        if(id == (*it)->getID())
            return (*it);
    return 0;
}

Tache* ProjetManager::trouverTache(const QString &id) const
{
    ProjetManager &projetManager = ProjetManager::getInstance();

    if(projetManager.empty())
        return 0;
    for(ProjetManager::TacheIterator it = projetManager.tache_begin();it != projetManager.tache_end();it++){
        if(id == (*it)->getIdentificateur())
            return (*it);
    }
    return 0;
}
*/

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
