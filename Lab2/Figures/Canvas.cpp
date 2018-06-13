#include <iostream>
#include <cassert>
#include "Canvas.h"

using namespace std;

/////////////////////////  Canvas  ///////////////////////////

Canvas::Canvas(){
  for(int row = 0; row < CANVAS_HEIGHT; ++row){
    for(int col = 0; col < CANVAS_WIDTH; ++col){
      grid[row][col] = false;
    }
  } 
}

void Canvas::setPixel(int x, int y, bool value){
  assert(0 <= x); assert(x < CANVAS_WIDTH);
  assert(0 <= y); assert(y < CANVAS_HEIGHT);
  grid[y][x] = value;
}

void Canvas::print() const {
  for(int row = 0; row < CANVAS_HEIGHT; ++row){
    for(int col = 0; col < CANVAS_WIDTH; ++col){
      cout << (grid[CANVAS_HEIGHT-row-1][col] ? PIXEL_ON : PIXEL_OFF) << " ";
    }
    cout << endl;
  } 
}

////////////////////////// End Canvas /////////////////////////
