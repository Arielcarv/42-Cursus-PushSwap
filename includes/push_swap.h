/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:03:01 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/03 22:01:50 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_a);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);

#endif