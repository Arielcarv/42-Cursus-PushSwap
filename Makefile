# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 16:58:50 by arcarval          #+#    #+#              #
#    Updated: 2024/01/01 16:42:25 by arcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLACK				=	\033[0;30m
BLUE				=	\033[0;34m
CYAN				=	\033[0;36m
GREEN				=	\033[0;32m
MAGENTA				=	\033[1;35m
ORANGE				=	\033[1;38;5;214m
RED					=	\033[0;31m
RESET				=	\033[0m
WHITE				=	\033[0;37m
YELLOW				=	\033[0;33m

# PUSH_SWAP
NAME				=	push_swap
HEADER				=	push_swap.h
INCLUDES_PATH		=	includes/
SRC_PATH			=	src/
OBJ_PATH			=	obj/
LIBFT				=	$(INCLUDES_PATH)Libft/
FT_PRINTF			=	$(INCLUDES_PATH)ft_printf/
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

PUSH_SWAP_SRCS		=	push_swap.c			swap_operations.c	push_operations.c \
						rotate_operations.c	reverse_rotate_operations.c \
						input_validations.c	utils.c			index.c \
						sort_three.c		sort_four.c		sort_five.c

PUSH_SWAP_OBJS		=	$(addprefix $(OBJ_PATH), $(PUSH_SWAP_SRCS:.c=.o))
INCLUDES			=	-I $(INCLUDES_PATH)

AR					=	ar -rcs
RM					=	rm -rf

all:			$(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(WHITE)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
				@mkdir $(OBJ_PATH)

$(NAME):		libft printf $(PUSH_SWAP_OBJS)
				$(CC) $(PUSH_SWAP_OBJS) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME)
				@echo "$(CYAN) PUSH_SWAP - I'm ready to work! 🧠$(RESET)"

libft:
				@make bonus -C $(LIBFT)

printf:
				@make -C $(FT_PRINTF)

clean:
				@$(RM) $(PUSH_SWAP_OBJS)
				@$(RM) $(OBJ_PATH)
				@echo "$(CYAN) FRACTOL - Bye Laziness, Bye dirt 🚿$(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -C $(INCLUDES_PATH)/Libft
				@make fclean -C $(INCLUDES_PATH)/ft_printf
				@echo "$(CYAN) PUSH_SWAP - Bath is so good!  Now it's over. 🧼✨$(RESET)"

norm:
				norminette -R CheckForbiddenSourceHeader $(addprefix $(SRC_PATH), $(PUSH_SWAP_SRCS)) $(INCLUDES_PATH)$(HEADER) $(INCLUDES_PATH)Libft/*.c  $(INCLUDES_PATH)Libft/*.h  $(INCLUDES_PATH)ft_printf/*.c  $(INCLUDES_PATH)ft_printf/*.h

re:				fclean all

.PHONY:	all $(NAME) libft printf bonus clean fclean re
