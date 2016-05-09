/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:11:23 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/20 14:18:14 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *new;
	size_t i;

	i = 0;
	new = (void *)malloc(sizeof(size) * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
