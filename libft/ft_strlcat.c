/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:37:40 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/26 10:36:59 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d_len;

	d_len = ft_strlen(dst);
	if (size < d_len)
		return (size + ft_strlen(src));
	while (*src && d_len < size - 1)
	{
		dst[d_len] = *src;
		src++;
		d_len++;
	}
	dst[d_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
