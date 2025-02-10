/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:27:10 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/06 20:44:04 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			l = 0;
			while (big[i + l] == little[l] && little[l] && (i + l) < len)
			{
				l++;
			}
			if (!little[l])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
