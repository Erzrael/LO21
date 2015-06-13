/*! \file
 * \brief contient la déclaration de la classe ExportImport_XML (import export de l'agenda au format XML
 *
 *
 */
#ifndef IMPORT_XML_H
#define IMPORT_XML_H
#include <ExportImport/exportimport.h>

char * convertQString(QString string); /*!< permet de convertir une Qstring en char* */

//class ExportImport;

/*! \brief classe permettant l'import/export de l'agenda au format XML
 * Implémentation de la classe ExportImport
 */
class ExportImport_XML : public ExportImport {
public:
   ExportImport_XML(QString filename);
   void load();
   void save();

private:
   QString format; /*!< format des dates dans le fichier */
   QString format_time; /*!< format des dates dans le fichier */
};

#endif // IMPORT_XML_H
