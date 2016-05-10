#include "wolf3d.h"

int main(int ac, char **av)
{

	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;

	window = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Error when init sdl video: %s\n", SDL_GetError());
		return (1);
	}
	window = SDL_CreateWindow("SDL Tuto", posX, posY,
								sizeX, sizeY, SDL_WINDOW_SHOWN);
	if (!window)
	{
		fprintf(stderr, "Error creating a window");
		return (1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		fprintf(stderr, "Error create a renderer");
		return (1);
	}
	int running = 1;

	SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	while (running)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				running = 0;
			else if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					running = 0;
				}
			}
		}
		//SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
