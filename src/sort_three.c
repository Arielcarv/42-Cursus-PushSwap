/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:03 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/20 20:40:26 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->nbr;
	second = (*stack_a)->next->nbr;
	third = (*stack_a)->next->next->nbr;
	if (first > second && first < third && third > second)
		swap_a(stack_a);
	if (first > second && first > third && second > third)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	if (first > second && first > third && second < third)
		rotate_a(stack_a);
	if (first < second && first < third && third < second)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	if (first < second && first > third && second > third)
		reverse_rotate_a(stack_a);
}
