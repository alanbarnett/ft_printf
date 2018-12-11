/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan </var/spool/mail/alan>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:02:34 by alan              #+#    #+#             */
/*   Updated: 2018/12/10 19:43:23 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Only really useful if used with ft_lstiter.
** Will print a (char *) from the list content.
*/
void				ft_lstputstr(t_list *item)
{
	if (item)
		write(1, (char *)item->content, ft_strlen(item->content));
}

/*
** Same as above, except it will print a specific length
*/
void				ft_lstputstr_len(t_list *item)
{
	if (item)
		write(1, (char *)item->content, item->content_size);
}
