/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:14:05 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/18 16:10:04 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	**ft_split_or_not(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (argv);
}

t_stack	*process_input(int argc, char **argv)
{
	int		i;
	int		current_number;
	char	**input_stack;
	t_stack	*new_input_stack;

	i = 1;
	if (argc == 2)
		i = 0;
	input_stack = ft_split_or_not(argc, argv);
	new_input_stack = NULL;
	while (input_stack[i])
	{
		if (!ft_strncmp(input_stack[i], "-", 2)
			|| !ft_strncmp(input_stack[i], "+", 2))
			return (NULL);
		if (!input_stack[i][0])
			return (NULL);
		current_number = ft_atoi(input_stack[i]);
		ft_lstadd_back(&new_input_stack, ft_lstnew(current_number));
		i++;
	}
	if (ft_check_duplicate(new_input_stack))
		return (NULL);
	return (new_input_stack);
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
