#ifndef AJOUTTACHEWINDOW_H
#define AJOUTTACHEWINDOW_H

#include <QDialog>

namespace Ui {
class AjoutTacheWindow;
}

class AjoutTacheWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutTacheWindow(QWidget *parent = 0);
    ~AjoutTacheWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AjoutTacheWindow *ui;
};

#endif // AJOUTTACHEWINDOW_H
