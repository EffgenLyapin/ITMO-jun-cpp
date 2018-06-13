#include <iostream>
#include "shapes.h"
#include "shapes.cpp"
#include "Canvas.h"
#include "Canvas.cpp"

using namespace std;


// TASKS 1 AND 2 - ADD/MODIFY CODE IN MAIN AS DIRECTED
int main(){

  //Shape 1
 // Ellipse e1(3.0,5.0);
 // e1.setPosition(15,15);
 // Circle c1(5.0);
 // c1.setPosition(15,15);
    Rectangle r1(6.0,3.0);
    r1.setPosition(2,2);
  //Array of pointers to the shapes
  const int NUM_SHAPES = 1;
  //Ellipse* shapes[NUM_SHAPES] ={&c1}; //{&e1,&c1};
  //Circle* shapes[NUM_SHAPES] ={&c1}; //{&e1,&c1};
Rectangle* shapes[NUM_SHAPES] ={&r1}; //{&e1,&c1};


  //Draw the shapes to the canvas
  Canvas c;
  int i = 0;
 // for(Ellipse **s = shapes; s < shapes + NUM_SHAPES; ++s){
//   for(Circle **s = shapes; s < shapes + NUM_SHAPES; ++s){
  for(Rectangle **s = shapes; s < shapes + NUM_SHAPES; ++s){
    cout << "Area of shape " << ++i << ": " << (*s)->area() << endl;
    (*s)->draw(&c);
  }

  //Print out the canvas
  c.print();

}
