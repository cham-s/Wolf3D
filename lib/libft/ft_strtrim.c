/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:23:00 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/30 12:00:17 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlenc(char const *str)
{
	size_t	i;
	size_t	l;
	size_t	j;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	l = 0;
	l = len;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	l--;
	while (str[l] == ' ' || str[l] == '\t' || str[l] == '\n')
	{
		l--;
		j++;
	}
	if ((i == len) || (j == len))
		return (0);
	return (len - (j + i));
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlenc(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	new = ft_strsub(s, i, len);
	if (!new)
		return (NULL);
	return (new);
}
