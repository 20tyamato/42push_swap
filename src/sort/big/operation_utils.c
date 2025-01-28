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

int merge_operations(t_operation_count *op)
{
    int ra  = op->ra;
    int rb  = op->rb;
    int rra = op->rra;
    int rrb = op->rrb;

    int cost_rr      = ft_max(ra, rb);
    int cost_rrr     = ft_max(rra, rrb);
    int cost_ra_rrb  = ra + rrb;
    int cost_rra_rb  = rra + rb;

    int best_cost = cost_rr;
    char best_scenario = 'A';

    if (cost_rrr < best_cost)
    {
        best_cost = cost_rrr;
        best_scenario = 'B';
    }
    if (cost_ra_rrb < best_cost)
    {
        best_cost = cost_ra_rrb;
        best_scenario = 'C';
    }
    if (cost_rra_rb < best_cost)
    {
        best_cost = cost_rra_rb;
        best_scenario = 'D';
    }
    op->rr  = 0;
    op->rrr = 0;
    op->ra  = 0;
    op->rb  = 0;
    op->rra = 0;
    op->rrb = 0;

    if (best_scenario == 'A')
    {
        op->rr = ft_min(ra, rb);
        op->ra = ra - op->rr;
        op->rb = rb - op->rr;
    }
    else if (best_scenario == 'B')
    {
        op->rrr = ft_min(rra, rrb);
        op->rra = rra - op->rrr;
        op->rrb = rrb - op->rrr;
    }
    else if (best_scenario == 'C')
    {
        op->ra  = ra;
        op->rrb = rrb;
    }
    else
    {
        op->rra = rra;
        op->rb  = rb;
    }
    return best_cost;
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
