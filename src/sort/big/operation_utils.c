#include "push_swap.h"

void	calc_minimum_steps_for_a(t_stack *a, t_stack *b, t_operation_count *operation_count, int value);
void	calc_minimum_steps_for_b(t_stack *a, t_stack *b, t_operation_count *operation_count, int value);

t_operation_count	*init_operation_count(void)
{
	t_operation_count	*operation_count;

	operation_count = (t_operation_count *)malloc(sizeof(t_operation_count));
	if (!operation_count)
		return (NULL);
	operation_count->ra = 0;
	operation_count->rb = 0;
	operation_count->rr = 0;
	operation_count->rra = 0;
	operation_count->rrb = 0;
	operation_count->rrr = 0;
	return (operation_count);
}

void	reset_operation_count(t_operation_count *operation_count)
{
	operation_count->ra = 0;
	operation_count->rb = 0;
	operation_count->rr = 0;
	operation_count->rra = 0;
	operation_count->rrb = 0;
	operation_count->rrr = 0;
}

int	merge_operations(t_operation_count *operation_count)
{
	int	r_sum;
	int	rr_sum;

	r_sum = 0;
	rr_sum = 0;
	while (operation_count->ra > 0
		&& operation_count->rb > 0)
	{
		operation_count->rr++;
		operation_count->ra--;
		operation_count->rb--;
	}
	while (operation_count->rra > 0
		&& operation_count->rrb > 0)
	{
		operation_count->rrr++;
		operation_count->rra--;
		operation_count->rrb--;
	}
	r_sum = operation_count->ra + operation_count->rb + operation_count->rr;
	rr_sum = operation_count->rra + operation_count->rrb + operation_count->rrr;
	if (r_sum < rr_sum)
	{
		operation_count->rra = 0;
		operation_count->rrb = 0;
		operation_count->rrr = 0;
		return (r_sum);
	}
	else
	{
		operation_count->ra = 0;
		operation_count->rb = 0;
		operation_count->rr = 0;
		return (rr_sum);
	}
}

void	repeat_operation(void (*op)(t_stack *, t_stack *),
								t_stack *a, t_stack *b, int count)
{
	while (count-- > 0)
		op(a, b);
}

void	exec_operations(t_stack *a, t_stack *b, int value)
{
	t_operation_count	*op_count;

	op_count = init_operation_count();
	calc_minimum_steps_for_a(a, b, op_count, value);
	calc_minimum_steps_for_b(a, b, op_count, value);
	merge_operations(op_count);
	repeat_operation(forward_rotate_a, a, b, op_count->ra);
	repeat_operation(forward_rotate_b, a, b, op_count->rb);
	repeat_operation(forward_rotate_ab, a, b, op_count->rr);
	repeat_operation(reverse_rotate_a, a, b, op_count->rra);
	repeat_operation(reverse_rotate_b, a, b, op_count->rrb);
	repeat_operation(reverse_rotate_ab, a, b, op_count->rrr);
	push_b(a, b);
	free(op_count);
}
