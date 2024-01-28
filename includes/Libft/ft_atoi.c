/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:18:17 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/27 20:59:56 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	ft_is_whitespace(char letter)
{
	if ((letter == '\t')
		|| (letter == '\n')
		|| (letter == '\v')
		|| (letter == '\f')
		|| (letter == '\r')
		|| (letter == ' '))
		return (1);
	return (0);
}

static int	ft_is_sign(char letter)
{
	if (letter == '-' || letter == '+')
		return (1);
	return (0);
}

static int	ft_is_negative(char letter)
{
	if (letter == '-')
		return (1);
	return (0);
}

int	ft_atoi(char const *str)
{
	int	number;
	int	signal;

	signal = 1;
	number = 0;
	while (ft_is_whitespace(*str))
		str++;
	if (ft_is_sign(*str))
	{
		if (ft_is_negative(*str))
			signal *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str)
			|| (signal == 1 && (number > (2147483647 - (*str - '0')) / 10))
			|| (signal == -1
				&& ((number < (-2147483648 + (*str - '0')) / 10)
					|| (number > (2147483648 - (*str - '0')) / 10))))
			ft_error_exit();
		number = (*str - '0') + (number * 10);
		str++;
	}
	return (signal * number);
}
