#include "push_swap.h"

void	reset_operation_counts(t_operation_count *operation_count);

static int find_best_scenario(int ra, int rb, int rra, int rrb, char *best_scenario)
{
	int cost_rr      = ft_max(ra, rb);
	int cost_rrr     = ft_max(rra, rrb);
	int cost_ra_rrb  = ra + rrb;
	int cost_rra_rb  = rra + rb;

	int best_cost = cost_rr;
	*best_scenario = 'A';
	if (cost_rrr < best_cost)
	{
		best_cost = cost_rrr;
		*best_scenario = 'B';
	}
	if (cost_ra_rrb < best_cost)
	{
		best_cost = cost_ra_rrb;
		*best_scenario = 'C';
	}
	if (cost_rra_rb < best_cost)
	{
		best_cost = cost_rra_rb;
		*best_scenario = 'D';
	}
	return best_cost;
}

static void	apply_scenario(t_operation_count *operation_count,
                           char best_scenario,
                           int ra, int rb,
                           int rra, int rrb)
{
	if (best_scenario == 'A')
	{
		operation_count->rr = ft_min(ra, rb);
		operation_count->ra = ra - operation_count->rr;
		operation_count->rb = rb - operation_count->rr;
	}
	else if (best_scenario == 'B')
	{
		operation_count->rrr = ft_min(rra, rrb);
		operation_count->rra = rra - operation_count->rrr;
		operation_count->rrb = rrb - operation_count->rrr;
	}
	else if (best_scenario == 'C')
	{
		operation_count->ra  = ra;
		operation_count->rrb = rrb;
	}
	else
	{
		operation_count->rra = rra;
		operation_count->rb  = rb;
	}
}

int	merge_operations(t_operation_count *operation_count)
{
	int  ra   = operation_count->ra;
	int  rb   = operation_count->rb;
	int  rra  = operation_count->rra;
	int  rrb  = operation_count->rrb;

	char best_scenario;
	int  best_cost = find_best_scenario(ra, rb, rra, rrb, &best_scenario);
	reset_operation_counts(operation_count);
	apply_scenario(operation_count, best_scenario, ra, rb, rra, rrb);
	return best_cost;
}
