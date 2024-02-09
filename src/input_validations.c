/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:14:05 by arcarval          #+#    #+#             */
/*   Updated: 2024/02/09 18:21:13 by arcarval         ###   ########.fr       */
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
		{
			if (ft_strncmp(*input_stack, "0", 2)
				&& ft_atoi(*input_stack) == 0)
				ft_putstr_fd("Error\n", 2);
			ft_exit_unitary(input_stack);
		}
		return (input_stack);
	}
	return (argv);
}

static void	input_checks(int argc, int i,
		char **input_stack, t_stack *new_stack)
{
	if (!ft_strncmp(input_stack[i], "-", 2)
		|| !ft_strncmp(input_stack[i], "+", 2))
	{
		if (argc == 2)
			ft_exit_error(input_stack, new_stack);
		else
			ft_exit(new_stack);
	}
	if (!input_stack[i][0])
		ft_exit(new_stack);
}

static void	check_non_digit(int i, char **input_stack)
{
	int	x;
	int	y;

	x = 0;
	if (i == 0)
		x = 1;
	while (input_stack[x])
	{
		y = 0;
		while (input_stack[x][y])
		{
			if (!ft_isdigit(input_stack[x][y])
				&& !ft_is_sign(input_stack[x][y]))
			{
				ft_putstr_fd("Error\n", 2);
				if (i == 0)
					exit(1);
				ft_exit_unitary(input_stack);
			}
			y++;
		}
		x++;
	}
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
	check_non_digit(i, input_stack);
	new_input_stack = NULL;
	while (input_stack[++i])
	{
		input_checks(argc, i, input_stack, new_input_stack);
		ft_lstadd_back(&new_input_stack,
			ft_lstnew(
				ft_atoi_push(argc, input_stack[i],
					input_stack, new_input_stack)));
	}
	if (ft_check_duplicate(new_input_stack))
		ft_exit(new_input_stack);
	if (ft_is_list_sorted(new_input_stack))
		ft_exit_sorted(new_input_stack);
	if (argc == 2)
		free_substrings(input_stack);
	return (new_input_stack);
}
