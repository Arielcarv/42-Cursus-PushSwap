/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:19:27 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/18 17:02:33 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp_1;
	t_stack	*temp_2;

	if (ft_lstsize(*stack) == 0 || ft_lstsize(*stack) == 1)
		return ;
	temp_1 = *stack;
	temp_2 = temp_1->next;
	temp_1->next = temp_1->next->next;
	temp_2->next = temp_1;
	*stack = temp_2;
}

void	swap_a(t_stack **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
