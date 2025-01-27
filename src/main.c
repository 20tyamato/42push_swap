#include "push_swap.h"

// ARG="5 2147483647 2147483646"; ./push_swap $ARG | ./checker $ARG
// python3 push_swap_tester.py -r 1 100 -l 9 -c 9

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
	push_swap(a, b);
	return (clean_exit(a, b));
}
