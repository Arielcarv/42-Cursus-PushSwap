/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:03 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/18 10:41:20 by arcarval         ###   ########.fr       */
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
	if (stack_size == 5)
		sort_five(stack_a, stack_b);
	if (stack_size > 5)
		sort_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (0);
	stack_a = process_input(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (!ft_is_list_sorted(stack_a))
	{
		build_index(&stack_a);
		sorting_switch(ft_lstsize(stack_a), &stack_a, &stack_b);
		ft_lstclear(&stack_a, ft_free);
		ft_lstclear(&stack_b, ft_free);
	}
	return (0);
}
