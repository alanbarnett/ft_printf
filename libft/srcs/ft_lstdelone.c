/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:10:20 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/11 21:40:59 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}

/*
** This function deletes the memory from the void pointer to content. It is
** meant to be used with lstdel. It ignores the content size, because there's
** nothing to do with it.
*/

void	ft_lstmemdel(void *content, size_t content_size)
{
	ft_memdel(&content);
	(void)content_size;
}
