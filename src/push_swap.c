/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:03 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/05 20:09:36 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(t_stack *lst)
{
	ft_printf("PRINT LIST: ");
	while (lst)
	{
		ft_printf("%d ", lst->nbr);
		lst = lst->next;
	}
	ft_printf("\n");
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

t_stack	*process_input(int argc, char **argv)
{
	int		i;
	int		current_number;
	char	**input_stack;
	t_stack	*new_input_stack;

	i = 0;
	if (argc == 2)
		input_stack = ft_split(argv[1], ' ');
	else
	{
		input_stack = argv;
		i = 1;
	}
	new_input_stack = NULL;
	while (input_stack[i])
	{
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

void	ft_free(int nbr)
{
	(void)nbr;
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = process_input(argc, argv);
	stack_b = process_input(argc, argv);
	ft_printlist(stack_a);
	ft_printlist(stack_b);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_is_list_sorted(stack_a))
		printf("IT'S SORTED\n");
	else
		printf("NOT SORTED\n");
		
	// For radix needs to build an index with stack
	// build_index(stack_a);
	ft_printf("List Size: %d", ft_lstsize(stack_a));
	ft_printf("\nARGC: %d", argc);
	ft_printf("\nARGV: %s", argv[0]);
	ft_printf("\n");
	// /* Test swap_ss */
	// swap_ss(&stack_a, &stack_b);
	// ft_printlist(stack_a);
	// ft_printlist(stack_b);
	/* Test push B to A */
	push_a(&stack_b, &stack_a);
	ft_printlist(stack_a);
	ft_printlist(stack_b);
	/* By the end of it all needs to clean stacks */
	ft_lstclear(&stack_a, ft_free);
	return (0);
}
