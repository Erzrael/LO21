#ifndef SUPPRIMERTACHEWINDOW_H
#define SUPPRIMERTACHEWINDOW_H

#include <QDialog>

namespace Ui {
class SupprimerTacheWindow;
}

class SupprimerTacheWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerTacheWindow(QWidget *parent = 0);
    ~SupprimerTacheWindow();

private:
    Ui::SupprimerTacheWindow *ui;
};

#endif // SUPPRIMERTACHEWINDOW_H
