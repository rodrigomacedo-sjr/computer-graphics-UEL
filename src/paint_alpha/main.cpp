#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "config.hpp"
#include "palette.hpp"

void display(void);
void handle_keyboard(GLubyte key, GLint x, GLint y);
void handle_motion(GLint x, GLint y);

Pallete palette = Pallete(PALETTE_SIZE);

int main(int argc, char *argv[]) {
  init(argc, argv);

  glutDisplayFunc(display);

  glutKeyboardFunc(handle_keyboard);

  glutMotionFunc(handle_motion);

  glutMainLoop();

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
