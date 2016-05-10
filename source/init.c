#inclue "wolf3d.h"

int		init_all(void)
{
	if (SDL_Init(SDL_INI_EVERYTHING) < 0)
	{
		ft_putstr_fd("Failed to init SDL: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	return (0);
}

int		init_window_info(t_winfo *w, int pos_x, int pos_y, int size_x, int size_y)
{
	w->pos.x = pos_x;
	w->pos.y = pos_y;
	w->size.x = size_x;
	w->size.y = size_y;
	w->all_info = 1;
}

int		create_window(t_winfo *w, char *title, int flags)
{

	w->window = SDL_CreateWindow(w->title, w->pos.x, w->pos.y,
								w->size.x, w->sise.y, flags);
	if (w->window == NULL)
	{
		ft_putstr_fd("Failed to Create Window: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	w->all_info += 1;

	return (0);
}

int		create_renderer(t_winfo *w, int index, int flags)
{
	if (w->all_info != 2)
	{
		ft_putendl_fd("Error create_render: first init winfo then create \
						window before creating renderer", 2);
		return(EXIT_ERROR);
	}
	w->renderer = SDL_CreateRendrer(w->window, , index, flags):
	if (w->renderer == NULL)
	{
		ft_putstr_fd("Failed to Create Renderer: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	w->all_info += 1;
	return (0);
}

void	setup_renderer(t_winfo *w, t_color *c)
{
	SDL_RenderSetLocalSize(w->renderer, w->size.x, w->size.y);
	SDL_RenderDrawColor(w->renderer, c->r, c->g, c->b, c->a);
}

void	render();
