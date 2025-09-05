#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int init(void);
void display(void);

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(640, 480);

  glutInitWindowPosition(100, 100);

  glutCreateWindow("Silly House");

  init();

  glutDisplayFunc(display);

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

  // Chimney
  glColor3f(0.3, 0.3, 0.3);
  glBegin(GL_QUAD_STRIP);
  glVertex2f(200, 460);
  glVertex2f(240, 460);
  glVertex2f(200, 300);
  glVertex2f(240, 300);
  glEnd();

  // Roof
  glColor3f(0.8, 0.1, 0.1);
  glBegin(GL_TRIANGLES);
  glVertex2f(320, 440);
  glVertex2f(170, 300);
  glVertex2f(470, 300);
  glEnd();

  // Wall
  glColor3f(0.3, 0.3, 0.3);
  glBegin(GL_QUAD_STRIP);
  glVertex2f(170, 300);
  glVertex2f(470, 300);
  glVertex2f(170, 50);
  glVertex2f(470, 50);
  glEnd();

  // Window
  glColor3f(0.5, 0.5, 0.9);
  glBegin(GL_QUAD_STRIP);
  glVertex2f(350, 235);
  glVertex2f(430, 235);
  glVertex2f(350, 155);
  glVertex2f(430, 155);
  glEnd();

  // Door
  glColor3f(0.5, 0.5, 0.9);
  glBegin(GL_QUAD_STRIP);
  glVertex2f(220, 200);
  glVertex2f(290, 200);
  glVertex2f(220, 50);
  glVertex2f(290, 50);
  glEnd();

  glFlush();

  return;
}

