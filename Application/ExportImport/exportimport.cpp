#include <ExportImport/exportimport.h>
#include <Classe/projetManager.h>
#include <Classe/agenda.h>



ExportImport::ExportImport(QString & filename) : filename(filename), agenda(Agenda::getInstance()), projetManager(ProjetManager::getInstance()) {}


ExportImport::~ExportImport()
{}
