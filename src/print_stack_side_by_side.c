#include "push_swap.h"

static void	put_spaces(int count)
{
	while (count-- > 0)
		write(1, " ", 1);
}

static void	print_aligned_int(int n, int width, int is_left)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	if (!s)
		return ;
	len = (int)ft_strlen(s);
	if (is_left)
	{
		write(1, s, len);
		if (len < width)
			put_spaces(width - len);
	}
	else
	{
		if (len < width)
			put_spaces(width - len);
		write(1, s, len);
	}
	free(s);
}

static void	print_aligned_str(const char *str, int width, int is_left)
{
	int	len = (int)ft_strlen(str);

	if (is_left)
	{
		write(1, str, len);
		if (len < width)
			put_spaces(width - len);
	}
	else
	{
		if (len < width)
			put_spaces(width - len);
		write(1, str, len);
	}
}

void	print_stack_side_by_side(t_stack *stack1, t_stack *stack2)
{
	t_list	*current1;
	t_list	*current2;

	current1 = stack1->top;
	current2 = stack2->top;
	ft_putstr("=======================================\n");
	ft_putstr("Stack A            |            Stack B\n");
	ft_putstr("=======================================\n");
	ft_putstr("top                |                top\n");
	while (current1 || current2)
	{
		if (current1)
		{
			print_aligned_int(current1->value, 18, 1);
			current1 = current1->next;
		}
		else
			print_aligned_str("", 18, 1);
		ft_putstr(" | ");
		if (current2)
		{
			print_aligned_int(current2->value, 18, 0);
			current2 = current2->next;
		}
		else
			print_aligned_str("", 18, 0);
		ft_putstr("\n");
	}
	ft_putstr("bottom             |             bottom\n");
	ft_putstr("=======================================\n");
}
