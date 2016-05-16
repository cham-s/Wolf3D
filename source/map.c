/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 20:12:11 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/16 17:03:23 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_map(t_winfo *w, t_map_info *mi, t_ray_info *ri)
{
	clear_screen(w);
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
	draw_mini_map(w, mi);
	SDL_RenderPresent(w->renderer);
}

void	event_directions(t_winfo *w, t_time_info *ti, t_map_info *mi, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE && !w->show_menu)
		w->show_menu = 1;
	else if (event->key.keysym.sym == SDLK_ESCAPE && w->show_menu)
	{
		w->show_menu = 0;
		w->index = 0;
	}
	else if (event->key.keysym.sym == SDLK_UP)
	{
		if (w->show_menu)
			w->index = w->index == 0 ? 1 : 0;
		else
			move_forward(mi, ti, w);
	}
	else if (event->key.keysym.sym == SDLK_DOWN)
	{
		if (w->show_menu)
			w->index = w->index == 0 ? 1 : 0;
		else
			move_backward(mi, ti, w);
	}
	else if (event->key.keysym.sym == SDLK_RIGHT && !w->show_menu)
		turn_right(mi);
	else if (event->key.keysym.sym == SDLK_LEFT && !w->show_menu)
		turn_left(mi);
}

void	toggle_music(t_winfo *w)
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

void	draw(t_winfo *w)
{
	//malloc instead?
	t_ray_info	ri;
	t_map_info	mi;
	t_time_info	ti;
	SDL_Event	event;

	(void)ri;
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
			{
				event_directions(w, &ti, &mi, &event);
				if (event.key.keysym.sym == SDLK_p && !w->show_menu)
					toggle_music(w);
				else if (event.key.keysym.sym == SDLK_r)
					init_map_info(&mi, w);
				else if (event.key.keysym.sym == SDLK_RCTRL && w->index == 1 && w->show_menu)
					w->running = 0;
				else if (event.key.keysym.sym == SDLK_RCTRL && w->index == 0 && w->show_menu)
				{
					w->index = 0;
					w->show_menu = 0;
				}

			}
		}
		if (w->show_menu)
			render_menu(w);
		else
			draw_map(w, &mi, &ri);
	}
}
