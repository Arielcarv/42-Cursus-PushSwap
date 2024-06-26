/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:17 by arcarval          #+#    #+#             */
/*   Updated: 2024/02/14 18:40:24 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

char	*get_next_line(int file_descriptor);

void	*ft_calloc_gnl(size_t number_spaces, size_t size);
int		ft_strlcpy_gnl(char *dest, char const *src, int size);
char	*ft_strjoin_gnl(char *str1, char *str2);

void	ft_printlist(t_stack *lst);
void	ft_free(int nbr);
int		ft_is_list_sorted(t_stack *stack_a);
int		ft_check_duplicate(t_stack *stack_a);
void	ft_exit(t_stack *stack_a);
void	ft_exit_sorted(t_stack *stack_a);
void	ft_exit_unitary(char **stack);
void	ft_exit_error(char **input_stack, t_stack *new_input_stack);
void	get_out(int argc, char **input_stack, t_stack *new_input_stack);
void	free_substrings(char **stack);
int		ft_is_sign(char letter);
int		ft_atoi_push_bonus(int argc, char const *str,
			char **input_stack, t_stack *new_stack);
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

#endif