/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:07:51 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/04 17:50:50 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = (char *)s;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = f(i, str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
