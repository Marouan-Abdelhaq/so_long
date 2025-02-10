/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:51:27 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/09 21:08:26 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*v;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	v = (const unsigned char *)src;
	p = (unsigned char *)dest;
	if (p > v)
	{
		i = n;
		while (i--)
			p[i] = v[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			p[i] = v[i];
			i++;
		}
	}
	return (dest);
}
