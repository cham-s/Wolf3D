/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:04:25 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/19 23:09:54 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		draw_wall(t_winfo *w, int x, SDL_Point *p, t_color *c)
{
	if (p->y < p->x)
	{
		p->x += p->y;
		p->y = p->x - p->y;
		p->x -= p->y;
	}
	if (p->y < 0 || p->x >= HEIGHT || x < 0 || x >= WIDTH)
		return (0);
	if (p->x < 0)
		p->x = 0;
	if (p->y >= WIDTH)
		p->y = WIDTH - 1;
	SDL_SetRenderDrawColor(w->renderer, c->r, c->g, c->b, c->a);
	while (p->x < p->y)
	{
		SDL_RenderDrawPoint(w->renderer, x, p->x);
		p->x++;
	}
	return (1);
}

int		draw_w(t_winfo *w, int x, SDL_Point *p,
		Uint32 buffer[HEIGHT][WIDTH])
{
	Uint8		r;
	Uint8		g;
	Uint8		b;

	while (p->x < p->y)
	{
		r = (buffer[p->x][x] & 0xFF0000) >> 16;
		g = (buffer[p->x][x] & 0xFF00) >> 8;
		b = (buffer[p->x][x] & 0xFF);
		SDL_SetRenderDrawColor(w->renderer, r, g, b, 255);
		SDL_RenderDrawPoint(w->renderer, x, p->x);
		p->x++;
	}
	return (1);
}

void	draw_ceiling_wall_floor(t_winfo *w, t_map_info *mi, t_ray_info *ri)
{
	int			y;
	SDL_Point	p;

	y = 0;
	p.x = y;
	p.y = mi->draw_start;
	mi->wall_color.r = 29;
	mi->wall_color.g = 179;
	mi->wall_color.b = 203;
	mi->wall_color.a = 255;
	draw_wall(w, mi->x, &p, &mi->wall_color);
	face_color(mi, ri);
	p.x = mi->draw_start;
	p.y = mi->draw_end;
	draw_wall(w, mi->x, &p, &mi->wall_color);
	mi->wall_color.r = 55;
	mi->wall_color.g = 42;
	mi->wall_color.b = 27;
	mi->wall_color.a = 255;
	p.x = mi->draw_end;
	p.y = HEIGHT;
	draw_wall(w, mi->x, &p, &mi->wall_color);
}

void	draw_white_black(t_winfo *w, t_map_info *mi,
		Uint32 buffer[HEIGHT][WIDTH])
{
	int			y;
	SDL_Point	p;

	y = 0;
	p.x = y;
	p.y = mi->draw_start;
	mi->wall_color.r = 0;
	mi->wall_color.g = 0;
	mi->wall_color.b = 0;
	mi->wall_color.a = 255;
	draw_wall(w, mi->x, &p, &mi->wall_color);
	p.x = mi->draw_start;
	p.y = mi->draw_end;
	draw_w(w, mi->x, &p, buffer);
	mi->wall_color.r = 67;
	mi->wall_color.g = 67;
	mi->wall_color.b = 67;
	mi->wall_color.a = 255;
	p.x = mi->draw_end;
	p.y = HEIGHT;
	draw_wall(w, mi->x, &p, &mi->wall_color);
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
