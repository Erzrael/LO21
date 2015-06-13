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

/*! \brief Classe utilisée pour toutes les exceptions
 */
class CalendarException{

    QString info; /*!< information quand à l'erreur qui a généré l'exception */

public:

    /*! \brief Constructeur de l'exception
     *
     * Le constructeur affiche par défaut le message passé en paramètre dans le débuggage console
     * \param message d'erreur de l'exception
     * \return CalendarException
     *
     */
    CalendarException(const QString& message):info(message){
       qDebug()<<"CalendarException :"<<message;
    }

    /*! \brief Récupère l'info
     * Fonction permet d'accéder à l'information d'erreur de cette exception
     * \return QString Information d'erreur
     *
     */
    QString getInfo() const {
       return info;
   }
};
#endif // CALENDAREXCEPTION_H
