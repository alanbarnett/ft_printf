/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:37:07 by abarnett          #+#    #+#             */
/*   Updated: 2018/05/31 16:15:06 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str, char del)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str != del)
		{
			count++;
			while (*str && *str != del)
				str++;
		}
		else
			str++;
	}
	return (count);
}
