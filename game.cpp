#include "game.h"
#include "ui_game.h"
#include "QPainter"
#include "QDebug"
#include "time.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    srand(time(NULL));
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPen outline(Qt::black);

    pallete.append(QColor("red"));
    pallete.append(QColor("blue"));
    pallete.append(QColor("green"));
    pallete.append(QColor("yellow"));
    pallete.append(QColor("magenta"));

    colours[0] = "Červená";
    colours[1] = "Modrá";
    colours[2] = "Zelená";
    colours[3] = "Žlutá";
    colours[4] = "Fialová";

    //int sirka = 100;
    //int vyska = 100;
    rectangle = new QGraphicsRectItem(0,50,100,100);
    text = new QGraphicsTextItem("Barva");
    scene->addItem(rectangle);
    scene->addItem(text);

    text->setPos(0,150);

    newGame();
}


Game::~Game()
{
    delete ui;
}

void Game::on_trueBtn_clicked()
{
    decision(true);
}

void Game::on_falseBtn_clicked()
{
    decision(false);
}

void Game::decision(bool answer){
    if((currentColor==currentPallete)&&(answer==true))
        correct++;
    else if((currentColor!=currentPallete)&&(answer==false))
        correct++;
    else
        wrong++;
    all++;
    ui->correctText->setText(QString::number(correct));
    ui->allText->setText(QString::number(all));
    ui->wrongText->setText(QString::number(wrong));
    randomPaint();
}

void Game::randomPaint(){
    currentColor = rand()%5;
    currentPallete = rand()%5;
    //qDebug()<<currentPallete;
    rectangle->setBrush(pallete.at(currentPallete));
    text->setPlainText(colours[currentColor]);
}

void Game::runGame(int mode){
    gameMode = mode;
    newGame();
    return this->show();
}

void Game::closeEvent(QCloseEvent *event){
    emit closed();
    event->accept();
}

void Game::newGame(){
    randomPaint();
    correct = wrong = all = 0;
    if(gameMode==0){
        this->setWindowTitle("Barvy - Classic");
        ui->wrongText->hide();
        ui->correctText->hide();
    }
    else if(gameMode==1){
        this->setWindowTitle("Barvy - Eternal");
        ui->wrongText->show();
        ui->correctText->show();
    }

}


