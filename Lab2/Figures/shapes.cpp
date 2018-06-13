#include <cassert>
#include <cmath>
#include "shapes.h"

using namespace std;

const double PI = 3.14159;

//////////////////////////  Ellipse  //////////////////////////

Ellipse::Ellipse(double xRad_in, double yRad_in)
  : xRad(xRad_in), yRad(yRad_in) {}
//Ellipse::Ellipse(double Rad_in)
 // : xRad(Rad_in), yRad(Rad_in) {}


double Ellipse::area() const {
  return PI * xRad * yRad;
}

void Ellipse::draw(Canvas *canvas) const{
  // Iterate through the grid of (x,y) pixel coordinates
  // in the canvas.
  for(int x = 0; x < CANVAS_WIDTH; ++x){
    for(int y = 0; y < CANVAS_HEIGHT; ++y){

      // The ellipse contains the point (x,y) if and only if
      // ((x-xPos)/xRad)^2 + ((y-yPos)/yRad)^2 <= 1

      double xDiff = x - get_xPos();
      double yDiff = y - get_yPos();

      if( (xDiff/xRad)*(xDiff/xRad) + (yDiff/yRad)*(yDiff/yRad) <= 1 ){
        // If the pixel is contained in the ellipse, set it to true
        canvas->setPixel(x, y, true);
      }
    }
  }
}
        
///////////////////////// End Ellipse /////////////////////////



//////////////////////////  Circle  //////////////////////////


        
///////////////////////// End Circle /////////////////////////



////////////////////////  Rectangle  /////////////////////////

Rectangle::Rectangle(double a_in, double b_in)
  : a(a_in), b(b_in) {}


double Rectangle::area() const {
  return a*b;
}

void Rectangle::draw(Canvas *canvas) const{
  // Iterate through the grid of (x,y) pixel coordinates
  // in the canvas.
  for(int x = 0; x < CANVAS_WIDTH; ++x){
    for(int y = 0; y < CANVAS_HEIGHT; ++y){

      // The ellipse contains the point (x,y) if and only if
      // ((x-xPos)/xRad)^2 + ((y-yPos)/yRad)^2 <= 1

     double xDiff = x - get_xPos();
     double yDiff = y - get_yPos();

      if(xDiff>=0&&xDiff<a&&yDiff>=0&&yDiff<b){
        // If the pixel is contained in the ellipse, set it to true
        canvas->setPixel(x, y, true);
      }
    }
  }
}

//////////////////////// End Rectangle //////////////////////





















