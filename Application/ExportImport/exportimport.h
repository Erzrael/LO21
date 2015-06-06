#ifndef EXPORTIMPORT_H
#define EXPORTIMPORT_H
#include <QString>

class ProjetManager;
class Agenda;

class ExportImport
{
protected:
   QString filename;
   Agenda & agenda;
   ProjetManager & projetManager;
   ExportImport(QString & filename);

public:
   virtual void save() = 0;
   virtual void load() = 0;
   ~ExportImport();
};




#endif // EXPORTIMPORT_H
