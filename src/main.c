#include "push_swap.h"

bool	parse_args(int argc, char **argv, t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

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
