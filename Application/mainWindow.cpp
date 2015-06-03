#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "ajoutProjetWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAjouter_un_Projet_triggered()
{
    AjoutProjetWindow ajout_projet_window;
    ajout_projet_window.setModal(true);
    ajout_projet_window.exec();
}
