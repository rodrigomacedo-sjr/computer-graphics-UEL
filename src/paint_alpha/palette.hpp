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
const RGBColor PURPLE = {"Purple", 1.0, 0.0, 1.0};
const RGBColor CYAN = {"Cyan", 0.0, 1.0, 1.0};
const RGBColor WHITE = {"White", 1.0, 1.0, 1.0};

class Pallete {
private:
  int size;
  std::vector<RGBColor> colors = {RED, GREEN, BLUE, YELLOW, PURPLE, CYAN, WHITE};

public:
  Pallete(int s);
  void draw_self(int x, int y);
};

#endif
