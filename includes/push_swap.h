/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:03:01 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/21 16:14:10 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

void	ft_printlist(t_stack *lst);
void	ft_printlist_index(t_stack *stack_a);
void	ft_free(int nbr);
int		ft_is_list_sorted(t_stack *stack_a);
void	build_index(t_stack **stack_a);
void	ft_exit(t_stack *stack_a);
void	free_substrings(char **stack);
t_stack	*process_input(int argc, char **argv);

void	swap_a(t_stack **stack_a, int print);
void	swap_b(t_stack **stack_a, int print);
void	swap_ss(t_stack **stack_a, t_stack **stack_b, int print);
void	push_a(t_stack **stack_b, t_stack **stack_a, int print);
void	push_b(t_stack **stack_a, t_stack **stack_b, int print);
void	rotate_a(t_stack **stack_a, int print);
void	rotate_b(t_stack **stack_b, int print);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b, int print);
void	reverse_rotate_a(t_stack **stack_a, int print);
void	reverse_rotate_b(t_stack **stack_b, int print);
void	reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b, int print);

int		find_min_nbr(t_stack **stack);

void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_radix(t_stack **stack_a, t_stack **stack_b);

#endif