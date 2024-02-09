/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:34:41 by arcarval          #+#    #+#             */
/*   Updated: 2024/02/09 16:18:53 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stack *stack_a)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(&stack_a, ft_free);
	exit(1);
}

void	ft_exit_error(char **input_stack, t_stack *new_input_stack)
{
	ft_putstr_fd("Error\n", 2);
	free_substrings(input_stack);
	ft_lstclear(&new_input_stack, ft_free);
	exit(1);
}

void	ft_exit_sorted(t_stack *stack_a)
{
	ft_lstclear(&stack_a, ft_free);
	exit(1);
}

void	ft_exit_unitary(char **input_stack)
{
	free_substrings(input_stack);
	exit(1);
}

void	get_out(int argc, char **input_stack, t_stack *new_input_stack)
{
	if (argc == 2)
		ft_exit_error(input_stack, new_input_stack);
	else
		ft_exit(new_input_stack);
}
