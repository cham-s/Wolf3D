/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:30:49 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/01 17:55:28 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t_s;

	t_s = (unsigned char *)s;
	while (n--)
	{
		if (*t_s == (unsigned char)c)
			return (t_s);
		t_s++;
	}
	return (NULL);
}
