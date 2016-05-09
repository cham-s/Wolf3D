/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:57:09 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/24 11:06:13 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*new;
	size_t	len1;

	len1 = ft_strlen(s1);
	new = ft_strnew(len1 + n);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy((new + len1), s2, n);
	return (new);
}
