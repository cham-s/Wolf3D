/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitspc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:44:54 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/01 19:01:38 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplitspc(char const *s)
{
	char **new;

	new = ft_strsplit(s, ' ');
	if (!new)
		return (NULL);
	return (new);
}
