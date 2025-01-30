CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address

NAME = push_swap
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

BONUS_NAME = checker

SRC_DIR = ./src
OBJ_DIR = ./obj
BONUS_OBJ_DIR = ./bonus_obj
INC_DIR = ./include

# SRC_FILES = $(shell find $(SRC_DIR) -type f -name '*.c')
SRC_FILE_NAMES = sort/big/merge_operations.c\
				sort/big/minimum_sorting.c\
				sort/big/calc_utils.c\
				sort/big/operation_utils.c\
				sort/big/big_sort.c\
				sort/small/small_sort.c\
				sort/push_swap.c\
				additional_libft/ft_max.c\
				additional_libft/print_aligned.c\
				additional_libft/ft_atoll.c\
				additional_libft/ft_min.c\
				exit.c\
				main.c\
				stack/is_stack_sorted.c\
				stack/operations/pa.c\
				stack/operations/rr.c\
				stack/operations/rrb.c\
				stack/operations/pb.c\
				stack/operations/rra.c\
				stack/operations/rb.c\
				stack/operations/rrr.c\
				stack/operations/sb.c\
				stack/operations/ra.c\
				stack/operations/ss.c\
				stack/operations/sa.c\
				stack/stack_operations.c\
				stack/stack_helpers.c\
				stack/stack_analysis.c\
				stack/print_stack_side_by_side.c\
				parsing/parse_args.c\
				parsing/to_array.c\
				parsing/check_array.c\
				parsing/split_utils.c\
				parsing/check_args.c
SRC_FILES      = $(addprefix $(SRC_DIR)/, $(SRC_FILE_NAMES))
OBJ_FILES      = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

BONUS_SRC_FILES = $(filter-out $(SRC_DIR)/main.c, $(SRC_FILES)) \
                  $(SRC_DIR)/checker.c
BONUS_OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BONUS_OBJ_DIR)/%.o,$(BONUS_SRC_FILES))

INCS = -I $(INC_DIR) -L $(LIBFTDIR) -lft

GREEN = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re debug bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(INCS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

# ボーナス用オブジェクト
$(BONUS_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFTDIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ_FILES)
	@$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) -o $@ $(INCS)
	@echo "\n$(BONUS_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(BONUS_NAME): $(GREEN)$(BONUS_NAME) was created$(RESET)"

clean:
	@$(MAKE) -sC $(LIBFTDIR) clean
	@if [ -d "$(OBJ_DIR)" ]; then rm -rf $(OBJ_DIR); echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"; fi
	@if [ -d "$(BONUS_OBJ_DIR)" ]; then rm -rf $(BONUS_OBJ_DIR); echo "$(BONUS_NAME): $(RED)$(BONUS_OBJ_DIR) was deleted$(RESET)"; fi
	@if [ -n "$(shell find $(OBJ_DIR) 2>/dev/null)" ]; then echo "$(NAME): $(RED)object files were deleted$(RESET)"; fi
	@if [ -n "$(shell find $(BONUS_OBJ_DIR) 2>/dev/null)" ]; then echo "$(BONUS_NAME): $(RED)object files were deleted$(RESET)"; fi

fclean: clean
	@$(MAKE) -sC $(LIBFTDIR) fclean
	@if [ -f "$(NAME)" ]; then rm -f $(NAME); echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"; fi
	@if [ -f "$(BONUS_NAME)" ]; then rm -f $(BONUS_NAME); echo "$(BONUS_NAME): $(RED)$(BONUS_NAME) was deleted$(RESET)"; fi

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all

re: fclean all
