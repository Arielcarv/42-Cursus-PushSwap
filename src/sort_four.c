/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:13 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/26 17:30:39 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_nbr(t_stack **stack)
{
	int		min_nbr;
	t_stack	*temp_1;

	temp_1 = *stack;
	min_nbr = temp_1->nbr;
	while (temp_1->next)
	{
		if (temp_1->next->nbr < min_nbr)
			min_nbr = temp_1->next->nbr;
		else
			temp_1 = temp_1->next;
	}
	return (min_nbr);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_nbr;

	if (!(ft_is_list_sorted(*stack_a)))
	{
		min_nbr = find_min_nbr(stack_a);
		while ((*stack_a)->nbr != min_nbr)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_b, stack_a);
	}
}
