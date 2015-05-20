#include "projetmanager.h"
#include <QDebug>

ProjetManager::TacheIterator& ProjetManager::TacheIterator::operator++(int){
   // qDebug()<<"operator++\n";
   ++tacheIterator;
   if(tacheIterator == ((*projetIterator)->getTaches()).end()){
      //qDebug()<<"++projetIterator\n";
      do {
         ++projetIterator;
         --nb_projets;
      } while (nb_projets != 0 && (*projetIterator)->getTaches().empty());
      if (nb_projets == 0){
         tacheIterator = vector<Tache *>::iterator();
      } else{
         tacheIterator = (*projetIterator)->getTaches().begin();
      }
   }
   return *this;
}

bool ProjetManager::TacheIterator::operator==(const ProjetManager::TacheIterator &other) const
{
    if (&other == this || this->tacheIterator == other.tacheIterator){
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

vector<Projet *> ProjetManager::getProjets() const
{
   return projets;
}

void ProjetManager::setProjets(const vector<Projet *> & value)
{
   projets = value;
}
ProjetManager::ProjetManager() {}

ProjetManager::~ProjetManager() {}

ProjetManager &ProjetManager::getInstance()
{
   static ProjetManager instanceUnique;
    return instanceUnique;
}

Projet *ProjetManager::ajouterProjet(const QString & id_p, const QDate &dispo, const QDate &deadline)
{
   if (this->trouverProjet(id_p)) {
      throw CalendarException("Erreur ajouterProjet : l'id du projet est déjà utilisé !");
   }
   Projet *p = new Projet(id_p, dispo, deadline);
   projets.push_back(p);
   return p;
}

Tache *ProjetManager::ajouterTache(const QString & id_projet, const QString & id, const QString & titre, const QDate & dispo, const QDate & deadline, const Duree & dur, const bool & pre)
{
   if (this->trouverTache(id)) {
      throw CalendarException("Erreur AjouterTache : l'id de la tache existe déjà");
   }
   Projet * p = this->trouverProjet(id_projet);
   if ( p == NULL ) {
      throw CalendarException("Erreur AjouterTache : l'id_projet n'existe pas");
   }

   Tache * t = NULL;
   if(dur.getDureeEnMinutes() != 0 ) { // si une durée est fixée, la tâche est unitaire
      t = new TacheUnitaire(id,titre,dispo,deadline,dur,pre);
   } else {
      t = new TacheComposite(id,titre,dispo,deadline);
   }
   p->ajouterTache(*t);
   return t;
}

ProjetManager::TacheIterator ProjetManager::tache_begin()
{
    return ProjetManager::TacheIterator(projets);
}

ProjetManager::TacheIterator ProjetManager::tache_end()
{
    vector<Projet *>::iterator it = projets.end();
    --it;
    return ProjetManager::TacheIterator(projets.size(), it, (*it)->getTaches().end());
}

Projet *ProjetManager::trouverProjet(const QString & id)
{
   for(vector<Projet *>::iterator it = projets.begin() ; it != projets.end() ; ++it ){
      if((*it)->id == id){
         return *it;
      }
   }
   return NULL;
}

Tache *ProjetManager::trouverTache(const QString & id)
{
   for(ProjetManager::TacheIterator it = this->tache_begin() ; it != this->tache_end() ; it++ ){
      if ((*it)->getIdentificateur() == id ){
         return *it;
      }
   }
   return NULL;
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
      tacheIterator = (*projetIterator)->getTaches().begin();
   }
   //qDebug()<<"TacheIterator"<<*projetIterator<<","<<*tacheIterator<<"\n";
}
