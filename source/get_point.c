/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:19:16 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/15 17:48:50 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void	init_points(char *file_name, t_winfo *w)
{
	char	*line;
	int		i;
	int		fd;
	int		x_len;
	char	**split;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplitspc(line);
		if (i++ == 0)
			x_len = tab_len(split);
		w->total_li = tab_len(split);
		tab_free(split);
		check_len_map(x_len, w);
		free(line);
	}
	check_error(&fd, line, x_len, i);
	w->total_col = i;
	close(fd);
}

static void		get_points(t_winfo *w, int *fd, char *line)
{
	int		x;
	int		y;
	char	**split;
	int		val;

	x = 0;
	y = 0;
	w->map = (int **)malloc(sizeof(int *) * w->total_col); 
	while (get_next_line(*fd, &line) > 0)
	{
		split = ft_strsplitspc(line);
		w->map[y] = (int *)malloc(sizeof(int) * w->total_li);
		while (x < w->total_li)
		{
			val = ft_atoi(split[x]);
			if (!val && (x == 0 || y == 0 || y == w->total_col - 1 || x == w->total_li - 1))
			{
				ft_putendl_fd("Not a valid file", 2);
				exit(EXIT_FAILURE);
			}

			w->map[y][x] = val;
			x++;
		}
		tab_free(split);
		free(line);
		x = 0;
		y++;
	}
}

void	get_map(char *file_name, t_winfo *w)
{
	int		fd;
	char	*line;

	line = NULL;
	init_points(file_name, w);
	fd = open(file_name, O_RDONLY);
	get_points(w, &fd, line);
	close(fd);
}
