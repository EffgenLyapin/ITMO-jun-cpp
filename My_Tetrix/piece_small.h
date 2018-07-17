#ifndef PIECE_SMALL_H
#define PIECE_SMALL_H
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <QBrush>

const int size=20;

class PieceSmall:public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit PieceSmall(QObject *parent=0);
    ~PieceSmall();
    QPainterPath PieceSmall::shape() const;
    void setBrush(QBrush i_brush);
    void setX(int i_x);
    void setY(int i_y);
    int getX();
    int getY();



protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QBrush brush;
    int coordX=0;
    int coordY=0;
};

#endif // PIECE_SMALL_H
