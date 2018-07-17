#include "piece.h"
#include "piece_small.h"

Piece::Piece(QObject *parent):
    QObject(parent),QGraphicsItem()
{


}

Piece::~Piece()
{

}

void Piece::moving(int pos_x, int pos_y)
{
    //    enum TetrixShape { ZShape, SShape, LineShape, TShape, SquareShape,
    //                       LShape, MirroredLShape };
    if (moveEn)
    {
    coords[0]=coords[0]+pos_x;
    coords[1]=coords[1]+pos_y;

  
//    if (pos_y>0&&collidesWithPath(p_path))
//    {
//        coords[1]=coords[1]-pos_y;
//        setPos(coords[0],coords[1]);
//        moveEn=false;
//        emit signalNewPiece();
//    }
//    if (pos_rot==0&&coords[0]+piece_size[0]>21)
    if (coords[0]+piece_size[0]/20>21)
    {
        coords[0]=coords[0]-pos_x;
        setPos(coords[0],coords[1]);
    }
//    if (pos_rot==0&&coords[0]<=0)
    if (coords[0]<=0)
    {
        coords[0]=0;
        setPos(coords[0],coords[1]);
    }
//    if (pos_rot==2&&coords[0]<=2)
//    {
//        coords[0]=2;
//        setPos(coords[0],coords[1]);
//    }
//    if (pos_rot==2&&coords[0]+piece_size[0]>21)
//    {
//        coords[0]=21-piece_size[0];
//        setPos(coords[0],coords[1]);
//    }
//    if (pos_rot==1&&coords[0]+piece_size[0]>21)
//    {
//        coords[0]=coords[0]-pos_x;
//    }
//    if (pos_rot==1&&coords[0]<=0)
//    {
//        coords[0]=0;
//    }
//    if (pos_rot==3&&coords[0]-piece_size[0]<=0)
//    {
//        coords[0]=piece_size[0]+pos_x;
//    }
//    if (pos_rot==3&&coords[0]>21)
//    {
//        coords[0]=coords[0]-pos_x;
//        setPos(coords[0],coords[1]);
//    }

//    if ((pos_rot==0||pos_rot==3)&&coords[1]+piece_size[1]>33)
    if (coords[1]+piece_size[1]/20>33)
    {
        coords[1]=coords[1]-pos_y;
        setPos(coords[0],coords[1]);
        moveEn=false;
        emit addPiece();
        emit signalNewPiece();
    }
//    if ((pos_rot==1||pos_rot==2)&&coords[1]+piece_size[1]>33)
//    {
//        coords[1]=33;
//        setPos(coords[0],coords[1]);
//        moveEn=false;
//        emit signalNewPiece();
//    }
//    if (pos_rot==2&&coords[1]+piece_size[1]>33)
//    {
//        coords[1]=32;
//    }
//    if (pos_rot==3&&coords[1]+piece_size[1]>33)
//    {
//        coords[1]=coords[1]-pos_y;
//    }
//    if (coords[1]>=32)
//    {
//        moveEn=false;
//        emit signalNewPiece();
//    }
    setPos(coords[0],coords[1]);
    }
    setCoords(coords[0],coords[1]);
 }


bool Piece::collidesWithPath(const PieceSmall *item, Qt::ItemSelectionMode mode) const
{
    QPainterPath path=mapFromItem(item,item->shape());
    if (path.isEmpty()) {
        // No collision with empty paths.
        return false;
    }

    QRectF rectA(boundingRect());
  //  _q_adjustRect(rectA);
    QRectF rectB(path.controlPointRect());
   // _q_adjustRect(rectB);
    if (!rectA.intersects(rectB)) {
        // This we can determine efficiently. If the two rects neither
        // intersect nor contain eachother, then the two items do not collide.
        return false;
    }

    // For further testing, we need this item's shape or bounding rect.
    QPainterPath thisShape=shape();


    if (thisShape == QPainterPath()) {
        // Empty shape? No collision.
        return false;
    }

    // Use QPainterPath boolean operations to determine the collision, O(N*logN).
    if (mode == Qt::IntersectsItemShape)
        return path.intersects(thisShape);
    return path.contains(thisShape);
}

