/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:13 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/20 20:35:23 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_nbr(t_stack **stack)
{
	int		min;
	t_stack	*list;

	list = *stack;
	min = list->nbr;
	while (list->next)
	{
		if (list->next->nbr < min)
			min = list->next->nbr;
		else
			list = list->next;
	}
	return (min);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int min;

	if (!(ft_is_list_sorted(*stack_a)))
	{
		min = find_min_nbr(stack_a);
		while ((*stack_a)->nbr != min)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_b, stack_a);
	}
}
