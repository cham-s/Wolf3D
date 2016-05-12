#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_winfo	w;

	(void)ac;
	(void)av;
	init_all(&w);
	draw(&w);
	return (EXIT_SUCCESS);
}
