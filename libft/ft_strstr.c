/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:14:49 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/25 10:41:04 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	if (ft_strlen(little) == 0)
		return (char *)(big);
	while (big[i])
	{
		j = i;
		k = 0;
		while (little[k] == big[j])
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
