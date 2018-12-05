/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:35:35 by abarnett          #+#    #+#             */
/*   Updated: 2018/12/02 19:29:18 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/*
** An implementation of memset that does not segfault if b is NULL
** (Returns NULL instead)
*/
void	*ft_nmemset(void *b, int c, size_t len)
{
	unsigned char	*cur;

	cur = b;
	while (len-- && cur)
		*cur++ = (unsigned char)c;
	return (b);
}
