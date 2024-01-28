/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:37:49 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/27 21:04:16 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_input(t_stack **stack_a, t_stack **stack_b, char *line)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(stack_a, ft_free);
	ft_lstclear(stack_b, ft_free);
	free(line);
	exit(1);
}

void	do_checker_moves(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp("sa\n", line, 3))
		swap_a(stack_a, 0);
	else if (!ft_strncmp("sb\n", line, 3))
		swap_b(stack_a, 0);
	else if (!ft_strncmp("ss\n", line, 3))
		swap_ss(stack_a, stack_b, 0);
	else if (!ft_strncmp("pa\n", line, 3))
		push_a(stack_b, stack_a, 0);
	else if (!ft_strncmp("pb\n", line, 3))
		push_b(stack_a, stack_b, 0);
	else if (!ft_strncmp("ra\n", line, 3))
		rotate_a(stack_a, 0);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate_b(stack_a, 0);
	else if (!ft_strncmp("rr\n", line, 3))
		rotate_rr(stack_a, stack_b, 0);
	else if (!ft_strncmp("rra\n", line, 4))
		reverse_rotate_a(stack_a, 0);
	else if (!ft_strncmp("rrb\n", line, 4))
		reverse_rotate_b(stack_a, 0);
	else if (!ft_strncmp("rrr\n", line, 4))
		reverse_rotate_rrr(stack_a, stack_b, 0);
	else
		error_input(stack_a, stack_b, line);
}

void	get_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	(void)stack_a;
	line = get_next_line(0);
	while (line)
	{
		do_checker_moves(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_is_list_sorted(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = process_input(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(&stack_a, ft_free);
		exit(1);
	}
	get_moves(&stack_a, &stack_b);
	ft_lstclear(&stack_a, ft_free);
	ft_lstclear(&stack_b, ft_free);
	return (0);
}
