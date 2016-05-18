/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:10:51 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/18 17:11:44 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_player(t_winfo *w, t_map_info *mi)
{
	SDL_Rect	player;

	player.x = (int)mi->pos_y * PIX_SIZE + 20;
	player.y = (int)mi->pos_x * PIX_SIZE + 20;
	player.h = PIX_SIZE;
	player.w = PIX_SIZE;
	SDL_SetRenderDrawColor(w->renderer, 255, 0, 1, 255);
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
	else if (w->map[j][i] == 5)
		SDL_SetRenderDrawColor(w->renderer, 0, 0, 0, 255);
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
	w_a->wall.h = PIX_SIZE;
	w_a->wall.w = PIX_SIZE;
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
