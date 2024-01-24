/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:34:41 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/24 18:45:32 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stack *stack_a)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(&stack_a, ft_free);
	exit(1);
}

void	ft_exit_sorted(t_stack *stack_a)
{
	ft_lstclear(&stack_a, ft_free);
	exit(1);
}
