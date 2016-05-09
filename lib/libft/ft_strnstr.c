/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:15:43 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/28 15:33:44 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (ft_strlen(little) == 0)
		return (char *)(big);
	while (i < n && big[i])
	{
		j = i;
		k = 0;
		while ((little[k] == big[j]) && (j < n))
		{
			j++;
			k++;
			if (little[k] == '\0')
				return (char *)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
