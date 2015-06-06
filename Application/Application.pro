#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T17:56:31
#
#-------------------------------------------------

QT += widgets
QT += xml

CONFIG +=  console debug

SOURCES += main.cpp \
    Classe/tache.cpp \
    Classe/tacheUnitaire.cpp \
    Classe/duree.cpp \
    Classe/calendarException.cpp \
    Classe/agenda.cpp \
    Classe/tacheComposite.cpp \
    Classe/projetManager.cpp \
    Classe/projet.cpp \
    Classe/evenement.cpp \
    Classe/programmation.cpp \
    InterfaceGraphique/ajoutCompositionWindow.cpp \
    InterfaceGraphique/ajoutPrecedenceWindow.cpp \
    InterfaceGraphique/ajoutProjetWindow.cpp \
    InterfaceGraphique/choixTacheWindow.cpp \
    InterfaceGraphique/editionTacheCompositeWindow.cpp \
    InterfaceGraphique/editionTacheUnitaireWindow.cpp \
    InterfaceGraphique/mainWindow.cpp \
    InterfaceGraphique/supprimerCompositionWindow.cpp \
    InterfaceGraphique/supprimerPrecedenceWindow.cpp \
    InterfaceGraphique/supprimerProjetWindow.cpp \
    InterfaceGraphique/supprimerTacheWindow.cpp \
    InterfaceGraphique/tacheEditionWindow.cpp \
    ExportImport/import_xml.cpp \
    InterfaceGraphique/ajoutTacheWindow.cpp

HEADERS += \
    Classe/tache.h \
    Classe/tacheUnitaire.h \
    Classe/duree.h \
    Classe/calendarException.h \
    Classe/agenda.h \
    Classe/programmation.h \
    Classe/tacheComposite.h \
    Classe/projetManager.h \
    Classe/projet.h \
    Classe/evenement.h \
    InterfaceGraphique/ajoutCompositionWindow.h \
    InterfaceGraphique/ajoutPrecedenceWindow.h \
    InterfaceGraphique/ajoutProjetWindow.h \
    InterfaceGraphique/choixTacheWindow.h \
    InterfaceGraphique/editionTacheCompositeWindow.h \
    InterfaceGraphique/editionTacheUnitaireWindow.h \
    InterfaceGraphique/mainWindow.h \
    InterfaceGraphique/supprimerCompositionWindow.h \
    InterfaceGraphique/supprimerPrecedenceWindow.h \
    InterfaceGraphique/supprimerProjetWindow.h \
    InterfaceGraphique/supprimerTacheWindow.h \
    InterfaceGraphique/tacheEditionWindow.h \
    ExportImport/exportimport.h \
    ExportImport/import.h \
    ExportImport/export.h \
    ExportImport/import_xml.h \
    InterfaceGraphique/ajoutTacheWindow.h

FORMS += \
    InterfaceGraphique/ajoutCompositionWindow.ui \
    InterfaceGraphique/ajoutPrecedenceWindow.ui \
    InterfaceGraphique/ajoutProjetWindow.ui \
    InterfaceGraphique/choixTacheWindow.ui \
    InterfaceGraphique/editionTacheCompositeWindow.ui \
    InterfaceGraphique/editionTacheUnitaireWindow.ui \
    InterfaceGraphique/mainWindow.ui \
    InterfaceGraphique/supprimerCompositionWindow.ui \
    InterfaceGraphique/supprimerPrecedenceWindow.ui \
    InterfaceGraphique/supprimerProjetWindow.ui \
    InterfaceGraphique/supprimerTacheWindows.ui \
    InterfaceGraphique/tacheEditionWindow.ui \
    InterfaceGraphique/ajoutTacheWindow.ui
