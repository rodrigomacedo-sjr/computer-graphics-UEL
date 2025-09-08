#include "palette.hpp"
#include <iostream>

Pallete::Pallete(int s, float r) {
  sq_size = s;
  sq_spacing_ratio = r;
}

void Pallete::draw_self(int x, int y) {
  origin_coord.first = x;
  origin_coord.second = y;

  int i = 0;
  for (auto color : colors) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(x + i * sq_spacing_ratio * sq_size, y);
    glVertex2f(x + i * sq_spacing_ratio * sq_size, sq_size + y);
    glVertex2f(sq_size + x + i * sq_spacing_ratio * sq_size, sq_size + y);
    glVertex2f(sq_size + x + i * sq_spacing_ratio * sq_size, y);
    glEnd();

    i++;
  }
}

bool Pallete::inside(int x, int y, int sq_origin_x, int sq_origin_y) {
  return x >= sq_origin_x && x <= sq_origin_x + sq_size && y >= sq_origin_y &&
         y <= sq_origin_y + sq_size;
}

RGBColor Pallete::test_mouse(int x, int y, RGBColor current_color) {
  for (int i = 0; i < colors.size(); i++) {
    int this_color_origin_x =
        origin_coord.first + i * sq_spacing_ratio * sq_size;
    int this_color_origin_y = origin_coord.second;

    if (inside(x, y, this_color_origin_x, this_color_origin_y)) {
      return colors[i];
    }
  }
  return current_color;
}
