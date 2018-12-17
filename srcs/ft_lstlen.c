/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/11/06 14:20:43 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *head)
{
	size_t	count;

	count = 0;
	while (head && head->content)
	{
		count++;
		head = head->next;
	}
	return (count);
}
