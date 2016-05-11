#include "wolf3d.h"

int		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ft_putstr_fd("Failed to init SDL: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	return (0);
}

void	init_window_info(t_winfo *w, int pos_x, int pos_y, int size_x, int size_y)
{
	w->pos.x = pos_x;
	w->pos.y = pos_y;
	w->size.x = size_x;
	w->size.y = size_y;
	w->all_info = 1;
}

int		create_window(t_winfo *w, char *title, int flags)
{
	w->title = title;
	w->window = SDL_CreateWindow(w->title, w->pos.x, w->pos.y,
								w->size.x, w->size.y, flags);
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
	w->renderer = SDL_CreateRenderer(w->window, index, flags);
	if (w->renderer == NULL)
	{
		ft_putstr_fd("Failed to Create Renderer: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	SDL_RenderSetLogicalSize(w->renderer, w->size.x, w->size.y);
	w->all_info += 1;
	return (0);
}

void	calculate_step(t_ray_info *ri, t_map_info *mi)
{
	if (ri->ray_dir_x < 0)
	{
		mi->step_x = -1;
		mi->side_dist_x = (ri->ray_pos_x - mi->map_x) * mi->delta_dist_x;
	}
	else
	{
		mi->step_x = 1;
		mi->side_dist_x = (mi->map_x + 1.0 - ri->ray_pos_x) * mi->delta_dist_x;
	}
	if (ri->ray_dir_y < 0)
	{
		mi->step_y = -1;
		mi->side_dist_y = (ri->ray_pos_y - mi->map_y) * mi->delta_dist_y;
	}
	else
	{
		mi->step_y = 1;
		mi->side_dist_x = (mi->map_y + 1.0 - ri->ray_pos_y) * mi->delta_dist_y;
	}
}

void	calculate_ray_pos(t_ray_info *ri, t_map_info *mi)
{
	ri->camera_x = 2 * x / ri.width - 1; // x coordinate in camera space
	ri->ray_pos_x = mi->pos_x;
	ri->ray_pos_y = mi->pos_y;
	ri->ray_dir_x = mi->dir_x + mi->plane_x * ri->camera_x;
	ri->ray_dir_y = mi->dir_y + mi->plane_y * ri->camera_x;
	map_x = (int)ri->pos_x;
	map_y = (int)ri->pos_y;
	perp_wall_dist;
	delta_dist_x = sqrt(1 + (mi->ray_dir_y * mi->ray_dir_y) /
					(mi->ray_dir_x * mi->ray_dir_x));
	delta_dist_y = sqrt(1 + (mi->ray_dir_x * mi->ray_dir_x) /
					(mi->ray_dir_y * mi->ray_dir_y));
	hit = 0;
	calculate_step(ri, mi);
}

void	perform_dda(t_ray_info *ri, t_map_info *mi)
{
	while (mi->hit == 0)
	{
		if (mi->side_dist_x < mi->side_dist_y)
		{
			mi->side_dist_x += mi->side_dist_y;
			mi->map+x += mi->step_x;
			mi->side = 0;
		}
		else
		{
			mi->side_dist_y += mi->delta_dist_y;
			mi->map_y += mi->step_y;
			mi->side = 1;
		}
		if (mi->world_map[MAP_W][MAP_H] > 0) 
			mi->hit = 1
	}
}

void	run_game(t_winfo *w)
{
	SDL_Point	p;
	//malloc instead?
	t_ray_info	ri;
	t_map_info	mi;

	p.x = 0;
	p.y = 0;
	ri.width = (double)WIDTH;
	init_map_info(&mi);
	while (p.x < WIDTH)
	{
		//calulate ray position and direction
		calculate_ray_pos(&ri, &mi);
		perform_dda(&ri, &mi);
		if (mi->side == 0)
			mi->perp_wall_dist = (mi.map_x - ri.ray_pos_x + (1 - mi.step_x) / 2) ri.ray_dir_x;
		else
			mi->perp_wall_dist = (mi.map_y - ri.ray_pos_y + (1 - mi.step_y) / 2) ri.ray_dir_y;
		//height of line to draw on screen
		mi.line_height = (int) (HEIGHT / mi.perp_wall_Dist);
		mi.draw_start = -mi.line_height / 2 + HEIGHT / 2;
		if (mi.draw_start < 0)
			mi.draw_start = 0;
		mi.draw_end = mi.line_height / 2 + HEIGHT / 2;
		if (mi.draw_end >= HEIGHT)
			mi.draw_end = HEIGHT - 1;
		chooe_wall_color(&mi.wall_color, mi.world_map[mi.map_x][mi.map.y]);
	}
}

void	choose_wall_color(t_color *c, int v)
{
	if (v == 1)
	{
		c->r = 255;
		c->g = 0;
		c->b = 0;
		c->a = 0;
	}
	else if (v == 2)
	{
		c->r = 0;
		c->g = 255;
		c->b = 0;
		c->a = 0;
	}
	else if (v == 3)
	{
		c->r = 0;
		c->g = 0;
		c->b = 255;
		c->a = 0;
	}
	else if (v == 4)
	{
		c->r = 0;
		c->g = 0;
		c->b = 0;
		c->a = 0;
	}
	else
	{
		c->r = 255;
		c->g = 255;
		c->b = 0;
		c->a = 0;
	}
}

void	run_wolf(t_winfo *w)
{
	int			running;
	SDL_Event	event;
	static	int value = 0;

	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
			else if(event.key.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_ESCAPE)
					running = 0;
				else if(event.key.keysym.sym == SDLK_UP)
					value--;
				else if(event.key.keysym.sym == SDLK_DOWN)
					value++;
			}
		}
		render(w, value);
	}
}
