#include "wolf3d.h"

void	move_forward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x + mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
	{
		mi->pos_x += mi->dir_x * 0.0888;
		//
		printf("move speed: %lf\n", ti->move_speed);
	}
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y + mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y += mi->dir_y * 0.0888;
}

void	move_backward(t_map_info *mi, t_time_info *ti,  int world_map[MAP_H][MAP_W])
{
	if (world_map[(int)(mi->pos_x - mi->dir_x * ti->move_speed)][(int)mi->pos_y] == 0)
		mi->pos_x -= mi->dir_x * 0.0888;
	if (world_map[(int)mi->pos_x][(int)(mi->pos_y - mi->dir_y * ti->move_speed)] == 0)
		mi->pos_y -= mi->dir_y * 0.0888;
}

void	turn_right(t_map_info *mi, t_time_info *ti)
{
	double old_dir_x;
	double old_plane_x;

	//remove?
	(void)ti;
	old_dir_x = mi->dir_x;
	old_plane_x = mi->plane_x;
	mi->dir_x = mi->dir_x * cos(-0.0888) - mi->dir_y * sin(-0.0888);
	mi->dir_y = old_dir_x * sin(-0.0888) + mi->dir_y * cos(-0.0888); 
	mi->plane_x = mi->plane_x * cos(-0.0888) - mi->plane_y * sin(-0.0888);
	mi->plane_y = old_plane_x * sin(-0.0888) + mi->plane_y * cos(-0.0888); 
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
	mi->dir_x = mi->dir_x * cos(0.0888) - mi->dir_y * sin(0.0888);
	mi->dir_y = old_dir_x * sin(0.0888) + mi->dir_y * cos(0.0888); 
	mi->plane_x = mi->plane_x * cos(0.0888) - mi->plane_y * sin(0.0888);
	mi->plane_y = old_plane_x * sin(0.0888) + mi->plane_y * cos(0.0888); 
}
