#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRandomGenerator>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    min=32;
    ui->setupUi(this);
    this->setFixedSize(675,730);
    timer=new QTimer;
    timer->setInterval(1200-level*100);

    body=new QWidget;

    this->setCentralWidget(body);
    layout=new QGridLayout(body);
    view=new QGraphicsView();
    view->setFixedHeight(700);
    view->setFixedWidth(430);
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,420,660);
    scene->setBackgroundBrush(Qt::gray);
    QFont LabelFont("Times", 20, QFont::Bold);
//    shape_type=QRandomGenerator::global()->bounded(7)+1;
    LevName=new QLabel("LEVEL");
    LevName->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    LevName->setFont(LabelFont);
    LevCount=new QLCDNumber(7);
    LinesName=new QLabel("LINES");
    LinesName->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    LinesName->setFont(LabelFont);
    LinesCount=new QLCDNumber(5);
    start=new QPushButton("Start");
    stop=new QPushButton("Stop");
    pause=new QPushButton("Pause");
    quit=new QPushButton("Quit");;


//    piece=new Piece();
//    piece->setShape_T(shape_type);

    view->setScene(scene);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_update()));
    connect(this,SIGNAL(changingLevel()),this,SLOT(changeLevel()));
    connect(this,SIGNAL(levelChanged(int)),LevCount,SLOT(display(int)));
    connect(this,SIGNAL(linesChanged(int)),LinesCount,SLOT(display(int)));
    connect(start,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(pause,SIGNAL(clicked()),this,SLOT(pauseGame()));
    connect(stop,SIGNAL(clicked()),this,SLOT(end_game()));
    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
    layout->addWidget(view,0,0,8,2);
    layout->addWidget(LevName,0,3);
    layout->addWidget(LevCount,1,3);
    layout->addWidget(LinesName,2,3);
    layout->addWidget(LinesCount,3,3);
    layout->addWidget(start,4,3);
    layout->addWidget(stop,5,3);
    layout->addWidget(pause,6,3);
    layout->addWidget(quit,7,3);






}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkFillLine(int i)
{
   bool fill=false;
   int k=0;
       foreach(PieceSmall *item,pieces)
       {
//         int m=i*20;
//         int x=item->getX();
//         int y=item->getY();
         if (item->getY()==i*20&&item->getX()>=0&&item->getX()<660)
         k++;
       }
   if (k==21) fill=true;
   return fill;
}

void MainWindow::clearLine(int i)
{
    foreach(PieceSmall *item,pieces)
    {
//      int m=i*20;
//      int x=item->getX();
//      int y=item->getY();
      if (item->getY()==i*20&&item->getX()>=0&&item->getX()<660)
      {
      scene->removeItem(item);
      pieces.removeOne(item);
      }
    }
    linesDropped++;
    emit linesChanged(linesDropped);
    if(linesDropped%15==0)
    {
        level++;
        emit changingLevel();
        emit levelChanged(level);
    }
}

void MainWindow::oneLineDown(int i)
{
    for (int j=i;j>=0;j--)
    {
        foreach(PieceSmall *item,pieces)
        {

            if (item->getX()>=0&&item->getX()<660&&item->getY()==j*20)
                item->setPos(item->getX(),item->getY()+20);
        }
    }
    min--;
}



void MainWindow::newPiece()
{
    scene->removeItem(piece);
    shape_type=QRandomGenerator::global()->bounded(7)+1;
    piece=new Piece();
    piece->setShape_T(shape_type);
    scene->addItem(piece);
    connect(piece,SIGNAL(addPiece()),this,SLOT(addPiece()));
    connect(piece,SIGNAL(signalNewPiece()),this,SLOT(newPiece()));

}





void MainWindow::end_game()
{
    pieces.clear();
    QFont serifFont("Times", 15, QFont::Bold);
    scene->clear();
    scene->addText("GAME OVER!",serifFont);
    runGame=false;
    timer->stop();
    start->setEnabled(true);
    paused=false;
}

