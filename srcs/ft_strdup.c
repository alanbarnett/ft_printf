/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 20:52:19 by abarnett          #+#    #+#             */
/*   Updated: 2018/07/10 13:20:11 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = ft_strnew(len);
	return (dup ? ft_strncpy(dup, s1, len) : 0);
}

char	*ft_strndup(const char *s1, size_t len)
{
	char	*dup;

	dup = ft_strnew(len);
	return (dup ? ft_strncpy(dup, s1, len) : 0);
}
