#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H
#include "tache.h"
#include <ExportImport/rapidxml-1.13/rapidxml.hpp>
#include "duree.h"
#include "evenement.h"

/*! \brief Classe représentant une tache unitaire
 * classe abstraite
 * Une tache unitaire est programmable dans l'Agenda : c'est donc un évènement.
 */
class TacheUnitaire : public Tache, public Evenement {
    friend class ProjetManager;
protected:
    TacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur); /*!< constructeur */
    virtual ~TacheUnitaire(); /*!< destructeur */
public:
    virtual bool getPreempte() = 0; /*!< la tâche est préemptable ou non */
    // Tache interface
    virtual void xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache);
    // Evenement interface
    const QString & getID() const; /*!< \return identificateur de la tâche */
    void suppressionProgrammation(); /*!< ne fait rien : une tâche n'est pas affectée par la suppression de sa programmation */
};

#endif // TACHEUNITAIRE_H
