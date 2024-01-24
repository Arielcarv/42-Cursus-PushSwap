/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:54:23 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/24 18:36:31 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(t_stack *stack)
{
	ft_printf("PRINT LIST: ");
	while (stack)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	ft_printlist_index(t_stack *stack)
{
	ft_printf("↓ PRINT INDEX ↓\n");
	while (stack)
	{
		ft_printf("%d -> %d \n", stack->index, stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}

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
		temp_1 = temp_1->next;
	}
	return (min_nbr);
}

void	free_substrings(char **stack)
{
	int	index;

	index = 0;
	while (stack[index])
	{
		free(stack[index]);
		index++;
	}
	free(stack);
}
