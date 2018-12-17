/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:33:28 by abarnett          #+#    #+#             */
/*   Updated: 2018/09/03 22:07:15 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinit(size_t size, int c)
{
	char	*s;

	s = (char *)ft_nmemset(malloc(size + 1), c, size + 1);
	if (s)
		s[size] = '\0';
	return (s);
}
