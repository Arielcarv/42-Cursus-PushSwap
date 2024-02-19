/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:18:51 by arcarval          #+#    #+#             */
/*   Updated: 2024/02/14 18:21:04 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sign(char letter)
{
	if (letter == '-' || letter == '+')
		return (1);
	return (0);
}

int	ft_check_duplicate(t_stack *stack_a)
{
	t_stack	*next_nbr;

	while (stack_a)
	{
		next_nbr = stack_a->next;
		while (next_nbr)
		{
			if (stack_a->nbr == next_nbr->nbr)
				return (1);
			next_nbr = next_nbr->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_is_list_sorted(t_stack *stack_a)
{
	int	current_nbr;

	current_nbr = stack_a->nbr;
	while (stack_a)
	{
		if (current_nbr > stack_a->nbr)
			return (0);
		current_nbr = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
