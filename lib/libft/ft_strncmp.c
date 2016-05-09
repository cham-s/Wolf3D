/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:10:37 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/16 17:04:47 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ts1;
	unsigned char	*ts2;
	size_t			ls1;
	size_t			ls2;

	ls1 = ft_strlen(s1) + 1;
	ls2 = ft_strlen(s2) + 1;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while (ls1-- && ls2-- && n--)
	{
		if (*ts1 != *ts2)
			return (*ts1 - *ts2);
		ts1++;
		ts2++;
	}
	return (0);
}
