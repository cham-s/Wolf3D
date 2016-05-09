/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:38:09 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/08 15:35:21 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **alst)
{
	t_list *current;

	current = *alst;
	if (!current)
		return ;
	while (current)
	{
		ft_putendl((char *)current->content);
		current = current->next;
	}
}
