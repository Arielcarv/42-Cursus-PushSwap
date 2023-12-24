/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:54:23 by arcarval          #+#    #+#             */
/*   Updated: 2023/12/24 14:00:50 by arcarval         ###   ########.fr       */
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
	ft_printf("PRINT INDEX: ");
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
