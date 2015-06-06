#ifndef AJOUTPRECEDENCEWINDOW_H
#define AJOUTPRECEDENCEWINDOW_H

#include <QDialog>

namespace Ui {
class AjoutPrecedenceWindow;
}

class AjoutPrecedenceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutPrecedenceWindow(QWidget *parent = 0);
    ~AjoutPrecedenceWindow();

private slots:
    void on_buttonBox_accepted();

    void on_Projet_Box_currentTextChanged(const QString &arg1);

private:
    Ui::AjoutPrecedenceWindow *ui;
};

#endif // AJOUTPRECEDENCEWINDOW_H
