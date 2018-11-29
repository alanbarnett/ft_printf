/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:21:40 by abarnett          #+#    #+#             */
/*   Updated: 2018/11/26 23:35:04 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *item)
{
	item->next = *alst;
	*alst = item;
}

void	ft_lstadd_tail(t_list **alst, t_list *item)
{
	t_list **cur;

	cur = alst;
	if (!*cur)
	{
		*cur = item;
		return ;
	}
	while ((*cur)->next)
		cur = &(*cur)->next;
	(*cur)->next = item;
}
