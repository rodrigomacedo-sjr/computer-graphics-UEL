#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "canvas.hpp"
#include "config.hpp"
#include "palette.hpp"

// TODO: improve this somehow
bool drawing = false;

void display(void);
void handle_keyboard(GLubyte key, GLint x, GLint y);
void handle_mouse(GLint button, GLint action, GLint x, GLint y);
void handle_motion(GLint x, GLint y);

Pallete palette = Pallete(PALETTE_SIZE, PALETTE_SPACING);
Canvas canvas = Canvas();

int main(int argc, char *argv[]) {
  init(argc, argv);

  glutDisplayFunc(display);

  glutKeyboardFunc(handle_keyboard);

  glutMouseFunc(handle_mouse);

  glutMotionFunc(handle_motion);

  glutMainLoop();

  return 0;
}

void display(void) {
  canvas.clear();

  palette.draw_self(10, WINDOW_HEIGHT - PALETTE_SIZE - 10);

  glColor3f(canvas.current_color.r, canvas.current_color.g, canvas.current_color.b);

  glFlush();

  return;
}

// Clear screen on pressing 'd'
void handle_keyboard(GLubyte key, GLint x, GLint y) {
  GLint m = glutGetModifiers();
  if (key == 'd') {
    canvas.clear();
    palette.draw_self(10, WINDOW_HEIGHT - PALETTE_SIZE - 10);
    glFlush();
  }
}

void handle_mouse(GLint button, GLint action, GLint x, GLint y) {
  if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
    canvas.current_color = palette.test_mouse(x, WINDOW_HEIGHT - y, canvas.current_color);
    drawing = true;
  } else if (button == GLUT_LEFT_BUTTON && action == GLUT_UP)
    drawing = false;
}

void handle_motion(GLint x, GLint y) {
  if (drawing)
    canvas.draw_point(x, WINDOW_HEIGHT - y);
}
