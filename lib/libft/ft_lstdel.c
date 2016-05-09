/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:21:22 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/14 10:43:09 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *victim;

	victim = NULL;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		victim = *alst;
		*alst = (*alst)->next;
		free(victim);
	}
	*alst = NULL;
}
