/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:08:01 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/15 17:22:27 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	ri->camera_x = 2 * mi->x / (double)WIDTH - 1;
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

void	perform_dda(t_map_info *mi, t_winfo *w)
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
		if (w->map[mi->map_x][mi->map_y] > 0) 
			mi->hit = 1;
	}
}
