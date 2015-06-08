#include "choixTacheWindow.h"
#include "Classe/projet.h"
#include "Classe/projetManager.h"
#include "ui_choixTacheWindow.h"
#include "editionTacheCompositeWindow.h"
#include "editionTacheUnitaireWindow.h"

ChoixTacheWindow::ChoixTacheWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixTacheWindow)
{
    ui->setupUi(this);
    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

ChoixTacheWindow::~ChoixTacheWindow()
{
    delete ui;
}

void ChoixTacheWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Tache* Current = projetmanager.getTache(ui->Tache_Box->currentText());
    TacheComposite* Composite = dynamic_cast<TacheComposite*>(Current);
    if(Composite){
        EditionTacheCompositeWindow* edition_tache_composite_window = new EditionTacheCompositeWindow(Composite);
        edition_tache_composite_window->setModal(true);
        edition_tache_composite_window->exec();
        delete edition_tache_composite_window;
    } else {
        TacheUnitaire* Unitaire = dynamic_cast<TacheUnitaire*>(Current);
        EditionTacheUnitaireWindow* edition_tache_unitaire_window = new EditionTacheUnitaireWindow(Unitaire);
        edition_tache_unitaire_window->setModal(true);
        edition_tache_unitaire_window->exec();
        delete edition_tache_unitaire_window;
    }
}

void ChoixTacheWindow::on_Projet_Box_currentTextChanged(const QString &arg1)
{
    ui->Tache_Box->clear();
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
        ui->Tache_Box->addItem((*it)->getIdentificateur());
    }
}
