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

private:
    Ui::AjoutPrecedenceWindow *ui;
};

#endif // AJOUTPRECEDENCEWINDOW_H
