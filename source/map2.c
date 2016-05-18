/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:59:32 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/18 21:25:28 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	generate_texture(Uint32	tex[8][TEX_H * TEX_W])
{
	int x;
	int y;
	int xorco;
	int ycolor;
	int xycolor;

	x = 0;
	y = 0;
	while (x < TEX_W)
	{
		while (y < TEX_H)
		{
			xorco = (x * 256 / TEX_W) ^ (y * 256 / TEX_H);
			ycolor = y * 256 / TEX_H;
			xycolor = y * 128 / TEX_H + x * 128 / TEX_W;
			tex[0][TEX_W * y + x] = 65536 * 254 * (x != y && x != TEX_W - y);
			tex[1][TEX_W * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
			tex[2][TEX_W * y + x] = 256 * xycolor + 65536 * xycolor;
			tex[3][TEX_W * y + x] = xorco + 256 * xorco + 65536 * xorco;
			tex[4][TEX_W * y + x] = 256 * xorco;
			tex[5][TEX_W * y + x] = 65536 * 192 * (x % 16 && y % 16);
			tex[6][TEX_W * y + x] = 65536 * ycolor;;
			tex[7][TEX_W * y + x] = 128 + 256 * 128 + 65536 * 128;
			y++;
		}
		x++;
		y = 0;
	}
}

void	get_coord_text(t_winfo *w, t_map_info *mi, t_ray_info *ri)
{

	mi->tex_num = w->map[mi->map_x][mi->map_y] - 1; 
	if (mi->side == 0)
		mi->wall_x = ri->ray_pos_y + mi->perp_wall_dist * ri->ray_dir_y;
	else
		mi->wall_x = ri->ray_pos_x + mi->perp_wall_dist * ri->ray_dir_x;
	mi->wall_x -= floor(mi->wall_x);
	mi->tex_x = (int)(mi->wall_x * (double)TEX_W);
	if (mi->side == 0 && ri->ray_dir_x > 0)
		mi->tex_x = TEX_W - mi->tex_x - 1;
	if (mi->side == 1 && ri->ray_dir_y < 0)
		mi->tex_x = TEX_W - mi->tex_x - 1;
}

void	extract_color_from_text(t_map_info *mi, Uint32 buffer[HEIGHT][WIDTH],
		Uint32 texture[8][TEX_H * TEX_W])
{
	int		y;
	int		d;
	int		tex_y;
	Uint32	color;

	y = mi->draw_start;
	while (y < mi->draw_end)
	{
		d = y * 256 - HEIGHT * 128 + mi->line_height * 128;
		tex_y = ((d * TEX_H) / mi->line_height) / 256;
		color = texture[mi->tex_num][TEX_H * tex_y + mi->tex_x];
		if (mi->side == 1)
			color = (color >> 1) & 8355711;
		buffer[y][mi->x] = color;
		y++;
	}
}

