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
	init_window_info(w, 100, 200, 300, 400);
	if (create_window(w, "Wolf 3D", SDL_WINDOW_SHOWN) < 0)
		return (EXIT_ERROR);
	else if (create_renderer(w, FIRST_MATCH, SDL_RENDERER_ACCELERATED) < 0)
		return (EXIT_ERROR);
	setup_renderer(w, &c);
	return (0);
}

void	setup_renderer(t_winfo *w, t_color *c)
{
	SDL_RenderSetLogicalSize(w->renderer, w->size.x, w->size.y);
	SDL_SetRenderDrawColor(w->renderer, c->r, c->g, c->b, c->a);
}

void	render(t_winfo *w, SDL_Rect *player_pos)
{
	SDL_SetRenderDrawColor(w->renderer, 0, 0, 255, 255);
	SDL_RenderClear(w->renderer);
	SDL_SetRenderDrawColor(w->renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(w->renderer, player_pos);
	SDL_RenderPresent(w->renderer);
}

void	quit(t_winfo *w)
{
	SDL_DestroyRenderer(w->renderer);
	SDL_DestroyWindow(w->window);
	free(w);
	SDL_Quit();
}
