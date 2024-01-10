/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:54:23 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/10 12:18:19 by arcarval         ###   ########.fr       */
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

void	ft_printlist_index(t_stack *lst)
{
	ft_printf("↓ PRINT INDEX ↓\n");
	while (lst)
	{
		ft_printf("%d -> %d \n", lst->index, lst->nbr);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	ft_free(int nbr)
{
	(void)nbr;
}

int	find_min_nbr(t_stack **stack)
{
	int		min_nbr;
	t_stack	*temp_1;

	temp_1 = *stack;
	min_nbr = temp_1->nbr;
	while (temp_1->next)
	{
		if (temp_1->next->nbr < min_nbr)
			min_nbr = temp_1->next->nbr;
		else
			temp_1 = temp_1->next;
	}
	return (min_nbr);
}
