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

// doing the drawing here
void	render(t_winfo *w, int y_pos)
{
	SDL_SetRenderDrawColor(w->renderer, 0, 0, 255, 255);
	SDL_RenderClear(w->renderer);
	SDL_SetRenderDrawColor(w->renderer, 255, 255, 255, 255);
	// test
	SDL_Point p;
	p.x = 0;
	p.y = 0;
	while (p.x < w->size.x)
	{
		while (p.y < w->size.y)
		{
			if (p.y == y_pos)
				SDL_RenderDrawPoint(w->renderer, p.x, p.y);
			p.y++;
		}
		p.y = 0;
		p.x++;
	}
	SDL_RenderPresent(w->renderer);
}

void	quit(t_winfo *w)
{
	SDL_DestroyRenderer(w->renderer);
	SDL_DestroyWindow(w->window);
	free(w);
	SDL_Quit();
}
