#ifndef AJOUTCOMPOSITIONWINDOW_H
#define AJOUTCOMPOSITIONWINDOW_H

#include <QDialog>

namespace Ui {
class AjoutCompositionWindow;
}

class AjoutCompositionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutCompositionWindow(QWidget *parent = 0);
    ~AjoutCompositionWindow();

private slots:
    void on_buttonBox_accepted();

    void on_Projet_Box_currentTextChanged(const QString &arg1);

private:
    Ui::AjoutCompositionWindow *ui;
};

#endif // AJOUTCOMPOSITIONWINDOW_H
