/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:21:40 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/02 17:08:21 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	len;
	size_t	i;
	size_t	strlen;

	if (!s)
		return (NULL);
	i = 0;
	strlen = 0;
	len = size_to_allocate(s, c);
	new = (char **)ft_memalloc(len + 1);
	if (!new)
		return (NULL);
	while (len--)
	{
		while (*s == c)
			s++;
		strlen = ft_strlenchr(s, c);
		new[i] = ft_strnew(strlen);
		ft_memcpy(new[i], s, strlen);
		s += strlen;
		i++;
	}
	new[i] = NULL;
	return (new);
}
