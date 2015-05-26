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
   std::vector<Tache *> taches;
   QString id;
   QString titre;
   QDate dateDispo;
   QDate echeance;
   Projet(const QString& identificateur, const QString& ti, const QDate& dispo, const QDate& deadline);
   Projet(const Projet& p);
   Projet& operator=(const Projet& obj);
   ~Projet();

   friend class ProjetManager;
public:

   // influence de l'ajout sur dateDispo ?
   //void ajouterTache(Tache &t);
   TacheComposite * ajouterTache(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);
   TacheUnitaire * ajouterTache(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur, const bool& pre = false);

   //Getters and setters
   QDate& getDisponibilite();
   const QDate& getDisponibilite() const;
   void setDisponibilite(const QDate &value);

   QDate& getEcheance();
   const QDate& getEcheance() const;
   void setEcheance(const QDate &value);

   QString& getID();
   const QString& getID() const;
   void setID(const QString &value);

   QString& getTitre();
   const QString& getTitre() const;
   void setTitre(const QString &value);

   std::vector<Tache *> &getTaches();
   const std::vector<Tache *> &getTaches() const;

    /* Autres fonctions */
   const unsigned int nbTaches() const;

   //pas besoin d'itérateur basique vu qu'on a déjà l'itérateur intégré dans vector
   class DisponibiliteFilterIterator {
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
