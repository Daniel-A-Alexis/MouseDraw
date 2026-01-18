#include <fstream>
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main()
{
  SDL_Event e;
  bool isRunning = true;
  
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* win = SDL_CreateWindow("Dans window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

  SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);
  
  SDL_Rect rect;

  Uint64 last = SDL_GetPerformanceCounter();
      
  while(isRunning)
    {
      
      Uint64 now = SDL_GetPerformanceCounter();
      double deltaTime = (double)(now-last) / (double)SDL_GetPerformanceFrequency();
      last=now;
	
      
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);
      
      rect = {100, 100, 10, 10};
  
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      SDL_RenderFillRect (renderer, &rect);

      SDL_RenderPresent(renderer);

      cout << deltaTime << "\n";
    }
  SDL_Delay (4000);
  
  SDL_DestroyWindow(win);
  SDL_Quit();

}
