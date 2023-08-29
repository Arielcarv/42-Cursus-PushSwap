/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:16:18 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 17:31:29 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int *(*function)(int), void (*del)(int))
{
	t_stack	*new_lst;
	t_stack	*aux;

	new_lst = NULL;
	while (lst)
	{
		aux = ft_lstnew((int)*function(lst->nbr));
		if (!aux)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, aux);
		lst = lst->next;
	}
	return (new_lst);
}
