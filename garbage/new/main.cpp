#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Button Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Rect buttonRect;
    buttonRect.x = 300;
    buttonRect.y = 200;
    buttonRect.w = 200;
    buttonRect.h = 100;

    bool isButtonClicked = false;

    while (!isButtonClicked)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                //case SDL_QUIT:
                //    isButtonClicked = true;
                //    break;

                case SDL_MOUSEBUTTONUP:
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    if (x > buttonRect.x && x < buttonRect.x + buttonRect.w && y > buttonRect.y && y < buttonRect.y + buttonRect.h)
                    {
                        isButtonClicked = true;
                        std::cout << "Button clicked!" << std::endl;
                    }
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &buttonRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
