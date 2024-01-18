/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:17 by arcarval          #+#    #+#             */
/*   Updated: 2024/01/18 12:19:10 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

char	*get_next_line(int file_descriptor);

void	*ft_calloc_gnl(size_t number_spaces, size_t size);
int		ft_strlcpy_gnl(char *dest, char const *src, int size);
char	*ft_strjoin_gnl(char *str1, char *str2);

void	ft_printlist(t_stack *lst);
void	ft_free(int nbr);

t_stack	*process_input(int argc, char **argv);

#endif