/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:03 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 15:10:47 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(t_list *lst)
{
	ft_printf("\nPRINT LIST: ");
	while (lst)
	{
		ft_printf("%d ", lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

t_list	*process_input(int argc, char **argv)
{
	int		i;
	t_list	*new_input_list;
	int		current_number;
	char	**input_list;

	if (argc == 2)
		input_list = ft_split(argv[1], ' ');
	else
		input_list = argv;
	new_input_list = NULL;
	i = 1;
	while (input_list[i])
	{
		current_number = ft_atoi(input_list[i]);
		ft_lstadd_front(&new_input_list, ft_lstnew(current_number));
		i++;
	}
	return (new_input_list);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	// process_input(argc, argv);
	if (!process_input(argc, argv))
	{
		ft_printf("Error\n");
		exit(1);
	}
	ft_printf("ARGC: %d", argc);
	ft_printf("\nARGV: %s", argv[0]);
	ft_printf("\n");
	return (0);
}
