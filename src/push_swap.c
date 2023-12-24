/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:03 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/24 00:22:00 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_switch(int stack_size, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_1;

	temp_1 = *stack_a;
	if (stack_size == 2 && (temp_1->nbr > temp_1->next->nbr))
		swap_a(stack_a);
	if (stack_size == 3)
		sort_three(stack_a);
	if (stack_size == 4)
		sort_four(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = process_input(argc, argv);
	// stack_b = process_input(argc, argv);
	stack_b = NULL;
	ft_printlist(stack_a);
	ft_printlist(stack_b);
	if (!stack_a)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (ft_is_list_sorted(stack_a))
		ft_printf("IT'S SORTED\n");
	else
		ft_printf("NOT SORTED\n");
	// For radix needs to build an index with stack
	// build_index(stack_a);
	ft_printf("List Size: %d", ft_lstsize(stack_a));
	ft_printf("\nARGC: %d", argc);
	ft_printf("\nARGV[0]: %s", argv[0]);
	ft_printf("\n");

	sorting_switch(ft_lstsize(stack_a), &stack_a, &stack_b);

	ft_printlist(stack_a);
	ft_printlist(stack_b);

	/* By the end of it all needs to clean stacks */
	ft_lstclear(&stack_a, ft_free);
	ft_lstclear(&stack_b, ft_free);
	return (0);
}
