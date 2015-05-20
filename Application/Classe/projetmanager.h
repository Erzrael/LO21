#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H
#include <vector>
#include "projet.h"
#include "tache.h"

class ProjetManager
{
private:
   static ProjetManager * instanceUnique;
   vector<Projet *> projets;

   //DesignPattern Singleton
   ProjetManager();
   ~ProjetManager();
   ProjetManager(const ProjetManager & foo);
   ProjetManager & operator=(const ProjetManager & foo);
public:
   static ProjetManager &getInstance();

   Projet * ajouterProjet(const QString & id_p, const QDate& dispo, const QDate& deadline);
   Tache * ajouterTache(const QString & id_projet, const QString& id, const QString& titre, const QDate& dispo, const QDate& deadline, const Duree &dur = Duree(0), const bool &pre = false);

   class TacheIterator{
   private:
      unsigned int nb_projets;
      vector<Projet *>::iterator projetIterator;
      vector<Tache *>::iterator tacheIterator;

      //Le tacheIterator est initialisé avec l'itérator du premier projet de ProjetManager
      TacheIterator(vector<Projet *> & p);
      TacheIterator(unsigned int size, vector<Projet *>::iterator it_p, vector<Tache *>::iterator it_t);
      friend class ProjetManager;
   public:
      TacheIterator& end();
      TacheIterator& operator++(int);
      bool operator==(const TacheIterator &other) const;
      bool operator!=(const TacheIterator &other) const;
      Tache* operator*() const;
   };
   TacheIterator tache_begin();
   TacheIterator tache_end();


   Projet * trouverProjet(const QString & id);
   Tache * trouverTache(const QString & id);

   vector<Projet *> getProjets() const;
   void setProjets(const vector<Projet *> & value);
};

#endif // PROJETMANAGER_H
