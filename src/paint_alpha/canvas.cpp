#include "canvas.hpp"
#include <GL/gl.h>

void Canvas::clear(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void Canvas::set_color(RGBColor color) { glColor3f(color.r, color.g, color.b); }

void Canvas::draw_point(int x, int y) {
  glColor3f(current_color.r, current_color.g, current_color.b);
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
  glFlush();
}
