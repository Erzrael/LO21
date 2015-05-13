#ifndef PROJET_H
#define PROJET_H
#include "tache.h"
//#include <QDate>
#include <vector>

class Projet
{
private:
   std::vector<Tache *> taches;
   QDate dateDispo;
   QDate echeance;
public:
//   Projet():dateDispo(0),echeance(QDate(0,0,0)){}

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
