#include "supprimerCompositionWindow.h"
#include "ui_supprimerCompositionWindow.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"
#include "Classe/tacheComposite.h"

SupprimerCompositionWindow::SupprimerCompositionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerCompositionWindow)
{
    ui->setupUi(this);

    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

SupprimerCompositionWindow::~SupprimerCompositionWindow()
{
    delete ui;
}

void SupprimerCompositionWindow::on_Tache_Box_currentTextChanged(const QString &arg1)
{
    if(ui->Tache_Box->currentText() != ""){
        ui->Composante_Box->clear();
        ProjetManager &projetmanager = ProjetManager::getInstance();

        Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

        TacheComposite* T = dynamic_cast<TacheComposite*>(P->trouverTache(ui->Tache_Box->currentText()));

        for(vector<Tache*>::const_iterator it = T->getComposition().begin(); it != T->getComposition().end(); ++it)
            ui->Composante_Box->addItem((*it)->getIdentificateur());
    }
}

void SupprimerCompositionWindow::on_Projet_Box_currentTextChanged(const QString &arg1)
{
    ui->Tache_Box->clear();
    ui->Composante_Box->clear();
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
        TacheComposite* item = dynamic_cast<TacheComposite*>(*it);
        if(item)
            ui->Tache_Box->addItem(item->getIdentificateur());
    }
}

void SupprimerCompositionWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    TacheComposite* T = dynamic_cast<TacheComposite*>(P->trouverTache(ui->Tache_Box->currentText()));

    try{
        T->supprimerComposition(ui->Composante_Box->currentText());
        QMessageBox::information(this,"Succès","La composition a bien été supprimée");
    } catch (CalendarException e) {
        QMessageBox::warning(this,"Erreur",e.getInfo());
    }
}
