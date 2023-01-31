#include <SDL2/SDL.h>
#include <GL/gl.h>

int main()
{
  // Initialization of SDL
  SDL_Window *window;
  SDL_GLContext context;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: Unable to initialize SDL\n");
        return -1;
  }

  // Create a SDL window
  window = SDL_CreateWindow("My SDL Window", SDL_WINDOWPOS_CENTERED,
  			  SDL_WINDOWPOS_CENTERED, 640, 480,
  			  SDL_WINDOW_OPENGL);

  // Create a GL context
  context = SDL_GL_CreateContext(window);

  // Initialize OpenGL
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 640, 480, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Create a rounded button in the middle
  GLfloat x = 320.0f;
  GLfloat y = 240.0f;
  GLfloat radius = 50.0f;

  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y);
  for(int i=0; i<=360; i++) {
  	glVertex2f(x+(radius*cos(i)), y+(radius*sin(i)));
  }
  glEnd();

  // Event loop
  SDL_Event event;
  while(SDL_WaitEvent(&event)) {
  	if(event.type == SDL_QUIT || event.type == SDL_MOUSEBUTTONDOWN) {
  		// Show a message when user click on the button
  		printf("Button clicked!\n");
  		break;
  	}
  }

  // Clean up
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
