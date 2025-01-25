#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = create_stack();
	b = create_stack();
	if (!parse_args(argc, argv, a, b))
		return (error_exit(a, b));
	if (is_sorted(a, b))
		return (clean_exit(a, b));
	push_swap(a, b);
	return (clean_exit(a, b));
}
