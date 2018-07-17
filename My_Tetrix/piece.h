#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <QRect>
#include <QVector>
#include<QRandomGenerator>
#include"piece_small.h"



enum TetrixShape { NoShape,ZShape, SShape, LineShape, TShape, SquareShape,
                   LShape, MirroredLShape };
//coordsTable[0][0]=QRect( 0, 0, 20, 20);
//coordsTable[0][1]=QRect( 20, 0, 20, 20);
//coordsTable[0][2]=QRect( 20, 20, 20, 20);
//coordsTable[0][3]=QRect( 40, 20, 20, 20);

//coordsTable[1][0]=QRect( 20, 0, 20, 20);
//coordsTable[1][1]=QRect( 40, 0, 20, 20);
//coordsTable[1][2]=QRect( 0, 20, 20, 20);
//coordsTable[1][3]=QRect( 20, 20, 20, 20);

//coordsTable[2][0]=QRect( 0, 0, 20, 20);
//coordsTable[2][1]=QRect( 0, 20, 20, 20);
//coordsTable[2][2]=QRect( 0, 40, 20, 20);
//coordsTable[2][3]=QRect( 0, 60, 20, 20);

//coordsTable[3][0]=QRect( 20, 0, 20, 20);
//coordsTable[3][1]=QRect( 0, 20, 20, 20);
//coordsTable[3][2]=QRect( 20, 20, 20, 20);
//coordsTable[3][3]=QRect( 40, 20, 20, 20);

//coordsTable[4][0]=QRect( 0, 0, 20, 20);
//coordsTable[4][1]=QRect( 0, 20, 20, 20);
//coordsTable[4][2]=QRect( 20, 0, 20, 20);
//coordsTable[4][3]=QRect( 20, 20, 20, 20);

//coordsTable[5][0]=QRect( 0, 40, 20, 20);
//coordsTable[5][1]=QRect( 20, 0, 20, 20);
//coordsTable[5][2]=QRect( 20, 20, 20, 20);
//coordsTable[5][3]=QRect( 20, 40, 20, 20);

//coordsTable[6][0]=QRect( 0, 0, 20, 20);
//coordsTable[6][1]=QRect( 0, 20, 20, 20);
//coordsTable[6][2]=QRect( 0, 40, 20, 20);
//coordsTable[6][3]=QRect( 20, 40, 20, 20);
//const int coordsTable [8][4][4]={
    //{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
    //{{0, 0, 20, 20},{20, 0, 20, 20},{20, 20, 20, 20},{40, 20, 20, 20}},
    //{{20, 0, 20, 20},{40, 0, 20, 20},{0, 20, 20, 20},{20, 20, 20, 20}},
    //{{0, 0, 20, 20},{0, 20, 20, 20},{0, 40, 20, 20},{0, 60, 20, 20}},
    //{{20, 0, 20, 20},{0, 20, 20, 20},{20, 20, 20, 20},{40, 20, 20, 20}},
    //{{0, 0, 20, 20},{0, 20, 20, 20},{20, 0, 20, 20},{20, 20, 20, 20}},
    //{{0, 40, 20, 20},{20, 0, 20, 20},{20, 20, 20, 20},{20, 40, 20, 20}},
    //{{0, 0, 20, 20},{0, 20, 20, 20},{0, 40, 20, 20},{20, 40, 20, 20}}



//};
const int coordsTable [8][4][2]={
    {{0,0},{0,0},{0,0},{0,0}},
    {{0,0},{20,0},{20,20},{40,20}},
    {{20,0},{40,0},{0,20},{20,20}},
    {{0,0},{20,0},{40,0},{60,0}},
    {{20,0},{0,20},{20,20},{40,20}},
    {{0,0},{20,0},{0,20},{20,20}},
    {{0,40},{20,0},{20,20},{20,40}},
    {{0,0},{0,20},{0,40},{20,40}}
};

//const int coordsTable [8][11][2]={
//    {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
//    {{0,0},{1,0},{2,0},{2,1},{3,1},{3,2},{2,2},{1,2},{1,1},{0,1},{10,0}},
//    {{1,0},{2,0},{3,0},{3,1},{2,1},{2,2},{1,2},{0,2},{0,1},{1,1},{10,0}},
//    {{0,0},{1,0},{2,0},{3,0},{4,0},{4,1},{3,1},{2,1},{1,1},{0,1},{10,0}},
//    {{1,0},{2,0},{2,1},{3,1},{3,2},{2,2},{1,2},{0,2},{0,1},{1,1},{10,0}},
//    {{0,0},{1,0},{2,0},{2,1},{2,2},{1,2},{0,2},{0,1},{0,0},{0,0},{8,0}},
//    {{0,2},{1,2},{1,1},{1,0},{2,0},{2,1},{2,2},{2,3},{1,3},{0,3},{10,0}},
//    {{0,0},{1,0},{1,1},{1,2},{2,2},{2,3},{1,3},{0,3},{0,2},{0,1},{10,0}}
//};
const int coordsTableShapes[8][11][2]={
    {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
    {{1,1},{20,1},{39,1},{39,21},{59,21},{59,39},{40,39},{21,39},{21,19},{1,19},{1,1}},
    {{21,1},{40,1},{59,1},{59,19},{39,19},{39,39},{20,39},{1,39},{1,21},{21,21},{21,1}},
    {{1,1},{20,1},{40,1},{60,1},{79,1},{79,19},{60,19},{40,19},{20,19},{1,19},{1,1}},
    {{21,1},{39,1},{39,21},{59,21},{59,39},{40,39},{20,39},{1,39},{1,21},{21,21},{21,1}},
    {{1,1},{20,1},{39,1},{39,20},{39,39},{20,39},{1,39},{1,20},{1,1},{1,1},{1,1}},
    {{1,41},{21,41},{21,20},{21,1},{39,1},{39,20},{39,40},{39,59},{20,59},{1,59},{1,41}},
    {{1,1},{19,1},{19,20},{19,41},{39,41},{39,59},{20,59},{1,59},{1,40},{1,20},{1,1}}
};



class Piece: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Piece(QObject *parent=0);
    ~Piece();
    void moving(int pos_x,int pos_y);

    void reset();
    int getX();
    int getY();
    void setCoords(int pos_x,int pos_y);
    void setShape_T(int type_shape);
    void rotate_piece();
    void unrotate_piece();
    void setmoveEn(bool m_En);
    QPainterPath Piece::shape() const;
    bool collidesWithPath(const PieceSmall *item, Qt::ItemSelectionMode mode) const;
    QVector<PieceSmall*> getPieces_s();
    void vec_PS_clear();

signals:
    void signalNewPiece();
    void addPiece();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    bool moveEn=true;
    bool pieceCreating=true;
    int coordsPiece[4][2];
    int coordsShape[11][2];
    int shape_T=0;
    int coords [2]={10,0};
    QPainterPath p_path;
    const int sizes[8][2]={
            {0,0},
            {60,40},
            {60,40},
            {80,20},
            {60,40},
            {40,40},
            {40,60},
            {40,60}
        };
    int piece_size [2]={0,0};
    int rot_pos=0;
    QVector<PieceSmall*> pieces_s;


};



#endif // PIECE_H
