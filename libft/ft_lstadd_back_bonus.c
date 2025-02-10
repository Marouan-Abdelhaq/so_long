/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:16:15 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/05 03:41:29 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}
