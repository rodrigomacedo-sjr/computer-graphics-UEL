#ifndef CANVAS_H
#define CANVAS_H

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "palette.hpp"

enum Mode { NORMAL, SPRAY, LINE, SQUARE, FIGURE };

class Canvas {
private:
  std::pair<int, int> last_start = {0, 0};

public:
  RGBColor current_color = WHITE;
  void clear(void);
  void draw_point(int x, int y);
  void erase_point(int x, int y);
  void spray_point(int x, int y);
  void start_lining(int x, int y);
  void end_lining(int x, int y);
  void start_squaring(int x, int y);
  void end_squaring(int x, int y);
  void draw_figure(int x, int y, int size);
};

#endif
