/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:13:03 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/15 15:13:05 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isspace(int c)
{
	unsigned char tc;

	tc = (unsigned char)c;
	if (tc == '\t' || tc == ' ' || tc == '\r'
		|| tc == '\v' || tc == '\f')
		return (true);
	return (false);
}
