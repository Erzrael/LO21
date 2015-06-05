#include "ajoutCompositionWindow.h"
#include "ui_ajoutCompositionWindow.h"

AjoutCompositionWindow::AjoutCompositionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutCompositionWindow)
{
    ui->setupUi(this);
}

AjoutCompositionWindow::~AjoutCompositionWindow()
{
    delete ui;
}
