/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:06:23 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/17 14:34:37 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_winfo	w;
	char	*start;

	check_args(ac, av[1]);
	get_map(av[1], &w);
	if (!(start = ft_strchr(av[1], '/')))
		w.map_name = av[1];
	else
		w.map_name = start + 1;
	init_all(&w);
	draw(&w);
	quit(&w);
	return (EXIT_SUCCESS);
}
