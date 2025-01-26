#include "push_swap.h"

int	merge_operations(t_operation_count *operation_count)
{
	int sum;

	sum = 0;
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
	sum = operation_count->ra + operation_count->rb
		+ operation_count->rr + operation_count->rra
		+ operation_count->rrb + operation_count->rrr;
	return (sum);
}

t_operation_count	*init_operation_count(void)
{
	t_operation_count *operation_count;

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
