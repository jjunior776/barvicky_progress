#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    game = new Game;
    connect(game,SIGNAL(closed()),this,SLOT(show()));
    connect(ui->classicBtn,SIGNAL(clicked(bool)),this,SLOT(hide()));
    connect(ui->endlessBtn,SIGNAL(clicked(bool)),this,SLOT(hide()));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_endlessBtn_clicked()
{
    game->runGame(1);
}

void Menu::on_classicBtn_clicked()
{
    //game = new Game;
    game->runGame(0);
}
