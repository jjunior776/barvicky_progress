#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QCloseEvent>

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    void runGame(int mode);
    ~Game();

private slots:
    void on_trueBtn_clicked();

    void on_falseBtn_clicked();

    void decision(bool answer);

    void randomPaint();

    void newGame();

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void closed();

private:
    //QColor pallete[];
    QList<QColor> pallete;
    QString colours[5];
    int correct;
    int wrong;
    int all;
    int currentColor;
    int currentPallete;
    int gameMode;
    Ui::Game *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
};

#endif // GAME_H
