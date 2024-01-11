/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:50:21 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/07 19:06:35 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*temp_1;
	t_stack	*temp_2;
	t_stack	*temp_3;

	if (ft_lstsize(*stack1) == 0)
		return ;
	temp_1 = *stack1;
	temp_2 = temp_1->next;
	temp_1->next = NULL;
	*stack1 = temp_2;
	temp_3 = *stack2;
	temp_1->next = temp_3;
	*stack2 = temp_1;
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
