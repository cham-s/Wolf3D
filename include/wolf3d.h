/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 21:58:51 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/15 15:45:01 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <fcntl.h>
# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include "libft.h"

# define NO_FLAG 0
# define ALL_INFO_INIT 3
# define FIRST_MATCH -1

# define WIDTH 1280 
# define HEIGHT 720 

# define MAP_W 24
# define MAP_H 24
# define C_SPEED 0.0989
# define PIX_SIZE 6

typedef	struct	s_color
{
	Uint8		r;
	Uint8		g;
	Uint8		b;
	Uint8		a;
}				t_color;

typedef struct	s_player
{
	char		*name;
	int			live;
	SDL_Rect	pos;
}				t_player;

typedef struct	s_winfo
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*screen;
	SDL_Point		pos;
	SDL_Point		size;
	char			*title;
	t_color			clear_c;
	int				**map;
	int				total_col;
	int				total_li;
}					t_winfo;

typedef	struct	s_map_info
{
	int		x;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		hit;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	double	delta_dist_x;
	double	delta_dist_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_color	wall_color;
}				t_map_info;

typedef	struct	s_time_info
{
	double	time;
	double	oldtime;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}				t_time_info;

typedef struct	s_ray_info
{
	double	camera_x;
	double	ray_pos_x;
	double	ray_pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	width;
}				t_ray_info;

int		init_all(t_winfo *w);
void	clear_screen(t_winfo *w, t_color *c);
void	run_wolf(t_winfo *w);
int		create_renderer(t_winfo *w, int index, int flags);
int		create_window(t_winfo *w, char *title, int flags);
void	init_window_info(t_winfo *w, int pos_x, int pos_y, int size_x, int size_y);
int		init_sdl(void);
void	quit(t_winfo *w);
int		load_media(SDL_Surface *img, char *img_path);
void	render(t_winfo *w, int y_pos);
void	init_map_info(t_map_info *mi);
void	draw(t_winfo *w);
int		draw_line(t_winfo *w, int x, int start, int end, t_color *c);
void	change_time_values(t_time_info *ti);
void	turn_left(t_map_info *mi, t_time_info *ti);
void	turn_right(t_map_info *mi, t_time_info *ti);
void	move_backward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W]);
void	move_forward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W]);
void	violet(t_color *c);
void	red(t_color *c);
void	orange(t_color *c);
void	green(t_color *c);
void	blue(t_color *c);
void	perform_dda(t_map_info *mi, int world_map[MAP_W][MAP_H]);
void	calculate_ray_pos(t_ray_info *ri, t_map_info *mi);
void	calculate_step(t_ray_info *ri, t_map_info *mi);
void	draw_ceiling_wall_floor(t_winfo *w, t_map_info *mi, t_ray_info *ri);
void	face_color(t_map_info *mi, t_ray_info *ri);
void	draw_player(t_winfo *w, t_map_info *mi);
void	draw_cube(t_winfo *w, int world_map[MAP_H][MAP_W]);
void	draw_mini_map(t_winfo *w, t_map_info *mi, int world_map[MAP_H][MAP_W]);
void	get_map(char *file_name, t_winfo *w);
int		check_args(int ac, char *map);
void	check_len_map(int x_len, t_winfo *w);
void	check_error(int *fd, char *line, int x, int y);

#endif
