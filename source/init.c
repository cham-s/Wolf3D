/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:11:01 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/17 13:11:15 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_audio2(t_winfo *w)
{
	w->winning = Mix_LoadWAV("media/sound/winning.wav");
	if (!w->winning)
	{
		ft_putendl_fd("Failed to load winning sound effect", 2);
		exit(EXIT_FAILURE);
	}
	w->escape = Mix_LoadWAV("media/sound/escape.wav");
	if (!w->escape)
	{
		ft_putendl_fd("Failed to load escape sound effect", 2);
		exit(EXIT_FAILURE);
	}
	w->move = Mix_LoadWAV("media/sound/move.wav");
	if (!w->move)
	{
		ft_putendl_fd("Failed to load move sound effect", 2);
		exit(EXIT_FAILURE);
	}
	w->start = Mix_LoadWAV("media/sound/enter.wav");
	if (!w->move)
	{
		ft_putendl_fd("Failed to load enter sound effect", 2);
		exit(EXIT_FAILURE);
	}
}

int		load_audio(t_winfo *w)
{
	char	*music;

	if (!ft_strcmp(w->map_name, "space.w3d"))
		music = "media/sound/rainforest.wav";
	else
		music = "media/sound/rainforest.wav";
	w->music = Mix_LoadMUS(music);
	if (!w->music)
	{
		ft_putendl_fd("Failed to load music ", 2);
		exit(EXIT_FAILURE);
	}
	else
	w->step = Mix_LoadWAV("media/sound/walk_s.wav");
	if (!w->step)
	{
		ft_putendl_fd("Failed to load step sound effect", 2);
		exit(EXIT_FAILURE);
	}
	load_audio2(w);
	return (0);
}

int		init_media(void)
{
	int	img_flags;

	img_flags = IMG_INIT_PNG;
	if (!(IMG_Init(img_flags) & img_flags))
	{
		ft_putstr_fd("Failed to init IMG: ", 2);
		ft_putendl_fd(IMG_GetError(), 2);
		return (EXIT_ERROR);
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		ft_putstr_fd("Failed to init AUDIO: ", 2);
		ft_putendl_fd(Mix_GetError(), 2);
		return (EXIT_ERROR);
	}
	return (0);
}

int		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ft_putstr_fd("Failed to init SDL: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	return (0);
}

int		create_window(t_winfo *w, char *title, int flags)
{
	w->window = SDL_CreateWindow(title, w->pos.x, w->pos.y,
								w->size.x, w->size.y, flags);
	if (w->window == NULL)
	{
		ft_putstr_fd("Failed to Create Window: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	return (0);
}
