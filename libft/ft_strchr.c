/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:45:15 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/26 18:11:29 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t_s;

	t_s = (char *)s;
	i = 0;
	while (t_s[i])
	{
		if (t_s[i] == (char)c)
			return (&t_s[i]);
		i++;
	}
	if (t_s[i] == (char)c)
		return (&t_s[i]);
	return (NULL);
}
