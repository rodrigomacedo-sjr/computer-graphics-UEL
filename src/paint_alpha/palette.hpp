#ifndef PALETTE_H
#define PALETTE_H

#include <vector>

#include <string>

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

typedef struct RGBColor {
  std::string name;
  double r, g, b;
} RGBColor;

const RGBColor RED = {"Red", 1.0, 0.0, 0.0};
const RGBColor GREEN = {"Green", 0.0, 1.0, 0.0};
const RGBColor BLUE = {"Blue", 0.0, 0.0, 1.0};
const RGBColor YELLOW = {"Yellow", 1.0, 1.0, 0.0};
const RGBColor PINK = {"Pink", 1.0, 0.0, 1.0};
const RGBColor CYAN = {"Cyan", 0.0, 1.0, 1.0};
const RGBColor WHITE = {"White", 1.0, 1.0, 1.0};
const RGBColor BLACK = {"Black", 0.0, 0.0, 0.0};
const RGBColor ORANGE = {"Orange", 1.0, 0.647, 0.0};
const RGBColor PURPLE = {"Purple", 0.627, 0.125, 0.941};
const RGBColor BROWN = {"Brown", 0.59, 0.29, 0.0};

class Pallete {
private:
  int sq_size;
  float sq_spacing_ratio;
  std::pair<int, int> origin_coord;
  std::vector<RGBColor> colors = {RED,    GREEN, BLUE, YELLOW,
                                  PINK, CYAN,  WHITE};

  bool inside(int x, int y, int sq_origin_x, int sq_origin_y);

public:
  Pallete(int s, float r);
  void draw_self(int x, int y);
  RGBColor test_mouse(int x, int y, RGBColor current_color);
};

#endif
