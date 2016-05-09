/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:55:49 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/04 19:12:22 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list *alst, size_t index)
{
	t_list *tmp;
	size_t len;

	tmp = NULL;
	len = index - 1;
	while (len--)
		alst = alst->next;
	tmp = alst->next;
}