QVector<PieceSmall *> Piece::getPieces_s()
{
    return pieces_s;
}

void Piece::vec_PS_clear()
{
    pieces_s.clear();
}




void Piece::reset()
{

}

int Piece::getX()
{
    return this->coords[0];
}

int Piece::getY()
{
    return this->coords[1];
}

void Piece::setCoords(int pos_x, int pos_y)
{
    this->setX(pos_x*20);
    this->setY(pos_y*20);
}

void Piece::setShape_T(int type_shape)
{
    shape_T=type_shape;
}


void Piece::unrotate_piece()
{


        rot_pos++;
//    setTransformOriginPoint(20,20);
//    setRotation(rotation()-90);

    int temp=piece_size[0];
    piece_size[0]=piece_size[1];
    piece_size[1]=temp;

   for (int i=0;i<4;i++)
   {
       int x,y;
       x=coordsPiece[i][0];
       y=coordsPiece[i][1];
       coordsPiece[i][0]=y;
       coordsPiece[i][1]=-x+piece_size[1]-20;
   }

   for (int i=0;i<11;i++)
   {
       int x,y;
       x=coordsShape[i][0];
       y=coordsShape[i][1];
       coordsShape[i][0]=y;
       coordsShape[i][1]=-x+piece_size[1];
   }
//   const int coordsTable [8][4][2]={
//       {{0,0},{0,0},{0,0},{0,0}},
//       {{0,0},{1,0},{1,1},{2,1}},
//       {{1,0},{2,0},{0,1},{1,1}},
//       {{0,0},{1,0},{2,0},{3,0}},
//       {{1,0},{0,1},{1,1},{2,1}},
//       {{0,0},{1,0},{0,1},{1,1}},
//       {{0,2},{1,0},{1,1},{1,2}},
//       {{0,0},{0,1},{0,2},{1,2}}
//   };

//   const int coordsTableShapes[8][11][2]={
//       {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
//       {{1,1},{20,1},{39,1},{39,21},{59,21},{59,39},{40,39},{21,39},{21,19},{1,19},{1,1}},
//       {{21,1},{40,1},{59,1},{59,19},{39,19},{39,39},{20,39},{1,39},{1,21},{21,21},{21,1}},
//       {{1,1},{20,1},{40,1},{60,1},{79,1},{79,19},{60,19},{40,19},{20,19},{1,19},{1,1}},
//       {{21,1},{39,1},{39,21},{59,21},{59,39},{40,39},{20,39},{1,39},{1,21},{21,21},{21,1}},
//       {{1,1},{20,1},{39,1},{39,20},{39,39},{20,39},{1,39},{1,20},{1,1},{1,1},{1,1}},
//       {{1,41},{21,41},{21,20},{21,1},{39,1},{39,20},{39,40},{39,59},{20,59},{1,59},{1,41}},
//       {{1,1},{19,1},{19,20},{19,41},{39,41},{39,59},{20,59},{1,59},{1,40},{1,20},{1,1}}
//   }
   setCoords(coords[0],coords[1]);
   moving(0,0);

    p_path=shape();
    //setTransformOriginPoint(0,0);

}


