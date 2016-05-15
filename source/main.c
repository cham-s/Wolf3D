/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:06:23 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/15 14:51:12 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_winfo	w;

	check_args(ac, av[1]);
	get_map(av[1], &w);
	init_all(&w);
	draw(&w);
	quit(&w);
	return (EXIT_SUCCESS);
}
