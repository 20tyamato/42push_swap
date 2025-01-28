#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

# define SMALL_STACK_THRESHOLD 5

typedef struct s_array
{
	long long	*array;
	int			size;
}	t_array;

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

typedef struct s_operation_count
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operation_count;

// stack operations
t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
t_stack	*copy_stack(t_stack *stack);

void	push(t_stack *stack, int data);
int		pop(t_stack *stack);

bool	is_sorted(t_stack *stack);
bool	is_rev_sorted(t_stack *stack);

// parsing
int		get_string_array_size(char **str);
void	free_string_array(char **str);


// ================================================================

void	repeat_operation(void (*op)(t_stack *, t_stack *),
								t_stack *a, t_stack *b, int count);

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

void	fake_forward_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	fake_forward_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	fake_reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	fake_reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);

// debug
void	print_stack(t_stack *stack);
void	print_stack_side_by_side(t_stack *stack1, t_stack *stack2);
void	print_operation_count(t_operation_count *operation_count);

#endif
