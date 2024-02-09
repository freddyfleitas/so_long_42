/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:28:05 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/08 16:17:44 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (!lst || !del || !*lst)
		return ;
	node = *lst;
	while (*lst)
	{
		node = (*lst)-> next;
		ft_lstdelone (*lst, del);
		*lst = node;
	}
	*lst = NULL;
}
