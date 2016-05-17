/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:11:08 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/17 13:12:22 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		init_all(t_winfo *w)
{
	if (init_sdl() < 0)
		return (EXIT_ERROR);
	else if (init_media() < 0)
		return (EXIT_ERROR);
	init_window_info(w, 100, 200, WIDTH, HEIGHT);
	if (create_window(w, "Wolf 3D", SDL_WINDOW_RESIZABLE) < 0)
		return (EXIT_ERROR);
	else if (create_renderer(w, FIRST_MATCH, SDL_RENDERER_SOFTWARE) < 0)
		return (EXIT_ERROR);
	load_audio(w);
	w->menu_start = load_texture(w, "media/img/start.bmp");
	w->menu_exit = load_texture(w, "media/img/exit.bmp");
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
	//free(w);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}
