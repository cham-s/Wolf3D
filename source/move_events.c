#include "wolf3d.h"

//
#define C_SPEED 0.0995

void	move_forward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x + mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
	{
		mi->pos_x += mi->dir_x * C_SPEED;
		//
		printf("move speed: %lf\n", ti->move_speed);
	}
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y + mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y += mi->dir_y * C_SPEED;
}

void	move_backward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x - mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x -= mi->dir_x * C_SPEED;
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y - mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y -= mi->dir_y * C_SPEED;
}

void	turn_right(t_map_info *mi, t_time_info *ti)
{
	double old_dir_x;
	double old_plane_x;

	//remove?
	(void)ti;
	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(-C_SPEED) - mi->dir_y * sin(-C_SPEED);
	mi->dir_y = old_dir_x * sin(-C_SPEED) + mi->dir_y * cos(-C_SPEED); 
	mi->plane_x = mi->plane_x * cos(-C_SPEED) - mi->plane_y * sin(-C_SPEED);
	mi->plane_y = old_plane_x * sin(-C_SPEED) + mi->plane_y * cos(-C_SPEED); 
	//
	printf("rotation speed: %lf\n", ti->move_speed);
}

void	turn_left(t_map_info *mi, t_time_info *ti)
{
	double old_dir_x;
	double old_plane_x;

	// remove?
	(void)ti;
	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(C_SPEED) - mi->dir_y * sin(C_SPEED);
	mi->dir_y = old_dir_x * sin(C_SPEED) + mi->dir_y * cos(C_SPEED); 
	mi->plane_x = mi->plane_x * cos(C_SPEED) - mi->plane_y * sin(C_SPEED);
	mi->plane_y = old_plane_x * sin(C_SPEED) + mi->plane_y * cos(C_SPEED); 
}
