#include "tacheEditionWindow.h"
#include "ui_tacheEditionWindow.h"

TacheEditionWindow::TacheEditionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TacheEditionWindow)
{
    ui->setupUi(this);
}

TacheEditionWindow::~TacheEditionWindow()
{
    delete ui;
}
