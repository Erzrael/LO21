#include "ajoutProjetWindow.h"
#include "ui_ajoutProjetWindow.h"
#include "Classe/projetManager.h"
#include "QMessageBox"

AjoutProjetWindow::AjoutProjetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutProjetWindow)
{
    ui->setupUi(this);
    ui->Dispo_Edit->setMinimumDate(QDate::currentDate());
    ui->Echeance_Edit->setMinimumDate(QDate::currentDate().addDays(1));
}

AjoutProjetWindow::~AjoutProjetWindow()
{
    delete ui;
}

void AjoutProjetWindow::on_buttonBox_accepted()
{
    ProjetManager &projetmanager = ProjetManager::getInstance();
    if(ui->Id_Edit->text() == "" || ui->Titre_Edit->text() == "" ||
            (ui->Dispo_Edit->date() == ui->Echeance_Edit->date()))
        QMessageBox::warning(this,"Erreur","Certains champs sont vides ou incohérents");
    else {
        if(projetmanager.isProjetExistant(ui->Id_Edit->text())){
            QMessageBox::warning(this,"Erreur","Le projet existe déjà !");
        } else {
            projetmanager.ajouterProjet(ui->Id_Edit->text(), ui->Titre_Edit->text(),
                                        QDate(ui->Dispo_Edit->date()),
                                        QDate(ui->Echeance_Edit->date()));
            QMessageBox::information(this,"Succès","Le projet a bien été crée !");
        }
    }
    /*
    qDebug()<<"Projet ajouté";
    qDebug()<<projetmanager.getProjets()[0]->getId();
    qDebug()<<projetmanager.getProjets()[0]->getDisponibilite();
    */
}
