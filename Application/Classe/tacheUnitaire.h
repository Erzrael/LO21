#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H
#include "tache.h"
#include <ExportImport/rapidxml-1.13/rapidxml.hpp>
#include "duree.h"
#include "evenement.h"

class TacheUnitaire : public Tache, public Evenement {
    friend class ProjetManager;
protected:
    TacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur);
    //comme de toute manière TacheUnitaire est abstraite, pas besoin de mettre les opérateurs en privé
    //    TacheUnitaire(const TacheUnitaire& t);
    //    TacheUnitaire& operator=(const TacheUnitaire& obj);
    ~TacheUnitaire();

public:
    virtual bool getPreempte() = 0;
    // Tache interface
    virtual void xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache);
    // Evenement interface
    const QString & getID() const;
};

#endif // TACHEUNITAIRE_H
