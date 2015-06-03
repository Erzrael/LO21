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
    mainWindow.cpp \
    ajoutProjetWindow.cpp

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
    mainWindow.h \
    ajoutProjetWindow.h

FORMS += \
    mainWindow.ui \
    AjoutProjetWindow.ui
