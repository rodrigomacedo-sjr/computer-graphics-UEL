#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <format>
#include <string>

#include "palette.hpp"

int init(void);
void display(void);
void handle_keyboard(GLubyte key, GLint x, GLint y);
void handle_motion(GLint x, GLint y);

// TODO: move this somewhere better 
const std::string PROGRAM_NAME = "PAINT_ALPHA";
const std::string VERSION = "1.0";
const int WINDOW_LENGTH = 800;
const int WINDOW_HEIGHT = 640;
const int PALETTE_SIZE = 50;

Pallete palette = Pallete(PALETTE_SIZE);

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(WINDOW_LENGTH, WINDOW_HEIGHT);

  glutInitWindowPosition(100, 100);

  glutCreateWindow(std::format("{}_{}", PROGRAM_NAME, VERSION).c_str());

  init();

  glutDisplayFunc(display);

  glutKeyboardFunc(handle_keyboard);

  glutMotionFunc(handle_motion);

  glutMainLoop();

  return 0;
}

int init(void) {

  glClearColor(0.0, 0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, WINDOW_LENGTH, 0.0, WINDOW_HEIGHT);

  return 0;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  palette.draw_self(10, WINDOW_HEIGHT - PALETTE_SIZE - 10);

  glFlush();

  return;
}

// Clear screen on pressing 'd'
void handle_keyboard(GLubyte key, GLint x, GLint y) {
  GLint m = glutGetModifiers();
  if (key == 'd') {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
  }
}

void handle_motion(GLint x, GLint y) {
  glBegin(GL_POINT);
  glVertex2f(x, y);
  glEnd();
  glFlush();
}
