/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:11:01 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/15 13:11:02 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		load_audio(t_winfo *w)
{
	w->music = Mix_LoadMUS("media/sound/rainforest.wav");
	if (!w->music)
	{
		ft_putendl_fd("Failed to load music ", 2);
		exit(EXIT_FAILURE);
	}
	w->step = Mix_LoadWAV("media/sound/walk_s.wav");
	if (!w->music)
	{
		ft_putendl_fd("Failed to load step sound effect", 2);
		exit(EXIT_FAILURE);
	}
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

void	init_window_info(t_winfo *w, int pos_x,
		int pos_y, int size_x, int size_y)
{
	w->pos.x = pos_x;
	w->pos.y = pos_y;
	w->size.x = size_x;
	w->size.y = size_y;
	w->clear_c.r = 0;
	w->clear_c.g = 0;
	w->clear_c.b = 0;
	w->clear_c.a = 255;
	w->menu = 1;
	w->index = 0;
}

int		create_window(t_winfo *w, char *title, int flags)
{
	w->title = title;
	w->window = SDL_CreateWindow(w->title, w->pos.x, w->pos.y,
								w->size.x, w->size.y, flags);
	if (w->window == NULL)
	{
		ft_putstr_fd("Failed to Create Window: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	return (0);
}

int		create_renderer(t_winfo *w, int index, int flags)
{
	w->renderer = SDL_CreateRenderer(w->window, index, flags);
	if (w->renderer == NULL)
	{
		ft_putstr_fd("Failed to Create Renderer: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (EXIT_ERROR);
	}
	SDL_RenderSetLogicalSize(w->renderer, w->size.x, w->size.y);
	return (0);
}

SDL_Texture	*load_texture(t_winfo *w, char *name)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = SDL_LoadBMP(name);
	if (surface)
	{
		ft_putendl_fd("Failed to load textures: ", 2);
		exit(EXIT_FAILURE);
	}
	texture = SDL_CreateTextureFromSurface(w->renderer, surface);
	SDL_FreeSurface(surface);
	return (texture);
}

void	render_menu(t_winfo *w)
{
	SDL_Rect	m;

	clear_screen(w);
	m.h = HEIGHT;
	m.w = WIDTH;
	m.x = 0;
	m.y = 0;

	if (w->index == 0)
		SDL_RenderCopy(w->renderer, w->menu_start, NULL, &m);
	else
		SDL_RenderCopy(w->renderer, w->menu_exit, NULL, &m);
	SDL_RenderPresent(w->renderer);
}
