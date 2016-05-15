/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:06:17 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/15 15:09:29 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_map(char *map)
{
	int fd;

	if ((fd = open(map, O_RDONLY)) == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
}

int			check_args(int ac, char *map)
{
	if (ac != 2)
	{
		ft_putstr_fd("usage : ", 2);
		ft_putstr_fd(map, 2);
		ft_putendl_fd("./wolf3d <map>", 2);
		exit(EXIT_FAILURE);
	}
	check_map(map);
	return (EXIT_SUCCESS);
}

void		check_ret_gnl(int *fd, char *line)
{
	if (get_next_line(*fd, &line) < 0)
	{
		ft_putendl_fd("Not a valid file", 2);
		exit(EXIT_FAILURE);
	}
}

void		check_len_map(int x_len, t_winfo *w)
{
	if (x_len != w->total_li)
	{
		ft_putendl_fd("Map not well formatted", 2);
		exit(EXIT_FAILURE);
	}
}
