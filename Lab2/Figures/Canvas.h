#ifndef CANVAS_H
#define CANVAS_H

/////////////////////////  Canvas  ///////////////////////////

//Canvas Constants
const int CANVAS_WIDTH = 30;
const int CANVAS_HEIGHT = 30;

const char PIXEL_ON = '#';
const char PIXEL_OFF = ' ';

class Canvas {
  //OVERVIEW:  A Canvas object represents a 2D grid of "pixels"
  //           which can be set to either "on" or "off".  A Canvas
  //           knows how to print itself out to the terminal.  The
  //           canvas has a fixed width and height and the origin
  //           (0,0) of the canvas's coordinate system is at the
  //           bottom left.

public:

  //EFFECTS: creates a new Canvas with size CANVAS_WIDTH x CANVAS_HEIGHT
  Canvas();

  //REQUIRES: the pixel is on the canvas (0 <= x < CANVAS_WIDTH, 0 <= y < CANVAS_HEIGHT)
  //MODIFIES: grid
  //EFFECTS: if value is true, turns the pixel at (x,y) on
  //         if value is false, turns the pixel at (x,y) off
  void setPixel(int x, int y, bool value);

  //EFFECTS: prints this canvas to cout
  void print() const;

private:
  
  bool grid[CANVAS_HEIGHT][CANVAS_WIDTH];

};

////////////////////////// End Canvas /////////////////////////



#endif /* CANVAS_H */