void Piece::rotate_piece()
{
    if (moveEn&&shape_T!=5&&coords[1]+piece_size[0]/20<33&coords[0]+piece_size[0]/20<21)
    {

        rot_pos++;
//    setTransformOriginPoint(20,20);
//    setRotation(rotation()-90);

    int temp=piece_size[0];
    piece_size[0]=piece_size[1];
    piece_size[1]=temp;

   for (int i=0;i<4;i++)
   {
       int x,y;
       x=coordsPiece[i][0];
       y=coordsPiece[i][1];
       coordsPiece[i][0]=-y+piece_size[0]-20;
       coordsPiece[i][1]=x;
   }

   for (int i=0;i<11;i++)
   {
       int x,y;
       x=coordsShape[i][0];
       y=coordsShape[i][1];
       coordsShape[i][0]=-y+piece_size[0];
       coordsShape[i][1]=x;
   }
//   const int coordsTable [8][4][2]={
//       {{0,0},{0,0},{0,0},{0,0}},
//       {{0,0},{1,0},{1,1},{2,1}},
//       {{1,0},{2,0},{0,1},{1,1}},
//       {{0,0},{1,0},{2,0},{3,0}},
//       {{1,0},{0,1},{1,1},{2,1}},
//       {{0,0},{1,0},{0,1},{1,1}},
//       {{0,2},{1,0},{1,1},{1,2}},
//       {{0,0},{0,1},{0,2},{1,2}}
//   };

//   const int coordsTableShapes[8][11][2]={
//       {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
//       {{1,1},{20,1},{39,1},{39,21},{59,21},{59,39},{40,39},{21,39},{21,19},{1,19},{1,1}},
//       {{21,1},{40,1},{59,1},{59,19},{39,19},{39,39},{20,39},{1,39},{1,21},{21,21},{21,1}},
//       {{1,1},{20,1},{40,1},{60,1},{79,1},{79,19},{60,19},{40,19},{20,19},{1,19},{1,1}},
//       {{21,1},{39,1},{39,21},{59,21},{59,39},{40,39},{20,39},{1,39},{1,21},{21,21},{21,1}},
//       {{1,1},{20,1},{39,1},{39,20},{39,39},{20,39},{1,39},{1,20},{1,1},{1,1},{1,1}},
//       {{1,41},{21,41},{21,20},{21,1},{39,1},{39,20},{39,40},{39,59},{20,59},{1,59},{1,41}},
//       {{1,1},{19,1},{19,20},{19,41},{39,41},{39,59},{20,59},{1,59},{1,40},{1,20},{1,1}}
//   }
   setCoords(coords[0],coords[1]);
   moving(0,0);
    }
    p_path=shape();
    //setTransformOriginPoint(0,0);
}



void Piece::setmoveEn(bool m_En)
{
    moveEn=m_En;
}


QPainterPath Piece::shape() const
{
    QPainterPath path;
    QVector<QPointF> points;


    for (int i=0;i<10;i++)
    {
        points.push_back(QPointF(coordsShape[i][0],coordsShape[i][1]));
    }
    QPolygonF poligon=QPolygonF(points);

    path.addPolygon(poligon);
    return path;
}



QRectF Piece::boundingRect() const
{

    return QRectF(0,0,80,80);


}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    static const QBrush colorTable[8] = {
        Qt::NoBrush,
        Qt::green, Qt::red, Qt::blue,
        Qt::darkBlue, Qt::cyan, Qt::yellow, Qt::magenta
    };
    pieces_s.clear();
    PieceSmall *ps;

   // QPointF points [4];
    painter->setBrush(colorTable[shape_T]);
    setCoords(coords[0],coords[1]);
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<2;j++)
        {
            if (pieceCreating)
                coordsPiece[i][j]=coordsTable[shape_T][i][j];
        }
      //  points[i]=QPointF(coordsPiece[i][0],coordsPiece[i][1]);
        ps=new PieceSmall();
        ps->setBrush(colorTable[shape_T]);
        ps->setX(coordsPiece[i][0]);
        ps->setY(coordsPiece[i][1]);


        //painter->drawPath(ps->shape());
        ps->setPos(mapToParent(coordsPiece[i][0],coordsPiece[i][1]));

        pieces_s.push_back(ps);
        painter->drawRect(coordsPiece[i][0],coordsPiece[i][1],20,20);
    }

    //foreach (PieceSmall* item, pieces_s)
    for (int i=0;i<11;i++)
    {
        for (int j=0;j<2;j++)
        {
            if (pieceCreating) coordsShape[i][j]=coordsTableShapes[shape_T][i][j];
        }

    }

    if (pieceCreating)
    {
    piece_size[0]=sizes[shape_T][0];
    piece_size[1]=sizes[shape_T][1];
    }
    pieceCreating=false;
   // setCoords(coords[0],coords[1]);
    //painter->drawPath(shape());

    //painter->drawPolygon(points,coordsTable[shape_T][10][0],Qt::OddEvenFill);
}


