/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:01:43 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/26 10:38:28 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (*s)
	{
		new[i] = f(i, *s);
		i++;
		s++;
	}
	return (new);
}
