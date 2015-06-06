#ifndef IMPORT_H
#define IMPORT_H
#include <ExportImport/exportimport.h>
#include <QString>
#include <stdio>

class Import : public ExportImport {
protected:
   virtual void load() = 0;
public:
   Import(QString filename) : ExportImport(fopen(filename, "r")) {
      load();
   }
};

#endif // IMPORT_H
