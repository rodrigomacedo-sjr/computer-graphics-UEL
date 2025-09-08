#include <GL/gl.h>
#include <cstdlib>

#include "canvas.hpp"

void Canvas::clear(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void Canvas::draw_point(int x, int y) {
  glColor3f(current_color.r, current_color.g, current_color.b);
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
  glFlush();
}

// TODO: improve this
void Canvas::erase_point(int x, int y) {
  glPointSize(15.0);
  glColor3f(BLACK.r, BLACK.g, BLACK.b);
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
  glFlush();
  glPointSize(8.0);
}

void Canvas::spray_point(int x, int y) {
  int r = random() % 10;
  glPointSize(1.0);
  glColor3f(current_color.r, current_color.g, current_color.b);
  glBegin(GL_POINTS);
  for (int i = 0; i < r; i++)
    glVertex2f(x + random() % 20 - 20, y + random() % 20 - 20);
  glEnd();
  glFlush();
  glPointSize(8.0);
}

void Canvas::start_lining(int x, int y) {
  last_start = {x, y};
  return;
}

void Canvas::end_lining(int x, int y) {
  glColor3f(current_color.r, current_color.g, current_color.b);
  glBegin(GL_LINES);
  glVertex2f(last_start.first, last_start.second);
  glVertex2f(x, y);
  glEnd();
  glFlush();
  return;
}

void Canvas::start_squaring(int x, int y) {
  last_start = {x, y};
  return;
}
void Canvas::end_squaring(int x, int y) {
  glColor3f(current_color.r, current_color.g, current_color.b);
  glBegin(GL_QUADS);
  glVertex2f(last_start.first, last_start.second);
  glVertex2f(x, last_start.second);
  glVertex2f(x, y);
  glVertex2f(last_start.first, y);
  glEnd();
  glFlush();
  return;
}
void Canvas::draw_figure(int x, int y, int size) {
  glColor3f(current_color.r, current_color.g, current_color.b);
  glBegin(GL_TRIANGLES);
  glVertex2f(x, size * 0.8 + y);
  glVertex2f(x + size, size * 0.8 + y - size * 2);
  glVertex2f(x - size, size * 0.8 + y - size * 2);

  glVertex2f(x, y - size * 2);
  glVertex2f(x + size, y);
  glVertex2f(x - size, y);
  glEnd();
  glEnd();
  glFlush();
  return;
}
