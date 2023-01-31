#include <iostream>
#include <GL/glut.h>

bool buttonPressed = false;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  if (buttonPressed) {
    glColor3f(1.0, 0.0, 0.0); // Change color to red when button is pressed
  } else {
    glColor3f(0.0, 1.0, 0.0); // Change color to green when button is not pressed
  }

  glRectf(-0.5, 0.5, 0.5, -0.5); // Draw a rectangle for the button

  glFlush();
}

void mouseClick(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    buttonPressed = !buttonPressed; // Toggle the buttonPressed variable
    glutPostRedisplay();
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Button using OpenGL");
  glutDisplayFunc(display);
  glutMouseFunc(mouseClick);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glutMainLoop();
  return 0;
}
