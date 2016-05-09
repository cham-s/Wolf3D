/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:44:01 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/04 09:49:24 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	unsigned char	*tmp;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	tmp = (unsigned char *)ft_strndup((const char *)t_src, n);
	if (!tmp)
		return (NULL);
	ft_memcpy(t_dest, tmp, n);
	free(tmp);
	tmp = NULL;
	return (dest);
}
