/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:03 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/16 14:22:57 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_switch(int argc, t_stack **stack_a)
{
	t_stack	*temp_1;

	temp_1 = *stack_a;
	if (argc == 3 && (temp_1->nbr > temp_1->next->nbr))
		swap_a(stack_a);
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

	// sorting_switch(argc, &stack_a, &stack_b);
	sorting_switch(argc, &stack_a);

	ft_printlist(stack_a);
	ft_printlist(stack_b);

	/* By the end of it all needs to clean stacks */
	ft_lstclear(&stack_a, ft_free);
	ft_lstclear(&stack_b, ft_free);
	return (0);
}
