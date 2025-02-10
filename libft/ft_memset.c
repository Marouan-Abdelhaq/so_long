/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:11:39 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/05 23:47:31 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			i;

	p = (unsigned char *)s;
	v = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		p[i] = v;
		i++;
	}
	return (s);
}
