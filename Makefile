# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 16:58:50 by arcarval          #+#    #+#              #
#    Updated: 2024/01/24 18:38:34 by arcarval         ###   ########.fr        #
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
NAME_BONUS			=	checker
HEADER				=	push_swap.h
INCLUDES_PATH		=	includes/
SRC_PATH			=	src/
BONUS_PATH			=	bonus/
OBJ_PATH			=	obj/
OBJ_BONUS_PATH		=	bonus/obj/
LIBFT				=	$(INCLUDES_PATH)Libft/
FT_PRINTF			=	$(INCLUDES_PATH)ft_printf/
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
INCLUDES			=	-I $(INCLUDES_PATH)
AR					=	ar -rcs
RM					=	rm -rf

PUSH_SWAP_SRCS		=	push_swap.c			operations_swap.c	operations_push.c \
						operations_rotate.c	operations_reverse_rotate.c \
						input_validations.c	utils.c			build_index.c	utils_exit.c \
						sort_three.c		sort_four.c		sort_five.c		sort_radix.c

PUSH_SWAP_OBJS		=	$(addprefix $(OBJ_PATH), $(PUSH_SWAP_SRCS:.c=.o))

PUSH_SWAP_BONUS_SRCS=	checker.c	get_next_line_utils.c	get_next_line.c \
						operations_swap.c	operations_push.c \
						operations_rotate.c	operations_reverse_rotate.c \
						input_validations.c	utils.c

PUSH_SWAP_BONUS_OBJS=	$(addprefix $(OBJ_BONUS_PATH), $(PUSH_SWAP_BONUS_SRCS:.c=.o))


all:			$(NAME)

bonus:			$(NAME_BONUS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(WHITE)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_PATH)%.o: $(BONUS_PATH)%.c
				@mkdir -p $(OBJ_BONUS_PATH)
				@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(WHITE)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_BONUS_PATH)
				@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(WHITE)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):		libft printf $(PUSH_SWAP_OBJS)
				@$(CC) $(PUSH_SWAP_OBJS) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME)
				@echo "$(CYAN) PUSH_SWAP - I'm ready to work! 🧠$(RESET)"

$(NAME_BONUS):	libft printf $(PUSH_SWAP_BONUS_OBJS)
				@$(CC) $(PUSH_SWAP_BONUS_OBJS) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME_BONUS)
				@echo "$(CYAN) CHECKER - I'm ready to work! 🧠$(RESET)"

libft:
				@make --no-print-directory bonus -C $(LIBFT)

printf:
				@make --no-print-directory -C $(FT_PRINTF) > /dev/null

clean:
				@$(RM) $(PUSH_SWAP_OBJS)
				@$(RM) $(OBJ_PATH)
				@$(RM) $(PUSH_SWAP_BONUS_OBJS)
				@$(RM) $(OBJ_BONUS_PATH)
				@make --no-print-directory clean -C $(INCLUDES_PATH)/Libft
				@make --no-print-directory clean -C $(INCLUDES_PATH)/ft_printf
				@echo "$(CYAN) PUSH_SWAP - Bye Laziness, Bye dirt 🚿$(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)
				@make --no-print-directory fclean -C $(INCLUDES_PATH)/Libft
				@make --no-print-directory fclean -C $(INCLUDES_PATH)/ft_printf
				@echo "$(CYAN) PUSH_SWAP - Bath is so good!  Now it's over. 🧼✨$(RESET)"

test5:
				@ARG=$$(python3 -c "import random; print(' '.join(map(str, random.sample(range(5), 5))) )"); \
				./push_swap $$ARG | wc -l

test100:
				@ARG=$$(python3 -c "import random; print(' '.join(map(str, random.sample(range(100), 100))) )"); \
				./push_swap $$ARG | wc -l

test500:
				@ARG=$$(python3 -c "import random; print(' '.join(map(str, random.sample(range(500), 500))) )"); \
				./push_swap $$ARG | wc -l

norm:
				@norminette -R CheckForbiddenSourceHeader \
					$(addprefix $(SRC_PATH), $(PUSH_SWAP_SRCS)) \
					$(addprefix $(BONUS_PATH), *.c) \
					$(INCLUDES_PATH)$(HEADER) \
					$(INCLUDES_PATH)Libft/*.c \
					$(INCLUDES_PATH)Libft/*.h \
					$(INCLUDES_PATH)ft_printf/*.c \
					$(INCLUDES_PATH)ft_printf/*.h
					

re:				fclean all

.PHONY:	all $(NAME) $(NAME_BONUS) libft printf bonus clean fclean re
