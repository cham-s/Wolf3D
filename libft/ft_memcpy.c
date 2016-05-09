/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:17:52 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/25 18:06:53 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*t_dst;
	char	*t_src;
	size_t	i;

	t_dst = (char *)dst;
	t_src = (char *)src;
	i = 0;
	while (i < len)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return (dst);
}
