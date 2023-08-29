/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:38:43 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 12:55:35 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*next_node;
	t_list	*current_node;

	current_node = *lst;
	if (current_node && del)
	{
		while (current_node)
		{
			next_node = current_node->next;
			ft_lstdelone(current_node, del);
			current_node = next_node;
		}
		*lst = NULL;
	}
}
