#ifndef CONFIG_H
#define CONFIG_H

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <string>
#include <vector>
#include <format>

const std::string PROGRAM_NAME = "PAINT_ALPHA";
const std::string VERSION = "1.0";
const int WINDOW_LENGTH = 800;
const int WINDOW_HEIGHT = 640;
const int PALETTE_SIZE = 50;
const float PALETTE_SPACING = 1.5;
const float MY_POINT_SIZE = 8.0;
const std::vector<float> BG_COLOR = {0.0, 0.0, 0.0, 0.0};

int init(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(WINDOW_LENGTH, WINDOW_HEIGHT);

  glutInitWindowPosition(100, 100);

  glutCreateWindow(format("{}_{}", PROGRAM_NAME, VERSION).c_str());

  glPointSize(MY_POINT_SIZE);

  // TODO: improve this
  glClearColor(BG_COLOR[0], BG_COLOR[1], BG_COLOR[2], BG_COLOR[3]);

  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, WINDOW_LENGTH, 0.0, WINDOW_HEIGHT);

  return 0;
}

#endif
