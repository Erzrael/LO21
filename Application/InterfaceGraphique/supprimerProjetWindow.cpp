#include "supprimerProjetWindow.h"
#include "ui_supprimerProjetWindow.h"

SupprimerProjetWindow::SupprimerProjetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerProjetWindow)
{
    ui->setupUi(this);
}

SupprimerProjetWindow::~SupprimerProjetWindow()
{
    delete ui;
}
