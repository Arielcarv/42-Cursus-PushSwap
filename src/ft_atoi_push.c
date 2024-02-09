/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:18:17 by arcarval          #+#    #+#             */
/*   Updated: 2024/02/09 16:17:21 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_is_sign(char letter)
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

static int	is_min_max_int(char const *str, int signal, int number)
{
	if (!ft_isdigit(*str)
		|| (signal == 1 && (number > (2147483647 - (*str - '0')) / 10))
		|| (signal == -1
			&& ((number < (-2147483648 + (*str - '0')) / 10)
				|| (number > (2147483648 - (*str - '0')) / 10))))
		return (1);
	return (0);
}

int	ft_atoi_push(int argc, char const *str,
				char **input_stack, t_stack *new_input_stack)
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
		if (is_min_max_int(str, signal, number))
			get_out(argc, input_stack, new_input_stack);
		number = (*str - '0') + (number * 10);
		str++;
	}
	return (signal * number);
}
