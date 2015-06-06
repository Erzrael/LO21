#include "supprimerCompositionWindow.h"
#include "ui_supprimerCompositionWindow.h"

SupprimerCompositionWindow::SupprimerCompositionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerCompositionWindow)
{
    ui->setupUi(this);
}

SupprimerCompositionWindow::~SupprimerCompositionWindow()
{
    delete ui;
}
