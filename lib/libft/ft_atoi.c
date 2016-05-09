/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:13:09 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/30 16:32:24 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	c = '\0';
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		c = '-';
		i++;
	}
	if (str[i] == '+' && !ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (c == '-' ? -r : r);
}
