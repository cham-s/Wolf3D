/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:36:08 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/01 18:09:37 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s1, size_t len)
{
	void	*ret;

	ret = ft_memalloc(len);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, len);
	return (ret);
}
