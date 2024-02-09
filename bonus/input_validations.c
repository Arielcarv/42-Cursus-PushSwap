/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:50:25 by arcarval          #+#    #+#             */
/*   Updated: 2024/02/09 18:20:53 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			if (ft_atoi(*input_stack) == 0
				&& !ft_isdigit(*input_stack[0]))
				ft_printf("Error\n");
			ft_exit_unitary(input_stack);
		}
		return (input_stack);
	}
	return (argv);
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
	if (argc == 2)
		free_substrings(input_stack);
	return (new_input_stack);
}
