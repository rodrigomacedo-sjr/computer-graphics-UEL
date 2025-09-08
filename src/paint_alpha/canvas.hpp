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
  void draw_point(int x, int y);
};

#endif
