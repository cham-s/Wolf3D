#include "wolf3d.h"

//
#define MAP_W 24
#define MAP_H 24

void	move_forward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x + mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x += mi->dir_x * ti->move_speed;
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y + mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y += mi->dir_y * ti->move_speed;
}

void	move_backward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x - mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x -= mi->dir_x * ti->move_speed;
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y - mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y -= mi->dir_y * ti->move_speed;
}

void	turn_right(t_map_info *mi, t_time_info *ti)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(-ti->rot_speed) - mi->dir_y * sin(-ti->rot_speed);
	mi->dir_y = old_dir_x * sin(-ti->rot_speed) + mi->dir_y * cos(-ti->rot_speed); 
	mi->plane_x = mi->plane_x * cos(-ti->rot_speed) - mi->plane_y * sin(-ti->rot_speed);
	mi->plane_y = old_plane_x * sin(-ti->rot_speed) + mi->plane_y * cos(-ti->rot_speed); 
}

void	turn_left(t_map_info *mi, t_time_info *ti)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(ti->rot_speed) - mi->dir_y * sin(ti->rot_speed);
	mi->dir_y = old_dir_x * sin(ti->rot_speed) + mi->dir_y * cos(ti->rot_speed); 
	mi->plane_x = mi->plane_x * cos(-ti->rot_speed) - mi->plane_y * sin(ti->rot_speed);
	mi->plane_y = old_plane_x * sin(-ti->rot_speed) + mi->plane_y * cos(ti->rot_speed); 
}
