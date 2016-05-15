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
