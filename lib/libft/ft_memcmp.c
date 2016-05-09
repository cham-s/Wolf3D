/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:12:58 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/16 17:14:30 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	t_s1 = (unsigned char*)s1;
	t_s2 = (unsigned char*)s2;
	while (n--)
	{
		if (*t_s1 != *t_s2)
			return (*t_s1 - *t_s2);
		t_s1++;
		t_s2++;
	}
	return (0);
}
