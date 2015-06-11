#include "supprimerProjetWindow.h"
#include "ui_supprimerProjetWindow.h"
#include "Classe/projetManager.h"
#include "Classe/projet.h"

SupprimerProjetWindow::SupprimerProjetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerProjetWindow)
{
    ui->setupUi(this);
    ProjetManager &projetmanager = ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = projetmanager.getProjets().begin(); it != projetmanager.getProjets().end(); ++it)
        ui->Projet_Box->addItem((*it)->getId());
}

SupprimerProjetWindow::~SupprimerProjetWindow()
{
    delete ui;
}

void SupprimerProjetWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();

    projetmanager.supprimerProjet(ui->Projet_Box->currentText());
}
