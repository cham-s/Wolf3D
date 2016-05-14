#include "wolf3d.h"

int	init_all(t_winfo *w)
{
	t_color		c;

	c.r = 0;
	c.g = 255;
	c.r = 0;
	c.r = 255;
	if (init_sdl() < 0)
		return (EXIT_ERROR);
	init_window_info(w, 100, 200, WIDTH, HEIGHT);
	if (create_window(w, "Wolf 3D", SDL_WINDOW_RESIZABLE) < 0)
		return (EXIT_ERROR);
	else if (create_renderer(w, FIRST_MATCH, SDL_RENDERER_SOFTWARE) < 0)
		return (EXIT_ERROR);
	clear_screen(w, &c);
	return (0);
}

void	clear_screen(t_winfo *w, t_color *c)
{
	SDL_SetRenderDrawColor(w->renderer, c->r, c->g, c->b, c->a);
	SDL_RenderClear(w->renderer);
}

void	quit(t_winfo *w)
{
	SDL_DestroyRenderer(w->renderer);
	SDL_DestroyWindow(w->window);
	free(w);
	SDL_Quit();
}
