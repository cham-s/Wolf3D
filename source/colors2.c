/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:08:14 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/18 16:59:42 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	face_color2(t_map_info *mi, t_ray_info *ri)
{
	if (mi->side == 1 && ri->ray_dir_y > 0)
	{
		mi->wall_color.r = 189;
		mi->wall_color.g = 50;
		mi->wall_color.b = 37;
		mi->wall_color.a = 255;
	}
	else
	{
		mi->wall_color.r = 244;
		mi->wall_color.g = 244;
		mi->wall_color.b = 244;
		mi->wall_color.a = 255;
	}
}

void		face_color(t_map_info *mi, t_ray_info *ri)
{
	if (mi->side == 0 && ri->ray_dir_x > 0)
	{
		mi->wall_color.r = 123;
		mi->wall_color.g = 136;
		mi->wall_color.b = 139;
		mi->wall_color.a = 255;
	}
	else if (mi->side == 0 && ri->ray_dir_x < 0)
	{
		mi->wall_color.r = 215;
		mi->wall_color.g = 169;
		mi->wall_color.b = 87;
		mi->wall_color.a = 255;
	}
	else
		face_color2(mi, ri);
}

void		violet(t_color *c)
{
	c->r = 34;
	c->r = 18;
	c->r = 63;
	c->a = 255;
}

void		grey(t_color *c)
{
	c->r = 186;
	c->r = 186;
	c->r = 186;
	c->a = 255;
}

void		lightblue(t_color *c)
{
	c->r = 29;
	c->r = 179;
	c->r = 203;
	c->a = 0;
}
