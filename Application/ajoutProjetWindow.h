#ifndef AJOUTPROJETWINDOW_H
#define AJOUTPROJETWINDOW_H

#include <QDialog>

namespace Ui {
class AjoutProjetWindow;
}

class AjoutProjetWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutProjetWindow(QWidget *parent = 0);
    ~AjoutProjetWindow();

private:
    Ui::AjoutProjetWindow *ui;
};

#endif // AJOUTPROJETWINDOW_H
