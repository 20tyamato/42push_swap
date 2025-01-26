#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || argc > INT_MAX)
		return (EXIT_FAILURE);
	a = create_stack();
	b = create_stack();
	printf("a: %p\n", a);
	printf("b: %p\n", b);
	if (!parse_args(argc, argv, a, b))
		return (error_exit(a, b));
	print_stack(a);
	if (is_sorted(a, b))
		return (clean_exit(a, b));
	printf("3a: %p\n", a);
	printf("3b: %p\n", b);
	push_swap(a, b);
	return (clean_exit(a, b));
}
