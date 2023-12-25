/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:25:08 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/25 18:29:04 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_nbr(t_stack **stack)
{
	int min_nbr;
	t_stack *temp_1;

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

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	// find min
	// rotate if min is first 
	// or 
	// until min not found rotate a
}