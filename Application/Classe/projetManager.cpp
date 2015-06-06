#include "projetManager.h"

// ProjetManager* ProjetManager::instanceUnique = 0;

ProjetManager::TacheIterator& ProjetManager::TacheIterator::operator++(int){
   // qDebug()<<"operator++\n";
   ++tacheIterator;
   if(tacheIterator == ((*projetIterator)->getTaches()).end()){
      //qDebug()<<"++projetIterator\n";
      do {
         ++projetIterator;
         --nb_projets;
      } while (nb_projets > 1 && (*projetIterator)->getTaches().empty());
      if (nb_projets ) {
         tacheIterator = (*projetIterator)->getTaches().begin();
      }
   }
   return *this;
}

bool ProjetManager::TacheIterator::operator==(const ProjetManager::TacheIterator &other) const
{
    if (&other == this || (this->tacheIterator == other.tacheIterator)){
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


vector<Projet *> &ProjetManager::getProjets()
{
    return projets;
}

const vector<Projet *> &ProjetManager::getProjets() const
{
    return projets;
}

ProjetManager::ProjetManager() {}

ProjetManager::~ProjetManager(){
    qDebug()<<"Destruction de ProjetManager";
    
    while(!projets.empty()){/*
        Projet* p = projets.back();
        if(p->getId() != "")*/
            delete projets.back();
        projets.pop_back();
     }
}

ProjetManager &ProjetManager::getInstance()
{
    static ProjetManager instanceUnique;
    return instanceUnique;
}

Projet *ProjetManager::ajouterProjet(const QString& identificateur, const QString& ti, const QDate &dispo, const QDate &deadline)
{
    //Si le projet existe déjà
    if (ProjetManager::getInstance().isProjetExistant(identificateur)){
        throw CalendarException("erreur ProjetManager : projet id déjà existant");
        return 0;
    }
    Projet *p = new Projet(identificateur, ti, dispo, deadline);
    projets.push_back(p);
    return p;
}

Tache *ProjetManager::ajouterTache(const QString & id_projet, const QString & id, const QString & titre, const QDate & dispo, const QDate & deadline, const Duree & dur, const bool & pre)
{
   if (this->trouverTache(id)) {
      throw CalendarException("Erreur AjouterTache : l'id de la tache existe déjà");
   }
   Projet * p = this->trouverProjet(id_projet);
   if ( p == 0 ) {
      throw CalendarException("Erreur AjouterTache : l'id_projet n'existe pas");
   }

   Tache * t = 0;
   if(dur.getDureeEnMinutes() != 0 ) { // si une durée est fixée, la tâche est unitaire
      t = new TacheUnitaire(id,titre,dispo,deadline,dur,pre);
   } else {
      t = new TacheComposite(id,titre,dispo,deadline);
   }
   p->ajouterTache(*t);
   return t;
}

bool ProjetManager::isTacheExistante(const QString &id) const
{
    return trouverTache(id)!=0;
}

bool ProjetManager::isProjetExistant(const QString &id) const
{
    return trouverProjet(id)!=0;
}

Tache* ProjetManager::getTache(const QString &id)
{
    Tache* t = trouverTache(id);
    if (!t)
        throw CalendarException("erreur, ProjetManager, tache inexistante");
    return t;
}

const Tache* ProjetManager::getTache(const QString& id) const{
    return const_cast<ProjetManager*>(this)->getTache(id);
}

Projet *ProjetManager::getProjet(const QString &id)
{
    Projet* p = trouverProjet(id);
    if (!p)
        throw CalendarException("erreur, ProjetManager, projet inexistant");
    return p;
}

const Projet *ProjetManager::getProjet(const QString &id) const
{
    return const_cast<ProjetManager*>(this)->getProjet(id);
}

void ProjetManager::supprimerTache(const QString &id)
{
    Tache* t = ProjetManager::getInstance().getTache(id);
    Projet* p = t->getProjet();
    p->supprimerTache(id);
}

void ProjetManager::supprimerProjet(const QString &id)
{
    /*
    Projet* p = ProjetManager::getInstance().getProjet(id);
    delete p;
    */
    /* Si je veux supprimer un projet, il faut que je supprime le lien dans le vector d'où le code suivant */
    std::vector<Projet *>::iterator it = projets.begin();
    while(id != (*it)->getId() && it != projets.end())
        ++it;
    if(id == (*it)->getId()){
        delete *it;
        projets.erase(it);
    }
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
        if(id == (*it)->getId())
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

ProjetManager::TacheIterator ProjetManager::tache_begin()
{
    return ProjetManager::TacheIterator(projets);
}

ProjetManager::TacheIterator ProjetManager::tache_end()
{
    if(projets.empty()){
       return ProjetManager::TacheIterator(projets.size(), vector<Projet *>::iterator(), vector<Tache *>::iterator());
    } else {
       vector<Projet *>::iterator it = projets.end();
       --it;
       return ProjetManager::TacheIterator(projets.size(), it, (*it)->getTaches().end());
    }
}

unsigned int ProjetManager::nbProjets() const
{
    return projets.size();
}

ProjetManager::TacheIterator::TacheIterator(unsigned int size, vector<Projet *>::iterator it_p, vector<Tache *>::iterator it_t):
    nb_projets(size), projetIterator(it_p),
    tacheIterator(it_t) {

}

ProjetManager::TacheIterator::TacheIterator(vector<Projet *> & p):
    nb_projets(p.size()), projetIterator(p.begin()){
   if(nb_projets == 0){
//      vector<Tache *> t;
      tacheIterator = vector<Tache *>::iterator();
   }else{
      while (nb_projets != 0 && (*projetIterator)->getTaches().empty()) {
         ++projetIterator;
         --nb_projets;
      }
      tacheIterator = (*projetIterator)->getTaches().begin();
   }
   //qDebug()<<"TacheIterator"<<*projetIterator<<","<<*tacheIterator<<"\n";
}
