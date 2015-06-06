#include "ajoutPrecedenceWindow.h"
#include "ui_ajoutPrecedenceWindow.h"

AjoutPrecedenceWindow::AjoutPrecedenceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutPrecedenceWindow)
{
    ui->setupUi(this);
}

AjoutPrecedenceWindow::~AjoutPrecedenceWindow()
{
    delete ui;
}
