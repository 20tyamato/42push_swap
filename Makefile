CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address

NAME = push_swap
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include

SRC_FILES = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Include and Library flags
INCS = -I $(INC_DIR) -L $(LIBFTDIR) -lft

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -o $@ $(INCS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
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

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all

re: fclean all
