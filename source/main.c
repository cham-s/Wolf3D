#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_winfo	w;

	(void)ac;
	(void)av;
	init_all(&w);
	run_wolf(&w);
	return (EXIT_SUCCESS);
}


/* int	main(int ac, char **av) */
/* { */
/* 	t_winfo	*w; */
/* 	SDL_Surface *surfaceIMG; */

/* 	surfaceIMG = NULL; */
/* 	w = (t_winfo *)ft_memalloc(sizeof(t_winfo)); */
/* 	(void)ac; */
/* 	(void)av; */
/* 	init_ */
/* 		/1* init_sdl(); *1/ */
/* 		/1* init_window_info(w, 200, 400, 1000, 900); *1/ */
/* 		/1* create_window(w, "Game", SDL_WINDOW_SHOWN); *1/ */
/* 		/1* loop(w); *1/ */
/* 		return (EXIT_SUCCESS); */
/* } */
