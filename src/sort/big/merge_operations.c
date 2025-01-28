#include "push_swap.h"

void	reset_operation_counts(t_operation_count *operation_count);

void	update_best_cost_and_scenario(int *best_cost, char *best_scenario,
			int current_cost, char current_scenario)
{
	if (current_cost < *best_cost)
	{
		*best_cost = current_cost;
		*best_scenario = current_scenario;
	}
}

static int	find_best_scenario(int ra, int rb,
				int rra, int rrb, char *best_scenario)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	best_cost;

	cost_rr = ft_max(ra, rb);
	cost_rrr = ft_max(rra, rrb);
	cost_ra_rrb = ra + rrb;
	cost_rra_rb = rra + rb;
	best_cost = INT_MAX;
	*best_scenario = '\0';
	update_best_cost_and_scenario(&best_cost, best_scenario, cost_rr, 'A');
	update_best_cost_and_scenario(&best_cost, best_scenario, cost_rrr, 'B');
	update_best_cost_and_scenario(&best_cost, best_scenario, cost_ra_rrb, 'C');
	update_best_cost_and_scenario(&best_cost, best_scenario, cost_rra_rb, 'D');
	return (best_cost);
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
		operation_count->ra = ra;
		operation_count->rrb = rrb;
	}
	else
	{
		operation_count->rra = rra;
		operation_count->rb = rb;
	}
}

int	merge_operations(t_operation_count *operation_count)
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	char	best_scenario;
	int		best_cost;

	ra = operation_count->ra;
	rb = operation_count->rb;
	rra = operation_count->rra;
	rrb = operation_count->rrb;
	best_cost = find_best_scenario(ra, rb, rra, rrb, &best_scenario);
	reset_operation_counts(operation_count);
	apply_scenario(operation_count, best_scenario, ra, rb, rra, rrb);
	return (best_cost);
}
