#ifndef CHOIXTACHEWINDOW_H
#define CHOIXTACHEWINDOW_H

#include <QDialog>

namespace Ui {
class ChoixTacheWindow;
}

class ChoixTacheWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixTacheWindow(QWidget *parent = 0);
    ~ChoixTacheWindow();

private slots:
    void on_buttonBox_accepted();

    void on_Projet_Box_currentTextChanged(const QString);

private:
    Ui::ChoixTacheWindow *ui;
};

#endif // CHOIXTACHEWINDOW_H
