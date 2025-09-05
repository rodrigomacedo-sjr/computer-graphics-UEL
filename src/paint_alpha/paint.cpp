#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <format>
#include <string>

int init(void);
void display(void);
void handle_keyboard(GLubyte key, GLint x, GLint y);
void handle_motion(GLint x, GLint y);

// TODO: move this somewhere better
const std::string PROGRAM_NAME = "PAINT_ALPHA";
const std::string VERSION = "1.0";

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(640, 480);

  glutInitWindowPosition(100, 100);

  glutCreateWindow(format("{}_{}", PROGRAM_NAME, VERSION).c_str());

  init();

  glutDisplayFunc(display);

  glutKeyboardFunc(handle_keyboard);

  glutMotionFunc(handle_motion);

  glutMainLoop();

  return 0;
}

int init(void) {

  glClearColor(1.0, 1.0, 1.0, 0.0);

  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, 640.0, 0.0, 480.0);

  return 0;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_QUADS);
  glVertex2f(100, 200);
  glVertex2f(200, 200);
  glVertex2f(100, 100);
  glVertex2f(200, 100);
  glEnd();

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
