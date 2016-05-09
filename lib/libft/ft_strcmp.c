/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:00:28 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/26 18:10:47 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				len1;
	int				len2;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	t_s1 = (unsigned char*)s1;
	t_s2 = (unsigned char*)s2;
	i = 0;
	while (len1-- && len2--)
	{
		if (t_s1[i] != t_s2[i])
			return (t_s1[i] - t_s2[i]);
		i++;
	}
	return (0);
}
