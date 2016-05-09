/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:26:47 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/04 09:39:06 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*t_dest;
	unsigned char	*t_src;
	unsigned char	tc;

	i = 0;
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	tc = (unsigned char)c;
	while (n--)
	{
		t_dest[i] = t_src[i];
		if (t_src[i] == tc)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
