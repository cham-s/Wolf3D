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

int		draw_w(t_winfo *w, int x, int start, int end, Uint32 buffer[HEIGHT][WIDTH])
{
	Uint8		r;
	Uint8		g;
	Uint8		b;

	printf("x: %d\n", x);
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

void	draw_cube(t_winfo *w)
{
	SDL_Rect	wall;
	int			end_h;
	int			end_w;
	int			x;
	int			y;
	int			i;
	int			j;

	x = 20;
	i = 0;
	j = 0;
	end_w = PIX_SIZE * w->total_li + 20;
	end_h = PIX_SIZE * w->total_col + 20;
	wall.h =  PIX_SIZE;
	wall.w =  PIX_SIZE;
	while (x < end_w)
	{
		y = 20;
		j = 0;
		while (y < end_h)
		{
			wall.x = x;
			wall.y = y;
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
			SDL_RenderFillRect(w->renderer, &wall);
			SDL_RenderDrawRect(w->renderer, &wall);
			y += PIX_SIZE; 
			j++;
		}
		x += PIX_SIZE;
		i++;
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
