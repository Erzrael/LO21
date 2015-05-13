#ifndef CALENDAREXCEPTION_H
#define CALENDAREXCEPTION_H

#include <QString>
#include <QDate>
#include <QTextStream>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>

using namespace std;

class CalendarException{

    QString info;

public:

    CalendarException(const QString& message):info(message){}

    QString getInfo() const {
        return info;
    }
};
#endif // CALENDAREXCEPTION_H
