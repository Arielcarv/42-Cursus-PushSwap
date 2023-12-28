/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:13 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/27 21:32:09 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
