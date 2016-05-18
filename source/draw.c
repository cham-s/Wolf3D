/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:10:51 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/17 15:47:14 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	get_rand_color(t_color *c)
{
	int	rand_n = rand() % 10 + 1;
	if ( rand_n == 4 || rand_n == 13)
	{
		c->r = 227;
		c->g = 255;
		c->b = 255;
		c->a = 255;
	}
	if (rand_n == 7 || rand_n == 2)
	{
		c->r = 0;
		c->g = 3;
		c->b = 158;
		c->a = 255;
	}
	else
	{
		c->r = 0;
		c->g = 0;
		c->b = 0;
		c->a = 255;
	}
}
int		draw_stars(t_winfo *w, int x, int start, int end)
{
	t_color c;

	get_rand_color(&c);
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
	SDL_SetRenderDrawColor(w->renderer, c.r, c.g, c.b, c.a);
	while (start < end)
	{
		SDL_RenderDrawPoint(w->renderer, x, start);
		start++;
	}
	return (1);
}

int		draw_w(t_winfo *w, int x, int start, int end, Uint32 buffer[HEIGHT][WIDTH])
{
	Uint8		r;
	Uint8		g;
	Uint8		b;

	while (start < end)
	{
		r = (buffer[start][x] & 0xFF0000) >> 16;
		g = (buffer[start][x] & 0xFF00) >> 8;
		b = (buffer[start][x] & 0xFF);
		//
		//printf("x : %d y: %d color :%d\n", x, start, buffer[start][x]);
		SDL_SetRenderDrawColor(w->renderer, r, g, b, 255);
		SDL_RenderDrawPoint(w->renderer, x, start);
		start++;
	}
	return (1);
}

void	draw_ceiling_wall_floor(t_winfo *w, t_map_info *mi, t_ray_info *ri)
{
	int y = 0;

	lightblue(&mi->wall_color);
	if (ft_strcmp(w->map_name, "space.w3d"))
		draw_wall(w, mi->x, y, mi->draw_start, &mi->wall_color);
	else
		draw_stars(w, mi->x, y, mi->draw_end);
	face_color(mi, ri);
	draw_wall(w, mi->x, mi->draw_start, mi->draw_end, &mi->wall_color);
	if (ft_strcmp(w->map_name, "space.w3d"))
		brown(&mi->wall_color);
	else
		grey(&mi->wall_color);
	draw_wall(w, mi->x, mi->draw_end, HEIGHT, &mi->wall_color);
}
// delete
void	draw_white_black(t_winfo *w, t_map_info *mi, t_ray_info *ri)
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

void	draw_player(t_winfo *w, t_map_info *mi)
{
	SDL_Rect	player;

	player.x = (int)mi->pos_y * PIX_SIZE + 20;
	player.y = (int)mi->pos_x * PIX_SIZE + 20;
	player.h = PIX_SIZE;
	player.w = PIX_SIZE;
	SDL_SetRenderDrawColor(w->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(w->renderer, &player);
	SDL_RenderDrawRect(w->renderer, &player);
}

void	choose_color(t_winfo *w, int i, int j)
{
	if (w->map[j][i] == 0)
		SDL_SetRenderDrawColor(w->renderer, 255, 255, 255, 255);
	else if (w->map[j][i] == 1)
		SDL_SetRenderDrawColor(w->renderer, 255, 217, 11, 255);
	else if (w->map[j][i] == 2)
		SDL_SetRenderDrawColor(w->renderer, 234, 67, 54, 255);
	else if (w->map[j][i] == 3)
		SDL_SetRenderDrawColor(w->renderer, 53, 168, 82, 255);
	else if (w->map[j][i] == 4)
		SDL_SetRenderDrawColor(w->renderer, 255, 187, 0, 255);
	else 
		SDL_SetRenderDrawColor(w->renderer, 255, 255, 255, 255);
}

void	init_wall(t_wall *w_a, t_winfo *w)
{
	w_a->x = 20;
	w_a->i = 0;
	w_a->j = 0;
	w_a->end_w = PIX_SIZE * w->total_li + 20;
	w_a->end_h = PIX_SIZE * w->total_col + 20;
	w_a->wall.h =  PIX_SIZE;
	w_a->wall.w =  PIX_SIZE;
}

void	draw_cube(t_winfo *w)
{
	t_wall		w_a;

	init_wall(&w_a, w);
	while (w_a.x < w_a.end_w)
	{
		w_a.y = 20;
		w_a.j = 0;
		while (w_a.y < w_a.end_h)
		{
			w_a.wall.x = w_a.x;
			w_a.wall.y = w_a.y;
			choose_color(w, w_a.i, w_a.j);
			SDL_RenderFillRect(w->renderer, &w_a.wall);
			SDL_RenderDrawRect(w->renderer, &w_a.wall);
			w_a.y += PIX_SIZE; 
			w_a.j++;
		}
		w_a.x += PIX_SIZE;
		w_a.i++;
	}
}

void	draw_mini_map(t_winfo *w, t_map_info *mi)
{
	SDL_Rect	mini_map;

	mini_map.x = 20;
	mini_map.y = 20;
	mini_map.h = PIX_SIZE * w->total_col;
	mini_map.w = PIX_SIZE * w->total_li;
	SDL_SetRenderDrawColor(w->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(w->renderer, &mini_map);
	SDL_RenderDrawRect(w->renderer, &mini_map);
	draw_cube(w);
	draw_player(w, mi);
}

void	render_menu(t_winfo *w)
{
	SDL_Rect	m;

	clear_screen(w);
	m.h = HEIGHT;
	m.w = WIDTH;
	m.x = 0;
	m.y = 0;

	if (w->index == 0)
		SDL_RenderCopy(w->renderer, w->menu_start, NULL, &m);
	else
		SDL_RenderCopy(w->renderer, w->menu_exit, NULL, &m);
	SDL_RenderPresent(w->renderer);
}
