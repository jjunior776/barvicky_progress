#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "game.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_endlessBtn_clicked();

    void on_classicBtn_clicked();

private:
    Ui::Menu *ui;
    Game *game;

};

#endif // MENU_H
