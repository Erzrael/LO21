#include "supprimerPrecedenceWindow.h"
#include "ui_supprimerPrecedenceWindow.h"

SupprimerPrecedenceWindow::SupprimerPrecedenceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerPrecedenceWindow)
{
    ui->setupUi(this);
}

SupprimerPrecedenceWindow::~SupprimerPrecedenceWindow()
{
    delete ui;
}
