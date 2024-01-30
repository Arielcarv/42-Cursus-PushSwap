/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:14:05 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/30 19:07:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_split_or_not(int argc, char **argv)
{
	char	**input_stack;
	int		size;

	if (argc == 2)
	{
		input_stack = ft_split(argv[1], ' ');
		size = 0;
		while (input_stack[size])
			size++;
		if (size == 1)
			ft_exit_unitary(input_stack);
		return (input_stack);
	}
	return (argv);
}

static int	ft_check_duplicate(t_stack *stack_a)
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

t_stack	*process_input(int argc, char **argv)
{
	int		i;
	char	**input_stack;
	t_stack	*new_input_stack;

	i = 0;
	if (argc == 2)
		i = -1;
	input_stack = ft_split_or_not(argc, argv);
	new_input_stack = NULL;
	while (input_stack[++i])
	{
		if (!ft_strncmp(input_stack[i], "-", 2)
			|| !ft_strncmp(input_stack[i], "+", 2))
			ft_exit(new_input_stack);
		if (!input_stack[i][0])
			ft_exit(new_input_stack);
		ft_lstadd_back(&new_input_stack, ft_lstnew(ft_atoi(input_stack[i])));
	}
	if (ft_check_duplicate(new_input_stack))
		ft_exit(new_input_stack);
	if (ft_is_list_sorted(new_input_stack))
		ft_exit_sorted(new_input_stack);
	if (argc == 2)
		free_substrings(input_stack);
	return (new_input_stack);
}
