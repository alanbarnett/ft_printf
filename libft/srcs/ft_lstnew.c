/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:06:41 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/11 21:39:27 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	head = (t_list *)ft_memalloc(sizeof(t_list));
	if (head == 0)
		return (0);
	head->next = 0;
	if (content == 0)
	{
		head->content = 0;
		head->content_size = 0;
		return (head);
	}
	head->content = ft_memalloc(content_size);
	if (head->content == 0)
	{
		ft_memdel((void **)&head);
		return (0);
	}
	ft_memcpy(head->content, content, content_size);
	head->content_size = content_size;
	return (head);
}

/*
** this function exists to put a pointer into the list easily
** content and content size get directly copied, instead of making new memory
*/

t_list	*ft_lstinit(void const *content, size_t content_size)
{
	t_list *head;

	head = (t_list *)ft_memalloc(sizeof(t_list));
	if (head == 0)
		return (0);
	head->next = 0;
	head->content = (void *)content;
	head->content_size = content_size;
	return (head);
}
