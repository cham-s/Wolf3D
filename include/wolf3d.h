#ifndef WOLF3D_H
# define WOLF3D_H
# include "SDL2/SDL.h"
# include "libft.h"

# define NO_FLAG 0
# define ALL_INFO_INIT 3
# define FIRST_MATCH -1

typedef	struct	s_color
{
	Uint8		r;
	Uint8		g;
	Uint8		b;
	Uint8		a;
}				t_color;

typedef struct	s_winfo
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Point		pos;
	SDL_Point		size;
	char			*title;
	int				all_info;
}					t_winfo;

typedef struct	s_player
{
	char		*name;
	int			live;
	SDL_Rect	pos;
}				t_player;

int		init_all(t_winfo *w);
void	setup_renderer(t_winfo *w, t_color *c);
void	render(t_winfo *w, SDL_Rect *player_pos);
void	run_wolf(t_winfo *w);
int		create_renderer(t_winfo *w, int index, int flags);
int		create_window(t_winfo *w, char *title, int flags);
void	init_window_info(t_winfo *w, int pos_x, int pos_y, int size_x, int size_y);
int		init_sdl(void);

#endif
