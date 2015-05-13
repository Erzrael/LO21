#ifndef PROJET_H
#define PROJET_H
#include "tache.h"
#include <QDate>
#include <vector>

class Projet
{
private:
   vector<*Tache> taches;
   QDate dateDispo;
   QDate echeance;
public:
   projet():dateDispo(0),echeance(0){}

   // influence de l'ajout sur dateDispo ?
   void ajouterTache(Tache * t);

   //Getters and setters
   QDate getDateDispo() const;
   void setDateDispo(const QDate & value);
   QDate getEcheance() const;
   void setEcheance(const QDate & value);


   //pas besoin d'itérateur basique vu qu'on a déjà l'itérateur intégré dans vector
   class DisponibiliteFilterIterator {
   private:
       friend class Projet;
       vector<*Tache> listeTaches;
       vector<Tache>::iterator tacheIterator;
       QDate dispo;
       DisponibiliteFilterIterator(vector<*Tache> u, const QDate& d):listeTaches(u),tacheIterator(u.begin()),dispo(d){
           while(tacheIterator != listeTache.end() && dispo<(*tacheIterator)->getDisponibilite()){
               tacheIterator ++ ;
           }
       }
   public:
       DisponibiliteFilterIterator():nbRemain(0),currentTache(0){}
       bool isDone() const { return tacheIterator == listeTache.end(); }
       void next() {
           if (isDone())
               throw CalendarException("error, next on an iterator which is done");
           do {
               tacheIterator ++;
           }while(tacheIterator != listeTache.end() && dispo<(*tacheIterator)->getDisponibilite());
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
