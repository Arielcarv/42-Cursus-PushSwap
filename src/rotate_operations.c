/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:15:31 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/09 09:03:52 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp_1;
	t_stack	*temp_2;
	t_stack	*temp_3;

	if (ft_lstsize(*stack) == 0 || ft_lstsize(*stack) == 1)
		return;
	temp_1 = *stack;
	temp_2 = ft_lstlast(*stack);
	temp_3 = temp_1->next;
	temp_2->next = temp_1;
	temp_1->next = NULL;
	*stack = temp_3;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}
