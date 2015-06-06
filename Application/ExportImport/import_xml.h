#ifndef IMPORT_XML_H
#define IMPORT_XML_H
#include <ExportImport/exportimport.h>

char * convertQString(QString string);

//class ExportImport;

class ExportImport_XML : public ExportImport {
public:
   ExportImport_XML(QString filename);
   void load();
   void save();

private:
   QString format;
};

#endif // IMPORT_XML_H
