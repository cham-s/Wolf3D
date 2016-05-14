#include "wolf3d.h"

int		draw_wall(t_winfo *w, int x, int start, int end, t_color *c)
{
	if (end < start)
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

void	draw_ceiling_wall_floor(t_winfo *w, t_map_info *mi, t_ray_info *ri)
{
	int y = 0;

	mi->wall_color.r = 29;
	mi->wall_color.g = 179;
	mi->wall_color.b = 203;
	mi->wall_color.a = 255;
	draw_wall(w, mi->x, y, mi->draw_start, &mi->wall_color);
	face_color(mi, ri);
	draw_wall(w, mi->x, mi->draw_start, mi->draw_end, &mi->wall_color);
	mi->wall_color.r = 55;
	mi->wall_color.g = 42;
	mi->wall_color.b = 27;
	mi->wall_color.a = 255;
	draw_wall(w, mi->x, mi->draw_end, HEIGHT, &mi->wall_color);
}
