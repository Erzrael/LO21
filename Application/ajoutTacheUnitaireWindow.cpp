#include "ajoutTacheUnitaireWindow.h"
#include "ui_ajoutTacheUnitaireWindow.h"

AjoutTacheUnitaireWindow::AjoutTacheUnitaireWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutTacheUnitaireWindow)
{
    ui->setupUi(this);
}

AjoutTacheUnitaireWindow::~AjoutTacheUnitaireWindow()
{
    delete ui;
}
