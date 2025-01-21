# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 16:04:02 by 20tyamato         #+#    #+#              #
#    Updated: 2024/06/10 21:57:18 by 20tyamato        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include

SRC_FILES = array_utils.c \
            forward_rotate.c \
            ft_atoi_long.c \
            input_handler_utils.c \
            input_handler.c \
            main.c \
            normalize.c \
            push_operations.c \
            push_swap.c \
            quick_sort.c \
            reverse_rotate.c \
            sorter.c \
            stack_operations.c \
            stack_utils.c \
            swap_operations.c \
            utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
INCS = -I $(INC_DIR) -L $(LIBFTDIR) -lft

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -o $@ $(INCS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFTDIR)

clean:
	@$(MAKE) -sC $(LIBFTDIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFTDIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all