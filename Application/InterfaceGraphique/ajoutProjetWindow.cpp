#include "ajoutProjetWindow.h"
#include "ui_ajoutProjetWindow.h"
#include "Classe/projetManager.h"

AjoutProjetWindow::AjoutProjetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutProjetWindow)
{
    ui->setupUi(this);
}

AjoutProjetWindow::~AjoutProjetWindow()
{
    delete ui;
}

void AjoutProjetWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();
    projetmanager.ajouterProjet(ui->Id_Edit->text(), ui->Titre_Edit->text(),
                                QDate(ui->Dispo_Edit->date()),
                                QDate(ui->Echeance_Edit->date()));
    /*
    qDebug()<<"Projet ajouté";
    qDebug()<<projetmanager.getProjets()[0]->getId();
    qDebug()<<projetmanager.getProjets()[0]->getDisponibilite();
    */
}
