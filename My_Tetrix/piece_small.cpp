#include "piece_small.h"

PieceSmall::PieceSmall(QObject *parent):
    QObject(parent),QGraphicsItem()
{


}

PieceSmall::~PieceSmall()
{

}

void PieceSmall::setBrush(QBrush i_brush)
{
    brush = i_brush;
}

void PieceSmall::setX(int i_x)
{
    coordX=i_x;
}

void PieceSmall::setY(int i_y)
{
    coordY=i_y;
}

int PieceSmall::getX()
{
    return this->x();
}

int PieceSmall::getY()
{
    return this->y();
}



QPainterPath PieceSmall::PieceSmall::shape() const
{

          QPainterPath path;
          path.addRect(1,1,19,19);
          return path;
}

QRectF PieceSmall::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void PieceSmall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    painter->drawRect(0,0,20,20);
}
