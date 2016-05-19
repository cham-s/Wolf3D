/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 20:12:34 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/19 19:35:09 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_forward(t_map_info *mi, t_time_info *ti, t_winfo *w)
{
	if (w->map[(int)(mi->pos_x + mi->dir_x *
				ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x += mi->dir_x * C_SPEED;
	if (w->map[(int)mi->pos_x][(int)(mi->pos_y + mi->dir_y *
				ti->move_speed)] == 0)
		mi->pos_y += mi->dir_y * C_SPEED;
	if ((int)mi->pos_x == 5 && (int)mi->pos_y == 1 &&
			!ft_strcmp(w->map_name, "space.w3d") &&
			!w->did_win)
	{
		w->did_win = 1;
		w->map[1][8] = 0;
		Mix_PlayChannel(-1, w->winning, 0);
	}
}

void	move_backward(t_map_info *mi, t_time_info *ti, t_winfo *w)
{
	if (w->map[(int)(mi->pos_x - mi->dir_x *
				ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x -= mi->dir_x * C_SPEED;
	if (w->map[(int)mi->pos_x][(int)(mi->pos_y - mi->dir_y *
				ti->move_speed)] == 0)
		mi->pos_y -= mi->dir_y * C_SPEED;
	if ((int)mi->pos_x == 5 && (int)mi->pos_y == 1 &&
			!ft_strcmp(w->map_name, "space.w3d") &&
			!w->did_win)
	{
		w->did_win = 1;
		w->map[1][8] = 0;
		Mix_PlayChannel(-1, w->winning, 0);
	}
}

void	turn_right(t_map_info *mi)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(-C_SPEED) - mi->dir_y * sin(-C_SPEED);
	mi->dir_y = old_dir_x * sin(-C_SPEED) + mi->dir_y * cos(-C_SPEED);
	mi->plane_x = mi->plane_x * cos(-C_SPEED) - mi->plane_y * sin(-C_SPEED);
	mi->plane_y = old_plane_x * sin(-C_SPEED) + mi->plane_y * cos(-C_SPEED);
}

void	turn_left(t_map_info *mi)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(C_SPEED) - mi->dir_y * sin(C_SPEED);
	mi->dir_y = old_dir_x * sin(C_SPEED) + mi->dir_y * cos(C_SPEED);
	mi->plane_x = mi->plane_x * cos(C_SPEED) - mi->plane_y * sin(C_SPEED);
	mi->plane_y = old_plane_x * sin(C_SPEED) + mi->plane_y * cos(C_SPEED);
}

void	keydown(t_winfo *w, t_map_info *mi, t_time_info *ti, SDL_Event *event)
{
	directions_key(w, ti, mi, event);
	reg_key(w, mi, event);
	enter_key(w, event);
}
