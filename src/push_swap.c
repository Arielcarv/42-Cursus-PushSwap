/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:03 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/28 00:14:06 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_strjoin1(char *str1, char str2)
{
	int str1_length;
	int str2_length;
	char *dest;

	if (!str1)
		str1 = ft_calloc(1, sizeof(char));
	if (!str2)
	{
		return (NULL);
	}
	str1_length = ft_strlen(str1);
	str2_length = 1;
	int size = str1_length + str2_length + 1;
	dest = malloc((size) * sizeof(char));
	ft_strlcpy(dest, str1, str1_length + 1);
	printf("%s", dest);
	printf("%d", size);
	// dest[size - 1] = str2;
	dest[size] = '\0';
	// free(str1);
	return (dest);
}

size_t ft_strlcat1(char *dest, char src, size_t size)
{
	size_t src_len;
	size_t dest_len;

	if (!src || !dest)
		return (0);
	src_len = 1;
	dest_len = ft_strlen(dest);
	if (size < dest_len)
		return (size + src_len);

	dest[dest_len] = src;
	dest[dest_len + 1] = '\0';
	return (dest_len + src_len);
}

int	valid_input(char **argv)
{
	int		i;
	int		j;
	char	*merged_input;

	i = 1;
	// Some arguments aren’t integers,
	merged_input = "  ";
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			write(1, &argv[i][j], 1);
			write(1, "\n", 1);
			ft_strlcat1(merged_input, argv[i][j], 1);
			j++;
		}
		i++;
	}
	// Some arguments are bigger than an integer
	// There are duplicates
	// i = 0;
	// while (merged_input)
	// {
	// 	write(1, &merged_input[i++], 1);
	// }
	printf("\n%s", merged_input);
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