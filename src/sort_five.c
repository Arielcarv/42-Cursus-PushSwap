/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:25:08 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/01 16:39:17 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*temp_1;

	temp_1 = *stack_a;
	min = find_min_nbr(stack_a);
	while (temp_1->next)
		temp_1 = temp_1->next;
	if (temp_1->nbr == min)
	{
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		push_a(stack_b, stack_a);
	}
	else
	{
		while ((*stack_a)->nbr != min)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		push_a(stack_b, stack_a);
	}
}
