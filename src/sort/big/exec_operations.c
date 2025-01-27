#include "push_swap.h"

void	calc_minimum_steps_for_a(t_stack *a, t_operation_count *operation_count, int value);
void	calc_minimum_steps_for_b(t_stack *b, t_operation_count *operation_count, int value);

static void	repeat_operation(void (*op)(t_stack *, t_stack *),
								t_stack *a, t_stack *b, int count)
{
	while (count-- > 0)
		op(a, b);
}

void	exec_operations(t_stack *a, t_stack *b, int value)
{
	t_operation_count	*op_count;

	op_count = init_operation_count();
	calc_minimum_steps_for_a(a, op_count, value);
	calc_minimum_steps_for_b(b, op_count, value);
	merge_operations(op_count);
	repeat_operation(forward_rotate_a, a, b, op_count->ra);
	repeat_operation(forward_rotate_b, a, b, op_count->rb);
	repeat_operation(forward_rotate_ab, a, b, op_count->rr);
	repeat_operation(reverse_rotate_a, a, b, op_count->rra);
	repeat_operation(reverse_rotate_b, a, b, op_count->rrb);
	repeat_operation(reverse_rotate_ab, a, b, op_count->rrr);
	push_b(a, b);
}
