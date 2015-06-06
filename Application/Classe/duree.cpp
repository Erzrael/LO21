#include "duree.h"
#include <cmath>
#include <string>
#include <stdio.h>

QTextStream& operator<<(QTextStream& f, const Duree & d){ d.afficher(f); return f; }

QTextStream& operator>>(QTextStream& flot, Duree& duree){
   unsigned int h,m;
   bool ok=true;
   flot>>h;
   if (flot.status()!=QTextStream::Ok) ok=false;

   if(flot.read(1)=="H") {
      flot>>m;
      if (flot.status()!=QTextStream::Ok) ok=false;
   }
   else {
      ok=false;
   }
   if (ok) duree=Duree(h,m);
   return flot;
}

Duree::Duree(char * minutes) : nb_minutes( atoi(minutes) )
{
   /*nb_minutes = 0;
   for (unsigned int i = 0 ; i < 5 ; i++ ) {
      int a = minutes[i] - '0';
      // qDebug() << "minute[" << i << "] = " << a ;
      nb_minutes += a * static_cast<int>( pow(10, (4 - i) ) );
   }*/

}

char * Duree::toChar() {
   char * buffer = static_cast<char *> (malloc( 10 * sizeof(char) ));
   sprintf (buffer, "%d", nb_minutes);

   return buffer;
}


void Duree::afficher(QTextStream& f) const {
   f.setPadChar('0');
   f.setFieldWidth(2);
   f<<nb_minutes/60;
   f.setFieldWidth(0);
   f<<"H";
   f.setFieldWidth(2);
   f<<nb_minutes%60;
   f.setFieldWidth(0);
   f.setPadChar(' ');
}

bool Duree::operator<(const Duree &b)
{
   if(this->getDureeEnMinutes() < b.getDureeEnMinutes())
      return true;
   else
      return false;
}
