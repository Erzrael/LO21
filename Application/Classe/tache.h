#ifndef TACHE_H
#define TACHE_H

#include <QString>
#include <QDate>
#include <vector>
#include <Classe/calendarException.h>
#include <ExportImport/rapidxml-1.13/rapidxml.hpp>


class Projet;

class Tache {
protected:
    std::vector<Tache*> precedence;
    QString identificateur;
    QString titre;
    QDate disponibilite;
    QDate echeance;
    std::vector<Tache*> mere;
    Tache* mere_compo;
    /*const Projet* projet;
    const Tache* pere;*/

    Tache(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);
    Tache(const Tache& t);
    Tache& operator=(const Tache& obj);

    friend class Projet;
public:

    /* Revoir pour foutre le destructeur en privée */
    virtual ~Tache();

    /* Les Setter et Getter */
    QString& getIdentificateur();
    const QString& getIdentificateur() const;
    void setIdentificateur(const QString &value);

    QString& getTitre();
    const QString& getTitre() const;
    void setTitre(const QString &value);

    QDate& getDisponibilite();
    const QDate& getDisponibilite() const;
    void setDisponibilite(const QDate &value);

    QDate& getEcheance();
    const QDate& getEcheance() const;
    void setEcheance(const QDate &value);

    std::vector<Tache *> &getPrecedence();
    const std::vector<Tache *> &getPrecedence() const;

    std::vector<Tache *> &getMere();
    const std::vector<Tache*> &getMere() const;

    Tache* getMere_Compo() const;
    void setMere_Compo(Tache *value);

    /* Autres Fonctions */
    void ajouterPrecedence(Tache& t);
    bool verifierPrecedence(Tache &t) const;
    bool verifierComposition(Tache &t) const;
    void supprimerPrecedence(const QString & id);
    unsigned int nbPrerequis() const;
    Tache* getPere(); // Renvoie un pointeur vers la tache père de la tâche appelante ou 0 si le père est le projet
    Projet* getProjet(); // Renvoie le projet auquel appartient une tâche

    // nécessaire pour l'import xml
    virtual void xml_ajouterAttributs(rapidxml::xml_document<> & doc, rapidxml::xml_node<> & node_tache) = 0;
};

#endif // TACHE_H
