#ifndef WOLF3D_H
# define WOF3D_H
# include "SDL2/SDL.h"
# include "libft.h"

# define NO_FLAG 0
# define ALL_INFO_INIT 3
# define FIRST_MATCH -1

typde	struct	s_color
{
	Uint8		r;
	Uint8		g;
	Uint8		b;
	Uint8		a;
}				t_color;


typedef struct	s_winfo
{
	SDL_Window	*window;
	SDL_Render	*renderer;
	SDL_Point	position;
	SDL_Point	window_size;
	char		*title;
	int			all_init;
}				t_winfo;

typedef struct	s_player
{
	char		*name;
	int			live;
	SDL_Point	position;
}				t_player;

#endif
