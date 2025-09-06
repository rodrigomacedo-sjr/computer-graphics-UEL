#include "palette.hpp"

Pallete::Pallete(int s) { size = s; }

void Pallete::draw_self(int x, int y) {
  int i = 0;
  for (auto color : colors) {

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(x + i * 1.5 * size, y);
    glVertex2f(x + i * 1.5 * size, size + y);
    glVertex2f(size + x + i * 1.5 * size, size + y);
    glVertex2f(size + x + i * 1.5 * size, y);
    glEnd();

    i++;
  }
}
