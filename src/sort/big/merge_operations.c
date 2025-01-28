#include "push_swap.h"

static void	update_best_cost_and_scenario(int *best_cost, char *best_scenario,
			int current_cost, char current_scenario)
{
	if (current_cost < *best_cost)
	{
		*best_cost = current_cost;
		*best_scenario = current_scenario;
	}
}

static int	find_best_scenario(t_operation_count *current_operation_count, char *best_scenario)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	best_cost;

	cost_rr = ft_max(current_operation_count->ra, current_operation_count->rb);
	cost_rrr = ft_max(current_operation_count->rra, current_operation_count->rrb);
	cost_ra_rrb = current_operation_count->ra + current_operation_count->rrb;
	cost_rra_rb = current_operation_count->rra + current_operation_count->rb;
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
						t_operation_count *current_operation_count)
{
	if (best_scenario == 'A')
	{
		operation_count->rr = ft_min(current_operation_count->ra, current_operation_count->rb);
		operation_count->ra = current_operation_count->ra - operation_count->rr;
		operation_count->rb = current_operation_count->rb - operation_count->rr;
	}
	else if (best_scenario == 'B')
	{
		operation_count->rrr = ft_min(current_operation_count->rra, current_operation_count->rrb);
		operation_count->rra = current_operation_count->rra - operation_count->rrr;
		operation_count->rrb = current_operation_count->rrb - operation_count->rrr;
	}
	else if (best_scenario == 'C')
	{
		operation_count->ra = current_operation_count->ra;
		operation_count->rrb = current_operation_count->rrb;
	}
	else
	{
		operation_count->rra = current_operation_count->rra;
		operation_count->rb = current_operation_count->rb;
	}
}

int	merge_operations(t_operation_count *operation_count)
{
	t_operation_count	*current_operation_count;
	char				best_scenario;
	int					best_cost;

	current_operation_count = init_operation_count();
	current_operation_count->ra = operation_count->ra;
	current_operation_count->rb = operation_count->rb;
	current_operation_count->rra = operation_count->rra;
	current_operation_count->rrb = operation_count->rrb;
	best_cost = find_best_scenario(current_operation_count, &best_scenario);
	reset_operation_counts(operation_count);
	apply_scenario(operation_count, best_scenario, current_operation_count);
	return (best_cost);
}
