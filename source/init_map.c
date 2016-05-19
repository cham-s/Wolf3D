/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:23:41 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/19 16:49:46 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_map_info(t_map_info *mi, t_winfo *w)
{
	double	old_dir_x;
	double	old_plane_x;
	double	val;

	val = C_SPEED * 17;
	mi->pos_x = 1.5;
	mi->pos_y = 1.5;
	mi->dir_x = -1;
	mi->dir_y = 0;
	mi->plane_x = 0;
	mi->plane_y = 0.66;
	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(-val) - mi->dir_y * sin(-val);
	mi->dir_y = old_dir_x * sin(-val) + mi->dir_y * cos(-val);
	mi->plane_x = mi->plane_x * cos(-val) - mi->plane_y * sin(-val);
	mi->plane_y = old_plane_x * sin(-val) + mi->plane_y * cos(-val);
	w->did_win = 0;
	w->map[1][8] = 1;
}

void		change_time_values(t_time_info *ti)
{
	ti->oldtime = ti->time;
	ti->time = SDL_GetTicks();
	ti->frame_time = (ti->time - ti->oldtime) / 1000.0;
	ti->move_speed = ti->frame_time * 5.0;
	ti->rot_speed = ti->frame_time * 3.0;
}

void		init_window_info(t_winfo *w, int pos_x, int pos_y)
{
	w->pos.x = pos_x;
	w->pos.y = pos_y;
	w->size.x = WIDTH;
	w->size.y = HEIGHT;
	w->clear_c.r = 0;
	w->clear_c.g = 0;
	w->clear_c.b = 0;
	w->clear_c.a = 255;
	w->menu = 1;
	w->index = 0;
	w->show_menu = 1;
	w->running = 1;
	w->first = 1;
	w->did_win = 0;
}

SDL_Texture	*load_texture(t_winfo *w, char *name)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = SDL_LoadBMP(name);
	if (!surface)
	{
		ft_putendl_fd("Failed to load textures: ", 2);
		exit(EXIT_FAILURE);
	}
	texture = SDL_CreateTextureFromSurface(w->renderer, surface);
	SDL_FreeSurface(surface);
	return (texture);
}
