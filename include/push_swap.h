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
t_stack		*create_stack(void);
t_stack		*copy_stack(t_stack *stack);
void		free_stack(t_stack *stack);

void		push(t_stack *stack, int data);
int			pop(t_stack *stack);

bool		is_sorted(t_stack *stack);
bool		is_rev_sorted(t_stack *stack);

// stack getters
int			get_max_num_in_stack(t_stack *stack);
int			get_min_num_in_stack(t_stack *stack);
int			get_position_from_top(t_stack *stack, int value);
int			get_top_element_of_stack(t_stack *stack);
int			get_bottom_element_of_stack(t_stack *stack);

// parsing utils
int			get_string_array_size(char **str);
void		free_string_array(char **str);

// sort operations
void		forward_rotate_a(t_stack *stack_a, t_stack *stack_b);
void		forward_rotate_b(t_stack *stack_a, t_stack *stack_b);
void		forward_rotate_ab(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);
void		swap_a(t_stack *stack_a, t_stack *stack_b);
void		swap_b(t_stack *stack_a, t_stack *stack_b);
void		swap_ab(t_stack *stack_a, t_stack *stack_b);

void		fake_forward_rotate_a(t_stack *stack_a, t_stack *stack_b);
void		fake_forward_rotate_b(t_stack *stack_a, t_stack *stack_b);
void		fake_reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void		fake_reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);

// main sort functions
void		sort_small_stack(t_stack *a, t_stack *b);
void		sort_big_stack(t_stack *a, t_stack *b);

// ================================================================

void		repeat_operation(void (*op)(t_stack *, t_stack *),
				t_stack *a, t_stack *b, int count);

// Additional libft functions
long long	ft_atoll(const char *str);
int			ft_max(int a, int b);
int			ft_min(int a, int b);

// debug
void		print_stack(t_stack *stack);
void		print_stack_side_by_side(t_stack *stack1, t_stack *stack2);
void		print_operation_count(t_operation_count *operation_count);

#endif
