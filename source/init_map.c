#include "wolf3d.h"

void	init_map_info(t_map_info *mi, t_winfo *w)
{
	double	old_dir_x;
	double	old_plane_x;
	double	val;

	(void)w;
	val = C_SPEED * 17;
	mi->pos_x = 1.5;
	mi->pos_y = 1.5;
	mi->dir_x = -1;
	mi->dir_y = 0;
	mi->plane_x = 0;
	mi->plane_y = 0.66 ;
	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(-val) - mi->dir_y * sin(-val);
	mi->dir_y = old_dir_x * sin(-val) + mi->dir_y * cos(-val); 
	mi->plane_x = mi->plane_x * cos(-val) - mi->plane_y * sin(-val);
	mi->plane_y = old_plane_x * sin(-val) + mi->plane_y * cos(-val); 
	w->did_win = 0;
	w->map[1][8] = 1;
	//change this to the start
	/* if (w->map[(int)mi->pos_x][(int)mi->pos_y]) */
	/* { */
	/* 	ft_putendl_fd("starting location blocked by a wall", 2); */
	/* 	exit(EXIT_FAILURE); */
	/* } */
}

void	change_time_values(t_time_info *ti)
{
	ti->oldtime = ti->time;
	ti->time = SDL_GetTicks();
	ti->frame_time = (ti->time - ti->oldtime) / 1000.0;
	ti->move_speed = ti->frame_time * 5.0;
	ti->rot_speed = ti->frame_time * 3.0;
}
