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
	else if (create_window(w, "Wolf 3D", NO_FLAG) < 0)
		return (EXIT_ERROR);
	else if (create_renderer(w, FIRST_MATCH, NO_FLAG) < 0)
		return (EXIT_ERROR);
	setup_renderer(w, &c);
	return (0);
}

void	setup_renderer(t_winfo *w, t_color *c)
{
	SDL_RenderSetLocalSize(w->renderer, w->size.x, w->size.y);
	SDL_RenderDrawColor(w->renderer, c->r, c->g, c->b, c->a);
}

void	render(t_winfo *w, SDL_Rect *player_pos)
{
	SDL_RenderClear(w->renderer);
	// set dynamic color
	SDL_SetRenderDrawColor(w->renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(w->renderer, &player_pos);
	SDL_RenderRenderDrawColor(w->renderer, 0, 255, 0, 255);
	SDL_RenderPresent(renderer);
}
