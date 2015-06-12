#include "ajoutCompositionWindow.h"
#include "ui_ajoutCompositionWindow.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"

AjoutCompositionWindow::AjoutCompositionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutCompositionWindow)
{
    ui->setupUi(this);

    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

AjoutCompositionWindow::~AjoutCompositionWindow()
{
    delete ui;
}

void AjoutCompositionWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();
    TacheComposite* Composee = dynamic_cast<TacheComposite*>(projetmanager.getTache(ui->Composee_Box->currentText()));
    Tache* Composante = projetmanager.getTache(ui->Composante_Box->currentText());
    if(Composee->verifierComposition(*Composante)){
        Composee->ajouterComposition(*Composante);
        QMessageBox::information(this,"Succès","La composition a été créée.");
    } else {
        QMessageBox::warning(this,"Erreur","La composition n'a pu être effectuée.");
    }
}

void AjoutCompositionWindow::on_Projet_Box_currentTextChanged(const QString &arg1)
{
    ui->Composee_Box->clear();
    ui->Composante_Box->clear();

    ProjetManager &projetmanager = ProjetManager::getInstance();

    Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

    for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
        TacheComposite* item = dynamic_cast<TacheComposite*>(*it);
        if(item)
            ui->Composee_Box->addItem(item->getIdentificateur());
    }
}

void AjoutCompositionWindow::on_Composee_Box_currentTextChanged(const QString &arg1)
{
    if(ui->Composee_Box->currentText() != ""){
        ui->Composante_Box->clear();
        ProjetManager &projetmanager = ProjetManager::getInstance();

        Projet* P = projetmanager.getProjet(ui->Projet_Box->currentText());

        Tache* T = P->trouverTache(ui->Composee_Box->currentText());

        for(vector<Tache*>::const_iterator it = P->getTaches().begin(); it != P->getTaches().end(); ++it){
            if(T->verifierComposition(**it))
                ui->Composante_Box->addItem((*it)->getIdentificateur());
        }
    }
}
