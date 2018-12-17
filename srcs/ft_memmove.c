/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:58:41 by abarnett          #+#    #+#             */
/*   Updated: 2018/05/21 16:34:48 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			++i;
		}
	else
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (dst);
}
