#include <SDL2/SDL.h>

int main()
{
	int posX = 100;
	int	posY = 200;
	int sizeX = 300;
	int sizeY = 400;

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

	while (running)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				running = 0;
		}
		SDL_UpdateWindowSurface(window);
	}
	/* SDL_RenderSetLogicalSize(renderer, sizeX, sizeY); */
	/* SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); */
	/* SDL_RenderClear(renderer); */
	/* //should check screen return if NULL; */
	/* SDL_RenderPresent(renderer); */
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
