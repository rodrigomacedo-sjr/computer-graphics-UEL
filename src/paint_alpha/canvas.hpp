#ifndef CANVAS_H
#define CANVAS_H

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "palette.hpp"

class Canvas {
private:
public:
  RGBColor current_color = WHITE;
  void clear(void);
  void set_color(RGBColor new_color);
  void draw_point(int x, int y);
};

#endif
