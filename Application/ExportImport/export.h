#ifndef EXPORT_H
#define EXPORT_H
#include <ExportImport/exportimport.h>
#include <QString>
#include <stdio>

class Export : public ExportImport {
protected:
   virtual void save() = 0;
public:
   Import(QString filename) : ExportImport(fopen(filename, "r")) {
      save();
   }
};

#endif // EXPORT_H
