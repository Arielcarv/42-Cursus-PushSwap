/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:37:49 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/18 12:44:47 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void get_moves(t_stack *stack_a)
// {
// 	char *line;

// 	(void)stack_a;
// 	line = get_next_line(0);
// 	while (line)
// 	{
// 		do_checker_moves(stack_a, line);
// 		free(line);
// 		line = get_next_line(0);
// 	}
// 	free(line);
// 	if (is_order_a(stack_a) && !stack_a->bsize)
// 		ft_printf("OK\n");
// 	else
// 		ft_printf("KO\n");
// }

// void do_checker_moves(t_ps *ps, char *line)
// {
// 	if (!ft_strcmp("pb\n", line))
// 		pb(ps, 0);
// 	else if (!ft_strcmp("pa\n", line))
// 		pa(ps, 0);
// 	else if (!ft_strcmp("ra\n", line))
// 		ra(ps, 0);
// 	else if (!ft_strcmp("rb\n", line))
// 		rb(ps, 0);
// 	else if (!ft_strcmp("rra\n", line))
// 		rra(ps, 0);
// 	else if (!ft_strcmp("rrb\n", line))
// 		rrb(ps, 0);
// 	else if (!ft_strcmp("sa\n", line))
// 		sa(ps, 0);
// 	else if (!ft_strcmp("sb\n", line))
// 		sb(ps, 0);
// 	else if (!ft_strcmp("rr\n", line))
// 		rr(ps, 0);
// 	else if (!ft_strcmp("rrr\n", line))
// 		rrr(ps, 0);
// 	else if (!ft_strcmp("ss\n", line))
// 		ss(ps, 0);
// 	else
// 		error_input(ps, line);
// }

// void	error_input(t_ps *ps, char *line)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	free_stacks(ps);
// 	free(line);
// 	exit(-1);
// }

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (0);
	stack_a = process_input(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_putstr_fd("KO\n", 2);
		exit(1);
	}
	ft_printlist(stack_a);
	// init_parse(argv, &stack_a);
	// get_moves(&stack_a);

	ft_lstclear(&stack_a, ft_free);
	ft_lstclear(&stack_b, ft_free);
	return (0);
}