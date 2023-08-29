/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:54:24 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 17:30:28 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	t_stack	*current_node;
	int		size;

	current_node = lst;
	size = 0;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		size++;
	}
	return (size);
}
