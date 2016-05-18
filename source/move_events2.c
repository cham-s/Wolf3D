/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 21:02:29 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/18 21:09:54 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	other_keys(t_winfo *w, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE && w->first)
		w->running = 0;
	else if (event->key.keysym.sym == SDLK_ESCAPE && !w->show_menu)
	{
		Mix_PauseMusic();
		Mix_PlayChannel(-1, w->escape, 0);
		w->show_menu = 1;
	}
	else if (event->key.keysym.sym == SDLK_ESCAPE && w->show_menu)
	{
		Mix_ResumeMusic();
		w->show_menu = 0;
		w->index = 0;
	}
}

void	directions_key(t_winfo *w, t_time_info *ti, t_map_info *mi, SDL_Event *event)
{
	other_keys(w, event);
	if (event->key.keysym.sym == SDLK_UP)
	{
		if (w->show_menu)
		{
			w->index = w->index == 0 ? 1 : 0;
			Mix_PlayChannel(-1, w->move, 0);
		}
		else
			move_forward(mi, ti, w);
	}
	else if (event->key.keysym.sym == SDLK_DOWN)
	{
		if (w->show_menu)
		{
			w->index = w->index == 0 ? 1 : 0;
			Mix_PlayChannel(-1, w->move, 0);
		}
		else
			move_backward(mi, ti, w);
	}
	else if (event->key.keysym.sym == SDLK_RIGHT && !w->show_menu)
		turn_right(mi);
	else if (event->key.keysym.sym == SDLK_LEFT && !w->show_menu)
		turn_left(mi);
}

void	enter_key(t_winfo *w, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_RETURN &&
				w->index == 1 && w->show_menu)
		w->running = 0;
	else if (event->key.keysym.sym == SDLK_RETURN &&
				w->index == 0 && w->show_menu)
	{
		Mix_PlayChannel(-1, w->start, 0);
		w->index = 0;
		w->show_menu = 0;
	}
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

void	reg_key(t_winfo *w, t_map_info *mi, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_p && !w->show_menu)
		toggle_music(w);
	else if (event->key.keysym.sym == SDLK_r)
		init_map_info(mi, w);
}
