#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

t_stack	*create_stack(void);
bool	parse_args(int argc, char **argv, t_stack *a, t_stack *b);
bool is_sorted(t_stack *a, t_stack *b);
void push_swap(t_stack *a, t_stack *b);

int	error_exit(t_stack *a, t_stack *b);
int	clean_exit(t_stack *a, t_stack *b);

#endif
