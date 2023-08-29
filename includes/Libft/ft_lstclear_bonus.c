/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:38:43 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 17:30:28 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*next_node;
	t_stack	*current_node;

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
