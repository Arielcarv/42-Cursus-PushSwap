/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:56:50 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/10 12:13:18 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_index(t_stack **stack_a)
{
	int		i;
	t_stack	*temp;
	t_stack	*list;

	temp = *stack_a;
	list = *stack_a;
	while (list)
	{
		i = 1;
		while (temp)
		{
			if (list->nbr > temp->nbr)
				i++;
			temp = temp->next;
		}
		list->index = i;
		temp = *stack_a;
		list = list->next;
	}
}
