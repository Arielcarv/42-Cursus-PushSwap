/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:34:21 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/11 08:38:34 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	int		len;
	t_stack	*temp_1;
	t_stack	*temp_2;
	t_stack	*ptr;

	if (ft_lstsize(*stack) == 0 || ft_lstsize(*stack) == 1)
		return;
	len = ft_lstsize(*stack);
	temp_1 = *stack;
	ptr = *stack;
	temp_2 = ft_lstlast(*stack);
	temp_2->next = temp_1;
	while (--len > 1)
		ptr = ptr->next;
	ptr->next = NULL;
	*stack = temp_2;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}
