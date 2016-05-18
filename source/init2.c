/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:11:08 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/18 17:38:11 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		init_all(t_winfo *w)
{
	if (init_sdl() < 0)
		return (EXIT_ERROR);
	else if (init_media() < 0)
		return (EXIT_ERROR);
	init_window_info(w, 100, 200);
	if (create_window(w, "Wolf 3D", SDL_WINDOW_RESIZABLE) < 0)
		return (EXIT_ERROR);
	else if (create_renderer(w, FIRST_MATCH, SDL_RENDERER_SOFTWARE) < 0)
		return (EXIT_ERROR);
	load_audio(w);
	if (!ft_strcmp(w->map_name, "space.w3d"))
	{
		w->menu_start = load_texture(w, "media/img/space_menu_start.bmp");
		w->menu_exit = load_texture(w, "media/img/space_menu_exit.bmp");
	}
	else
	{
		w->menu_start = load_texture(w, "media/img/start.bmp");
		w->menu_exit = load_texture(w, "media/img/exit.bmp");
	}
	clear_screen(w);
	return (0);
}

void	clear_screen(t_winfo *w)
{
	SDL_SetRenderDrawColor(w->renderer, 0, 0, 0, 255);
	SDL_RenderClear(w->renderer);
}

void	destroy_tab(int **tab, size_t len)
{
	int	i;

	i = 0;
	while (len--)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	quit(t_winfo *w)
{
	SDL_DestroyTexture(w->menu_start);
	SDL_DestroyTexture(w->menu_exit);
	SDL_DestroyRenderer(w->renderer);
	SDL_DestroyWindow(w->window);
	Mix_FreeMusic(w->music);
	Mix_FreeChunk(w->step);
	Mix_FreeChunk(w->winning);
	Mix_FreeChunk(w->start);
	Mix_FreeChunk(w->move);
	Mix_FreeChunk(w->escape);
	destroy_tab(w->map, w->total_col);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
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
