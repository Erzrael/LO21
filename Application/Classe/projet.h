#ifndef PROJET_H
#define PROJET_H
#include "tache.h"
#include "tacheComposite.h"
#include "tacheUnitaire.h"
//#include <QDate>
#include <vector>

class Projet
{
private:
   QString id;
   QString titre;
   std::vector<Tache *> taches;
   QDate dateDispo;
   QDate echeance;
   Projet(const QString id_p, const QString ti, const QDate& dispo, const QDate& deadline);
   Projet(const Projet& p);
   Projet& operator=(const Projet& obj);
   ~Projet();

   // influence de l'ajout sur dateDispo ?
   void ajouterTache(Tache &t);

   friend class ProjetManager;
public:

   Tache * ajouterTache(const QString& id, const QString& titre, const QDate& dispo, const QDate& deadline, const Duree &dur = Duree(0), const bool &pre = false);
   Tache *trouverTache(const QString& id); // Nécessetira des dynamics_cast
   const Tache *trouverTache(const QString& id) const;
   void supprimerTache(const QString& id);

   //Getters and setters
   QDate& getDisponibilite();
   const QDate& getDisponibilite() const;
   void setDisponibilite(const QDate &value);

   QDate& getEcheance();
   const QDate& getEcheance() const;
   void setEcheance(const QDate &value);

   std::vector<Tache *> &getTaches();
   const std::vector<Tache *> &getTaches() const;

   QString& getId();
   const QString& getId() const;
   void setId(const QString & value);


   //pas besoin d'itérateur basique vu qu'on a déjà l'itérateur intégré dans vector
   class DisponibiliteFilterIterator {
      //A modifier selon l'Itérator STL (seulement si on a besoin de la classe, car je pense pas, finalement)
   private:
       friend class Projet;
       std::vector<Tache *> listeTaches;
       std::vector<Tache *>::iterator tacheIterator;
       QDate dispo;
       DisponibiliteFilterIterator(vector<Tache *> u, const QDate& d):listeTaches(u),tacheIterator(u.begin()),dispo(d){
           while(tacheIterator != listeTaches.end() && dispo<(*tacheIterator)->getDisponibilite()){
               tacheIterator ++ ;
           }
       }
   public:
       bool isDone() const { return tacheIterator == listeTaches.end(); }
       void next() {
           if (isDone())
               throw CalendarException("error, next on an iterator which is done");
           do {
               tacheIterator ++;
           }while(tacheIterator != listeTaches.end() && dispo<(*tacheIterator)->getDisponibilite());
       }
       Tache& current() const {
           if (isDone())
               throw CalendarException("error, indirection on an iterator which is done");
           return **tacheIterator;
       }
   };
   DisponibiliteFilterIterator getDisponibiliteFilterIterator(const QDate& d) {
       return DisponibiliteFilterIterator(taches,d);
   }
};

#endif // PROJET_H
