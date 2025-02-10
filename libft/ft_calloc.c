/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:11:05 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/05 23:31:32 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	l;
	void	*ptr;

	l = nmemb * size;
	ptr = malloc(l);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, l);
	return (ptr);
}
