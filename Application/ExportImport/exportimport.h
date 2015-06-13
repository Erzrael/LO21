/*! \file
 * \brief contient la déclaration de la classe ExportImport
 *
 *
 */
#ifndef EXPORTIMPORT_H
#define EXPORTIMPORT_H
#include <QString>

class ProjetManager;
class Agenda;

/*! \brief Interface d'objets capables de réaliser l'export et l'import de l'agenda
 * classe abstraite
 */
class ExportImport
{
protected:
   QString filename; /*!< nom du fichier que l'on voudra modifier */
   Agenda & agenda; /*!< lien vers l'instance unique d'Agenda */
   ProjetManager & projetManager; /*!< lien vers l'instance Unique de ProjetManager */
   ExportImport(QString & filename); /*!< constructeur */

public:
   virtual void save() = 0; /*!< fonction réalisant l'export de l'agenda dans le fichier */
   virtual void load() = 0; /*!< fonction réalisant l'import de l'agenda depuis le fichier */
   ~ExportImport();
};




#endif // EXPORTIMPORT_H
