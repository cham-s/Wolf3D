#include "wolf3d.h"

static void	face_color2(t_map_info *mi, t_ray_info *ri)
{
	// red side-left 
	if (mi->side == 1 && ri->ray_dir_y > 0)
	{
		mi->wall_color.r = 189;
		mi->wall_color.g = 50;
		mi->wall_color.b = 37;
		mi->wall_color.a = 255;
	}
	// white side-right
	else
	{
		mi->wall_color.r = 244;
		mi->wall_color.g = 244;
		mi->wall_color.b = 244;
		mi->wall_color.a = 255;
	}
}


void		face_color(t_map_info *mi, t_ray_info *ri)
{
	if (mi->side == 0 && ri->ray_dir_x > 0)
	{
		mi->wall_color.r = 123;
		mi->wall_color.g = 136;
		mi->wall_color.b = 139;
		mi->wall_color.a = 255;
	}
	// own front
	else if (mi->side == 0 && ri->ray_dir_x < 0)
	{
		mi->wall_color.r = 215;
		mi->wall_color.g = 169;
		mi->wall_color.b = 87;
		mi->wall_color.a = 255;
	}
	else
		face_color2(mi, ri);
}
