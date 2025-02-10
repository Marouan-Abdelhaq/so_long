/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:42:10 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/06 20:26:11 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	int		l;

	l = ft_strlen(s);
	len = ft_strlen(s) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
	{
		return (NULL);
	}
	while (len--)
	{
		str[len] = s[len];
	}
	str[l] = '\0';
	return (str);
}
