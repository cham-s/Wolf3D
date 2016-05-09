/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:58:52 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/04 09:33:46 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_size(int n)
{
	int		s;

	s = 0;
	while (n)
	{
		s++;
		n /= 10;
	}
	return (s);
}

static	char	*ft_ismaxint_or_zero(int n)
{
	char	*ret;

	ret = NULL;
	if (n == -2147483648)
	{
		ret = ft_strnew(ft_strlen("-2147483648"));
		if (!ret)
			return (NULL);
		ft_memcpy(ret, "-2147483648", ft_strlen("-2147483648"));
	}
	else
	{
		ret = ft_strnew(ft_strlen("0"));
		if (!ret)
			return (NULL);
		ft_memcpy(ret, "0", ft_strlen("0"));
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	int		s;
	int		t;
	char	*new;

	s = ft_size(n);
	t = n;
	if (n == 0 || n == -2147483648)
		return (ft_ismaxint_or_zero(n));
	if (n < 0)
	{
		n = -n;
		s++;
	}
	if (!(new = ft_strnew(s)))
		return (NULL);
	while (s--)
	{
		new[s] = (n % 10) + '0';
		n /= 10;
	}
	new[0] = (t < 0 ? '-' : new[0]);
	return (new);
}
