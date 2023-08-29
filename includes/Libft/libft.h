/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:37 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/29 17:29:46 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int		ft_isalpha(int caracter);
int		ft_isdigit(int caracter);
int		ft_isalnum(int caracter);
int		ft_isascii(int caracter);
int		ft_isprint(int caracter);
size_t	ft_strlen(char const *str);
void	*ft_memset(void *str, int caracter, size_t length);
void	ft_bzero(void *str, size_t number);
void	*ft_memcpy(void *dest, const void *src, size_t char_number);
void	*ft_memmove(void *str1, const void *str2, size_t char_number);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
size_t	ft_strlcat(char *dest, char const *src, size_t size);
int		ft_toupper(int caracter);
int		ft_tolower(int caracter);
char	*ft_strchr(char const *str, int caracter);
char	*ft_strrchr(char const *str, int caracter);
int		ft_strncmp(char const *str1, char const *str2, size_t char_number);
void	*ft_memchr(const void *str, int caracter, size_t char_number);
int		ft_memcmp(const void *str, const void *str2, size_t char_number);
char	*ft_strnstr(char const *haystack, char const *needle, size_t str_len);
int		ft_atoi(char const *str);
void	*ft_calloc(size_t number_spaces, size_t size);
char	*ft_strdup(char const *str);
char	*ft_substr(char const *src, unsigned int beginning, size_t max_length);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str, char delimiter);
char	*ft_itoa(int number);
char	*ft_strmapi(char const *str, char (*function)(unsigned int, char));
void	ft_striteri(char *str, void (*function)(unsigned int, char*));
void	ft_putchar_fd(char caracter, int file_descriptor);
void	ft_putstr_fd(char *str, int file_descriptor);
void	ft_putendl_fd(char *str, int file_descriptor);
void	ft_putnbr_fd(int number, int file_desciptor);

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_lstnew(int nbr);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(int));
void	ft_lstclear(t_stack **lst, void (*del)(int));
void	ft_lstiter(t_stack *lst, void (*function)(int));
t_stack	*ft_lstmap(t_stack *lst, int *(*function)(int), void (*del)(int));

#endif
