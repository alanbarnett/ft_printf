/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan </var/spool/mail/alan>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:02:34 by alan              #+#    #+#             */
/*   Updated: 2018/11/26 17:22:12 by alan             ###   ########.fr       */
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
		ft_putstr((char *)item->content);
}
