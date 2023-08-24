/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:03 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/24 19:53:26 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(char **argv)
{
	int		i;
	// char	*merged_input;

	i = 1;
	// Some arguments aren’t integers,
	while(argv[i])
	{
		printf("%s", argv[i]);
		// merged_input = ft_strjoin(merged_input, argv[i]);
		i++;
	}
	// Some arguments are bigger than an integer
	// There are duplicates
	// printf("%s", merged_input);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	if (!valid_input(argv))
	{
		ft_printf("Error\n");
		exit(1);
	}
	ft_printf("ARGC: %d", argc);
	ft_printf("\nARGV: %s", argv[0]);
	ft_printf("\n");
	
	return (0);
}