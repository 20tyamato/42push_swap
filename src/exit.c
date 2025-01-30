#include "push_swap.h"

int	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

int	clean_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	return (EXIT_SUCCESS);
}
