/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:04:04 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 17:31:29 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack *lst, void (*function)(int))
{
	if (!lst)
		return ;
	while (lst)
	{
		function(lst->nbr);
		lst = lst->next;
	}
}
