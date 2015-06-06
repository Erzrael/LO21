#ifndef DUREE_H
#define DUREE_H

#include "calendarException.h"
#include <QString>
#include <QDate>
#include <QTextStream>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>
using namespace std;

/*! \class Duree
        \brief Classe permettant de manipuler des durees
        L'utilisation de cette classe nécessite des durées valides au sens commun du terme.
        D?clenchement d'exception dans le cas contraire
*/
class Duree{
public:
   //! Constructeur à partir de heure et minute
   /*! \param h heure avec h>=0
        \param m minute avec 0<=m<=59
        */
   Duree(unsigned int h, unsigned int m):nb_minutes(h*60+m) {
      if (m>59) throw CalendarException("erreur: initialisation duree invalide");}
   //! Constructeur à partir de minute
   /*! \param m minute avec m>=0
        */
   Duree(unsigned int m=0):nb_minutes(m) {}

   Duree(char * minutes);
   char * toChar();

   void setDuree(unsigned int minutes) { nb_minutes=minutes; }
   void setDuree(unsigned int heures, unsigned int minutes) { if (heures==0 && minutes>59) throw CalendarException("erreur: initialisation duree invalide"); nb_minutes=heures*60+minutes; }
   unsigned int getDureeEnMinutes() const { return nb_minutes; } //<!Retourne la duree en minutes
   double getDureeEnHeures() const { return double(nb_minutes)/60; } //<!Retourne la duree en heures
   unsigned int getMinute() const { return nb_minutes%60; }
   unsigned int getHeure() const { return nb_minutes/60; }
   void afficher(QTextStream& f) const; //<!Affiche la duree sous le format hhHmm
   bool operator<(Duree const& b);

private:

   unsigned int nb_minutes;
};

QTextStream& operator<<(QTextStream& f, const Duree & d);
QTextStream& operator>>(QTextStream&, Duree&); //lecture format hhHmm

#endif // DUREE_H
