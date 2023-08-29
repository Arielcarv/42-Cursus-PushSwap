/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:42:06 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 17:30:28 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current_node;

	if (!lst)
		return (lst);
	current_node = lst;
	while (current_node->next)
		current_node = current_node->next;
	return (current_node);
}
