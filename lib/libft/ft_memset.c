/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:31:35 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/25 18:08:24 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*new;

	new = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		new[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
