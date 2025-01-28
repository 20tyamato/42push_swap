#include "push_swap.h"

void	print_aligned_int(int n, int width, int is_left);
void	print_aligned_str(const char *str, int width, int is_left);

static void	print_stack_side_by_side_header(void)
{
	ft_putstr_fd("=======================================\n", STDOUT_FILENO);
	ft_putstr_fd("Stack A            |            Stack B\n", STDOUT_FILENO);
	ft_putstr_fd("=======================================\n", STDOUT_FILENO);
	ft_putstr_fd("top                |                top\n", STDOUT_FILENO);
}

static void	print_stack_side_by_side_footer(void)
{
	ft_putstr_fd("bottom             |             bottom\n", STDOUT_FILENO);
	ft_putstr_fd("=======================================\n", STDOUT_FILENO);
}

void	print_stack_side_by_side(t_stack *stack1, t_stack *stack2)
{
	t_list	*current1;
	t_list	*current2;

	current1 = stack1->top;
	current2 = stack2->top;
	print_stack_side_by_side_header();
	while (current1 || current2)
	{
		if (current1)
		{
			print_aligned_int(current1->value, 18, 1);
			current1 = current1->next;
		}
		else
			print_aligned_str("", 18, 1);
		ft_putstr_fd(" | ", STDOUT_FILENO);
		if (current2)
		{
			print_aligned_int(current2->value, 18, 0);
			current2 = current2->next;
		}
		else
			print_aligned_str("", 18, 0);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	print_stack_side_by_side_footer();
}
