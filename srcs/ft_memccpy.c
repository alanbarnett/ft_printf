/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:24:37 by abarnett          #+#    #+#             */
/*   Updated: 2018/05/31 12:51:16 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cur;

	cur = (unsigned char *)dst;
	while (n--)
	{
		*cur++ = *(unsigned char *)src++;
		if (*(cur - 1) == (unsigned char)c)
			return (cur);
	}
	return (0);
}
