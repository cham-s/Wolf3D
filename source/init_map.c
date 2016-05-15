#include "wolf3d.h"

void	init_map_info(t_map_info *mi)
{
	mi->pos_x = 10;
	mi->pos_y = 10;
	mi->dir_x = -1;
	mi->dir_y = 0;
	mi->plane_x = 0;
	mi->plane_y = 0.66 ;
}

void	change_time_values(t_time_info *ti)
{
	ti->oldtime = ti->time;
	ti->time = SDL_GetTicks();
	ti->frame_time = (ti->time - ti->oldtime) / 1000.0;
	ti->move_speed = ti->frame_time * 5.0;
	ti->rot_speed = ti->frame_time * 3.0;
}
