/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:44:41 by mabdelha          #+#    #+#             */
/*   Updated: 2024/11/04 14:19:06 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void del(void *content) {
//     free(content); // Libérer le contenu
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst || !*lst)
	{
		return ;
	}
	while (*lst)
	{
		ptr = *lst;
		*lst = ptr->next;
		del(ptr->content);
		free(ptr);
	}
	*lst = NULL;
}
