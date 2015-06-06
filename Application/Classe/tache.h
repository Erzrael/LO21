#ifndef TACHE_H
#define TACHE_H

#include <QString>
#include <QDate>
#include <vector>
#include <Classe/calendarException.h>

class Projet;

class Tache {
protected:
    std::vector<Tache*> precedence;
    QString identificateur;
    QString titre;
    QDate disponibilite;
    QDate echeance;
    Tache* mere;
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

    Tache *getMere() const;
    void setMere(Tache *value);

    Tache* getMere_Compo() const;
    void setMere_Compo(Tache *value);
    /* Patron Factory Methode */
    virtual Tache* clone() const = 0;

    /* Autres Fonctions */
    void ajouterPrecedence(Tache& t);
    bool verifierPrecedence(const Tache &t) const;
    bool verifierComposition(const Tache &t) const;
    unsigned int nbPrerequis() const;
    Tache* getPere(); // Renvoie un pointeur vers la tache père de la tâche appelante ou 0 si le père est le projet
    Projet* getProjet(); // Renvoie le projet auquel appartient une tâche
};

#endif // TACHE_H
