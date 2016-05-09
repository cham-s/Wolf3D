/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:56:20 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/06 15:46:39 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t_s;

	i = ft_strlen(s);
	t_s = (char *)s;
	while (i >= 0)
	{
		if (t_s[i] == (char)c)
			return (&t_s[i]);
		i--;
	}
	return (NULL);
}
