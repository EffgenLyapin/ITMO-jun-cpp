#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QObject>
#include <QTimer>
#include <piece.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool checkFillLine(int i);
    void clearLine(int i);
    void oneLineDown(int i);
    int min;
    int linesDropped=0;
    int level=0;
    bool paused=false;


public slots:
    void newPiece();
    void end_game();
    void addPiece();
    void timer_update();
    void changeLevel();
    void startGame();
    void pauseGame();


signals:

    void ending_game();
    void changingLevel();
    void linesChanged(int);
    void levelChanged(int);

private:
    Ui::MainWindow *ui;
    QWidget *body;
    QGridLayout *layout;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLabel *LevName;
    QLCDNumber *LevCount;
    QLabel *LinesName;
    QLCDNumber *LinesCount;
    QPushButton *start;
    QPushButton *stop;
    QPushButton *pause;
    QPushButton *quit;
    Piece *piece;
    void keyPressEvent(QKeyEvent *event);
    int shape_type=0;
    bool getColidies(int x,int y);
    bool runGame=false;
    QVector<PieceSmall*> pieces;
    QTimer *timer;


};


#endif // MAINWINDOW_H
