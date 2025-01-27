#include "push_swap.h"

// ARG="5 2147483647 2147483646"; ./push_swap $ARG | ./checker $ARG

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || argc > INT_MAX)
		return (EXIT_FAILURE);
	a = create_stack();
	b = create_stack();
	if (!parse_args(argc, argv, a, b))
		return (error_exit(a, b));
	if (is_sorted(a))
		return (clean_exit(a, b));
	// print_stack_side_by_side(a, b);
	push_swap(a, b);
	// print_stack_side_by_side(a, b);
	return (clean_exit(a, b));
}
