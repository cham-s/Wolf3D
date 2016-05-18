/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 20:12:11 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/18 21:27:50 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	side_and_draw_start(t_map_info *mi, t_ray_info *ri)
{
	if (mi->side == 0)
		mi->perp_wall_dist = (mi->map_x - ri->ray_pos_x +
				(1 - mi->step_x) / 2) / ri->ray_dir_x;
	else
		mi->perp_wall_dist = (mi->map_y - ri->ray_pos_y +
				(1 - mi->step_y) / 2) / ri->ray_dir_y;
	mi->line_height = (int)(HEIGHT / mi->perp_wall_dist);
	mi->draw_start = -mi->line_height / 2 + HEIGHT / 2;
	if (mi->draw_start < 0)
		mi->draw_start = 0;
	mi->draw_end = mi->line_height / 2 + HEIGHT / 2;
	if (mi->draw_end >= HEIGHT)
		mi->draw_end = HEIGHT - 1;
}

void	draw_map(t_winfo *w, t_map_info *mi, t_ray_info *ri)
{
	Uint32	buffer[HEIGHT][WIDTH];
	Uint32	texture[8][TEX_H * TEX_W];

	generate_texture(texture);
	clear_screen(w);
	mi->x = 0;
	while (mi->x < WIDTH)
	{
		calculate_ray_pos(ri, mi);
		perform_dda(mi, w);
		side_and_draw_start(mi, ri);
		if (ft_strcmp(w->map_name, "space.w3d"))
			draw_ceiling_wall_floor(w, mi, ri);
		else
		{
			get_coord_text(w, mi, ri);
			extract_color_from_text(mi, buffer, texture);
			draw_white_black(w, mi, buffer);
		}
		mi->x++;
	}
	w->first = 0;
	draw_mini_map(w, mi);
	SDL_RenderPresent(w->renderer);
}

void	draw(t_winfo *w)
{
	t_ray_info	ri;
	t_map_info	mi;
	t_time_info	ti;
	SDL_Event	event;

	init_map_info(&mi, w);
	ti.time = 0;
	ti.oldtime = 0;
	while (w->running)
	{
		change_time_values(&ti);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				w->running = 0;
			else if (event.key.type == SDL_KEYDOWN)
				keydown(w, &mi, &ti, &event);
		}
		if (w->show_menu)
			render_menu(w);
		else
			draw_map(w, &mi, &ri);
	}
}
