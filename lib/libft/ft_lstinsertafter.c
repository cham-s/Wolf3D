/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsertafter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:11:07 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/04 10:15:26 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsertafter(t_list *alst, t_list *new, size_t index)
{
	t_list *tmp;
	size_t len;

	len = index - 1;
	tmp = NULL;
	while (len--)
		alst = alst->next;
	tmp = alst->next;
	alst->next = new;
	new->next = tmp;
}
