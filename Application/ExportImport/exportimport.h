#ifndef EXPORTIMPORT_H
#define EXPORTIMPORT_H
#include <stdio.h>
#include <QString>
#include <Classe/projetManager.h>
#include <Classe/agenda.h>

class ExportImport
{
protected:
   FILE * file;
   Agenda & agenda;
   ProjetManager & projetmanager;
   ExportImport(FILE * file);
};

ExportImport::ExportImport(FILE * file) : file(file), agenda(Agenda::getInstance()), projetmanager(ProjetManager::getInstance()) {}
#endif // EXPORTIMPORT_H
