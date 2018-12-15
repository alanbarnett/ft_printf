/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:01:48 by alan              #+#    #+#             */
/*   Updated: 2018/12/13 23:04:35 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts a malloced string to uppercase
*/

void	ft_strupper(char *str)
{
	char	*cur;

	cur = str;
	while (cur && *cur)
	{
		*cur = ft_toupper(*cur);
		++cur;
	}
}
