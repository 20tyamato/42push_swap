#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

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
void	free_stack(t_stack *stack);

void	push(t_stack *stack, int data);
int		pop(t_stack *stack);

bool	parse_args(int argc, char **argv, t_stack *a, t_stack *b);
bool	is_sorted(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

int		error_exit(t_stack *a, t_stack *b);
int		clean_exit(t_stack *a, t_stack *b);

void	forward_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	forward_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	forward_rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	swap_a(t_stack *stack_a, t_stack *stack_b);
void	swap_b(t_stack *stack_a, t_stack *stack_b);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);

#endif
