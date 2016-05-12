#include "wolf3d.h"

void	init_map_info(t_map_info *mi)
{
	mi->pos_x = 22;
	mi->pos_y = 12;
	mi->dir_x = -1;
	mi->dir_y = 0;
	mi->plane_x = 0;
	mi->plane_y = 0.66 ;
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
		mi->side_dist_y = (mi->map_y + 1.0 - ri->ray_pos_y) * mi->delta_dist_y;
	}
}

void	calculate_ray_pos(t_ray_info *ri, t_map_info *mi)
{
	ri->camera_x = 2 * mi->x / (double)WIDTH - 1; // x coordinate in camera space
	ri->ray_pos_x = mi->pos_x;
	ri->ray_pos_y = mi->pos_y;
	ri->ray_dir_x = mi->dir_x + mi->plane_x * ri->camera_x;
	ri->ray_dir_y = mi->dir_y + mi->plane_y * ri->camera_x;
	mi->map_x = (int)ri->ray_pos_x;
	mi->map_y = (int)ri->ray_pos_y;
	mi->delta_dist_x = sqrt(1 + (ri->ray_dir_y * ri->ray_dir_y) /
			(ri->ray_dir_x * ri->ray_dir_x));
	mi->delta_dist_y = sqrt(1 + (ri->ray_dir_x * ri->ray_dir_x) /
			(ri->ray_dir_y * ri->ray_dir_y));
	mi->hit = 0;
	calculate_step(ri, mi);
}
//
#define MAP_W 24
#define MAP_H 24

void	perform_dda(t_map_info *mi, int world_map[MAP_W][MAP_H])
{
	while (mi->hit == 0)
	{
		if (mi->side_dist_x < mi->side_dist_y)
		{
			mi->side_dist_x += mi->delta_dist_x;
			mi->map_x += mi->step_x;
			mi->side = 0;
		}
		else
		{
			mi->side_dist_y += mi->delta_dist_y;
			mi->map_y += mi->step_y;
			mi->side = 1;
		}
		if (world_map[mi->map_x][mi->map_y] > 0) 
			mi->hit = 1;
	}
}

void	choose_wall_color(t_color *c, int v)
{
	if (v == 1)
	{
		c->r = 255;
		c->g = 0;
		c->b = 0;
		c->a = 255;
	}
	else if (v == 2)
	{
		c->r = 0;
		c->g = 255;
		c->b = 0;
		c->a = 255;
	}
	else if (v == 3)
	{
		c->r = 0;
		c->g = 0;
		c->b = 255;
		c->a = 255;
	}
	else if (v == 4)
	{
		c->r = 0;
		c->g = 0;
		c->b = 0;
		c->a = 255;
	}
	else
	{
		c->r = 255;
		c->g = 255;
		c->b = 0;
		c->a = 255;
	}
}
//
int		draw_line(t_winfo *w, int x, int start, int end, t_color *c)
{
	if(end < start)
	{
		start += end;
		end = start - end;
		start -= end; //swap y1 and y2
	}
	if(end < 0 || start >= HEIGHT  || x < 0 || x >= WIDTH)
		return 0; //no single point of the line is on screen
	if(start < 0) 
		start = 0; //clip
	if(end >= WIDTH)
		end = WIDTH - 1; //clip
	SDL_SetRenderDrawColor(w->renderer, c->r, c->g, c->b, c->a);
	while (start < end)
	{
		SDL_RenderDrawPoint(w->renderer, x, start);
		start++;
	}
	return (1);
}


void	draw_map(t_winfo *w, t_map_info *mi, t_ray_info *ri,  int world_map[MAP_H][MAP_W])
{
	clear_screen(w, &w->clear_c);
	mi->x = 0;
	while (mi->x < WIDTH)
	{
		//calulate ray position and direction
		calculate_ray_pos(ri, mi);
		perform_dda(mi, world_map);
		if (mi->side == 0)
			mi->perp_wall_dist = (mi->map_x - ri->ray_pos_x + (1 - mi->step_x) / 2) / ri->ray_dir_x;
		else
			mi->perp_wall_dist = (mi->map_y - ri->ray_pos_y + (1 - mi->step_y) / 2) / ri->ray_dir_y;
		//height of line to draw on screen
		mi->line_height = (int)(HEIGHT / mi->perp_wall_dist);
		mi->draw_start = -mi->line_height / 2 + HEIGHT / 2;
		if (mi->draw_start < 0)
			mi->draw_start = 0;
		mi->draw_end = mi->line_height / 2 + HEIGHT / 2;
		if (mi->draw_end >= HEIGHT)
			mi->draw_end = HEIGHT - 1;
		choose_wall_color(&mi->wall_color, world_map[mi->map_x][mi->map_y]);
		if (mi->side == 1)
		{
			mi->wall_color.r /= 2;
			mi->wall_color.g /= 2;
			mi->wall_color.b /= 2;
			mi->wall_color.a /= 2;
		}
		draw_line(w, mi->x, mi->draw_start, mi->draw_end, &mi->wall_color);
		mi->x++;
	}
}
void	move_forward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x + mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x += mi->dir_x * ti->move_speed;
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y + mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y += mi->dir_y * ti->move_speed;
}

void	move_backward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x - mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x -= mi->dir_x * ti->move_speed;
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y - mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y -= mi->dir_y * ti->move_speed;
}

void	draw(t_winfo *w)
{
	//malloc instead?
	t_ray_info	ri;
	t_map_info	mi;
	t_time_info	ti;
	int			running;
	SDL_Event	event;
	int world_map[MAP_W][MAP_H]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	ti.time = 0;
	running = 1;
	init_map_info(&mi);
	ti.time = 0;
	ti.oldtime = 0;
	while (running)
	{
		ti.oldtime = ti.time;
		ti.time = SDL_GetTicks();
		ti.frame_time = (ti.time - ti.oldtime) / 1000.0;
		double res = 1.0 / ti.frame_time;
		printf("fps: %lf\n", res);
		//show fps on screen
		ti.move_speed = ti.frame_time * 5.0;
		ti.rot_speed = ti.frame_time * 3.0;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
			else if (event.key.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					running = 0;
				else if (event.key.keysym.sym == SDLK_UP)
					move_forward(&mi, &ti, world_map);
				else if (event.key.keysym.sym == SDLK_DOWN)
					move_backward(&mi, &ti, world_map);
			}
		}
		draw_map(w, &mi, &ri, world_map);
		SDL_RenderPresent(w->renderer);
	}
}
