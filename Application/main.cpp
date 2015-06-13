/*! \file
 * \brief contient le programme principal (fonction main) : lancement de l'interface graphique
 *
 *
 */
#include "Classe/tache.h"
#include "Classe/tacheUnitaire.h"
#include "Classe/tacheComposite.h"
#include "Classe/projet.h"
#include "Classe/projetManager.h"
#include "Classe/agenda.h"

#include "InterfaceGraphique/mainWindow.h"
#include <QCoreApplication>
#include <QApplication>
#include <QComboBox>
#include <qdebug.h>
#include <ExportImport/import_xml.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow e;
    e.show();

    return app.exec();


    qDebug() << "Allegria";
}
