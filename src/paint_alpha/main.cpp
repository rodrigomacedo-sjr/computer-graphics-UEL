#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "canvas.hpp"
#include "config.hpp"
#include "palette.hpp"

// TODO: improve this somehow
bool drawing = false;
bool erasing = false;
bool lining = false;
bool squaring = false;
bool spraying = false;
bool figuring = false;
Mode mode = NORMAL;

void display(void);
void handle_keyboard(GLubyte key, GLint x, GLint y);
void handle_mouse(GLint button, GLint action, GLint x, GLint y);
void handle_motion(GLint x, GLint y);
void create_menu();
void handle_submenu(GLint op);

Pallete palette = Pallete(PALETTE_SIZE, PALETTE_SPACING);
Canvas canvas = Canvas();

int main(int argc, char *argv[]) {
  init(argc, argv);

  create_menu();

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

  glColor3f(canvas.current_color.r, canvas.current_color.g,
            canvas.current_color.b);

  glFlush();

  return;
}

// Clear screen on pressing 'd'
void handle_keyboard(GLubyte key, GLint x, GLint y) {
  if (key == 'd') {
    canvas.clear();
    palette.draw_self(10, WINDOW_HEIGHT - PALETTE_SIZE - 10);
    glFlush();
  }
}

// TODO: improve this A LOT
void handle_mouse(GLint button, GLint action, GLint x, GLint y) {
  GLint m = glutGetModifiers();

  if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN &&
      (m & GLUT_ACTIVE_SHIFT)) {
    // Erasing
    erasing = true;
  } else if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
    // Drawing
    canvas.current_color =
        palette.test_mouse(x, WINDOW_HEIGHT - y, canvas.current_color);

    switch (mode) {
    case NORMAL:
      drawing = true;
      break;
    case SPRAY:
      spraying = true;
      break;
    case LINE:
      if (!lining)
        canvas.start_lining(x, WINDOW_HEIGHT - y);
      lining = true;
      break;
    case SQUARE:
      if (!squaring)
        canvas.start_squaring(x, WINDOW_HEIGHT - y);
      squaring = true;
      break;
    case FIGURE:
      figuring = true;
      canvas.draw_figure(x, WINDOW_HEIGHT - y, 10);
    }

  } else if (button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
    if (erasing)
      erasing = false;
    else if (drawing)
      drawing = false;
    else if (spraying)
      spraying = false;
    else if (lining) {
      canvas.end_lining(x, WINDOW_HEIGHT - y);
      lining = false;

    } else if (squaring) {
      canvas.end_squaring(x, WINDOW_HEIGHT - y);
      squaring = false;

    } else if (figuring)
      figuring = false;
  }
}

void handle_motion(GLint x, GLint y) {
  if (erasing)
    canvas.erase_point(x, WINDOW_HEIGHT - y);
  else if (spraying)
    canvas.spray_point(x, WINDOW_HEIGHT - y);
  else if (drawing)
    canvas.draw_point(x, WINDOW_HEIGHT - y);
}

// TODO: move this somewhere else
void create_menu() {
  GLint menu, submenu1, submenu2;
  submenu1 = glutCreateMenu(handle_submenu);
  glutAddMenuEntry("normal", 0);
  glutAddMenuEntry("line", 1);
  glutAddMenuEntry("spray", 2);
  glutAddMenuEntry("square", 3);
  glutAddMenuEntry("stamp", 4);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void handle_submenu(GLint op) {
  switch (op) {
  case 0:
    mode = NORMAL;
    break;
  case 1:
    mode = LINE;
    break;
  case 2:
    mode = SPRAY;
    break;
  case 3:
    mode = SQUARE;
    break;
  case 4:
    mode = FIGURE;
    break;
  }
}