void MainWindow::addPiece()
{

    foreach (PieceSmall* item, piece->getPieces_s())
    {
        //item->setPos(mapToParent(item->g));
        scene->addItem(item);
        pieces.push_back(item);
        min=qMin(min,item->getY()/20);
    }

        int i=32;
        while (i>=min)
        {
            bool fill=checkFillLine(i);
            if (fill)
            {
                clearLine(i);
                oneLineDown(i);
                i++;
            }
            else i--;
        }
}

void MainWindow::timer_update()
{

    if (runGame)
    {
    start->setEnabled(false);
    if (!paused)
    {
    piece->moving(0,1);
    getColidies(0,1);
    }
    }
    else start->setEnabled(true);
}

void MainWindow::changeLevel()
{
    int timerInterval=1200-level*100;
    if (timerInterval>300)
        timer->setInterval(timerInterval);
}

void MainWindow::startGame()
{
    scene->clear();
    newPiece();
    runGame=true;
    timer->start(1000);
    paused=false;

}

void MainWindow::pauseGame()
{
    paused=!paused;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (runGame&&!paused)
    {
    switch (event->key())
    {
        case Qt::Key_W:
            piece->rotate_piece();
            getColidies(10,10);
            break;
        case Qt::Key_S:
          //
         //   piece->moving(0,1);

            piece->moving(0,1);
            getColidies(0,1);

          break;
        case Qt::Key_A:
          //
         //   piece->moving(-1,0);

            piece->moving(-1,0);
            getColidies(-1,0);
          break;
        case Qt::Key_D:
          //
            // piece->moving(1,0);

            piece->moving(1,0);
            getColidies(1,0);
          break;
        default:
            break;

    }
}
}

bool MainWindow::getColidies(int x, int y)
{
    int xyz=pieces.size();
    if (xyz>0&&runGame)
    {
        if (x!=0&&y==0)
        {
//working!!!
//            QList<QGraphicsItem*> collItems=piece->collidingItems();
//            if (!collItems.isEmpty())
//            {
//                piece->moving(0,0);
//                return true;
//            }
//-----------------------------------
            for(int i=0;i<xyz;i++)
            {
                    if (piece->collidesWithPath (pieces[i], Qt::IntersectsItemShape))//collidesWithPath(item->mapFromItem(item,item->shape()),Qt::IntersectsItemShape))
                        {
                        piece->moving(-1*x,y);
                        //piece->setCoords(piece->getX()*20-x*20,piece->getY()*20);
                        return true;
                        }

                 }

        }
        if (y>0&&x==0)
        {
//working!!!
//            QList<QGraphicsItem*> collItems=piece->collidingItems();
//            if (!collItems.isEmpty()&&piece->getY()>1)
//            {
//                piece->moving(0,0);
//                piece->setmoveEn(false);
//                piece->signalNewPiece();
//                return true;
//            }
//            if (!collItems.isEmpty()&&piece->getY()<=1)
//            {
//                emit end_game();
//                return true;
//            }
//---------------------------
            for(int i=0;i<xyz;i++)
                {

                    if (piece->collidesWithPath(pieces[i],  Qt::IntersectsItemShape)&&piece->getY()>1)
                        {
                          
                            piece->moving(x,-1*y);
                            // piece->setCoords(piece->getX()*20,piece->getY()*20-y*20);
                            piece->setmoveEn(false);
                            piece->addPiece();
                            piece->signalNewPiece();

                            return true;
                        }
                    if (piece->collidesWithPath(pieces[i],  Qt::IntersectsItemShape)&&piece->getY()<=1)
                        {
                            emit end_game();
                            return true;
                        }


                }
        }
        if (x==10&&y==10)
        {
            for(int i=0;i<xyz;i++)
            {

                    if (piece->collidesWithPath (pieces[i], Qt::IntersectsItemShape))//collidesWithPath(item->mapFromItem(item,item->shape()),Qt::IntersectsItemShape))
                    {
                    piece->unrotate_piece();
                   // piece->moving(0,-1);
                        //piece->setCoords(piece->getX()*20-x*20,piece->getY()*20);
                        return true;
                    }


            }
        }
    }
//    }
    return false;
}

