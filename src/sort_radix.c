/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:05:39 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/18 17:10:44 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	bin;

	bin = 0;
	while (!(ft_is_list_sorted(*stack_a)))
	{
		stack_size = ft_lstsize(*stack_a);
		while (stack_size)
		{
			if ((*stack_a)->index & (1 << bin))
				rotate_a(stack_a, 1);
			else
				push_b(stack_a, stack_b, 1);
			stack_size--;
		}
		bin++;
		while (*stack_b)
			push_a(stack_b, stack_a, 1);
	}
}
