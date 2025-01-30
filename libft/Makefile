NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 
DEPS = libft.h

# **************************************************************************** #
# Mandatory Functions x 23                                                     #
# **************************************************************************** #
SRCS += ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c
SRCS += ft_strlen.c
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_strlcpy.c
SRCS += ft_strlcat.c
SRCS += ft_toupper.c
SRCS += ft_tolower.c
SRCS += ft_strchr.c
SRCS += ft_strrchr.c
SRCS += ft_strncmp.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_strnstr.c
SRCS += ft_atoi.c
SRCS += ft_calloc.c
SRCS += ft_strdup.c

# **************************************************************************** #
# Additional Functions x 11                                                    #
# **************************************************************************** #
SRCS += ft_substr.c
SRCS += ft_strjoin.c
SRCS += ft_strtrim.c
SRCS += ft_split.c
SRCS += ft_itoa.c
SRCS += ft_strmapi.c
SRCS += ft_striteri.c
SRCS += ft_putchar_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c

# **************************************************************************** #
# gnl Functions x 1                                                            #
# **************************************************************************** #
SRCS += get_next_line.c
SRCS += ft_strcmp.c

# **************************************************************************** #
# Bonus Functions x 9                                                          #
# **************************************************************************** #
# BONUS_SRCS = 
# BONUS_SRCS += ft_lstnew.c
# BONUS_SRCS += ft_lstadd_front.c
# BONUS_SRCS += ft_lstsize.c
# BONUS_SRCS += ft_lstlast.c
# BONUS_SRCS += ft_lstadd_back.c
# BONUS_SRCS += ft_lstdelone.c
# BONUS_SRCS += ft_lstclear.c
# BONUS_SRCS += ft_lstiter.c
# BONUS_SRCS += ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re bonus
