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

}

void SupprimerCompositionWindow::on_Composante_Box_currentTextChanged(const QString &arg1)
{

}
