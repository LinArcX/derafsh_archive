#include <iostream>
#include <GL/glut.h>
#include <cmath>

const int num_segments = 50; // number of segments to draw the circle
bool buttonPressed = false;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  if (buttonPressed) {
    glColor3f(1.0, 0.0, 0.0); // Change color to red when button is pressed
  } else {
    glColor3f(0.0, 1.0, 0.0); // Change color to green when button is not pressed
  }

  // Draw a rounded button
  glBegin(GL_POLYGON);

  // Top-left corner
  for(int i = 0; i < num_segments; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
    float x = 0.25f * cosf(theta) + 0.5f;
    float y = 0.25f * sinf(theta) + 0.5f;
    glVertex2f(x, y);
  }

 // Top-right corner
  for(int i = 0; i < num_segments; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
    float x = 0.75f * cosf(theta) + 0.5f;
    float y = 0.25f * sinf(theta) + 0.5f;
    glVertex2f(x, y);
  }

  // Bottom-right corner
  for(int i = 0; i < num_segments; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
    float x = 0.75f * cosf(theta) + 0.5f;
    float y = 0.75f * sinf(theta) + 0.5f;
    glVertex2f(x, y);
  }

  // Bottom-left corner
  for(int i = 0; i < num_segments; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
    float x = 0.25f * cosf(theta) + 0.5f;
    float y = 0.75f * sinf(theta) + 0.5f;
    glVertex2f(x, y);
  }

  //for(int i = 0; i < num_segments; i++) {
  //  float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
  //  float x = 0.9f * cosf(theta);
  //  float y = 0.9f * sinf(theta);
  //  glVertex2f(x, y);
  //}
  glEnd();

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
  glutCreateWindow("Rounded Button using OpenGL");
  glutDisplayFunc(display);
  glutMouseFunc(mouseClick);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glutMainLoop();
  return 0;
}
