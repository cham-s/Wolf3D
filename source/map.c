/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 20:12:11 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/15 18:44:02 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_map(t_winfo *w, t_map_info *mi, t_ray_info *ri)
{
	clear_screen(w, &w->clear_c);
	mi->x = 0;
	while (mi->x < WIDTH)
	{
		calculate_ray_pos(ri, mi);
		perform_dda(mi, w);
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
		draw_ceiling_wall_floor(w, mi, ri);
		mi->x++;
	}
}

void	draw(t_winfo *w)
{
	//malloc instead?
	t_ray_info	ri;
	t_map_info	mi;
	t_time_info	ti;
	int			running;
	SDL_Event	event;

	running = 1;
	init_map_info(&mi, w);
	ti.time = 0;
	ti.oldtime = 0;
	while (running)
	{
		change_time_values(&ti);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
			else if (event.key.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					running = 0;
				else if (event.key.keysym.sym == SDLK_UP)
					move_forward(&mi, &ti, w);
				else if (event.key.keysym.sym == SDLK_DOWN)
					move_backward(&mi, &ti, w);
				else if (event.key.keysym.sym == SDLK_RIGHT)
					turn_right(&mi);
				else if (event.key.keysym.sym == SDLK_LEFT)
					turn_left(&mi);
				else if (event.key.keysym.sym == SDLK_p)
				{
					if (Mix_PlayingMusic() == 0)
						Mix_PlayMusic(w->music, -1);
					else
					{
						if (Mix_PausedMusic() == 1)
							Mix_ResumeMusic();
						else
							Mix_PauseMusic();
					}
				}
				else if (event.key.keysym.sym == SDLK_r)
					init_map_info(&mi, w);
			}
		}
		draw_map(w, &mi, &ri);
		draw_mini_map(w, &mi);
		SDL_RenderPresent(w->renderer);
	}
}
