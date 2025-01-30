#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

static bool	execute_instruction(const char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "sa") == 0)
		swap_a(a);
	else if (ft_strcmp(cmd, "sb") == 0)
		swap_b(b);
	else if (ft_strcmp(cmd, "ss") == 0)
		swap_ab(a, b);
	else if (ft_strcmp(cmd, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(cmd, "pb") == 0)
		push_b(a, b);
	else if (ft_strcmp(cmd, "ra") == 0)
		forward_rotate_a(a);
	else if (ft_strcmp(cmd, "rb") == 0)
		forward_rotate_b(b);
	else if (ft_strcmp(cmd, "rr") == 0)
		forward_rotate_ab(a, b);
	else if (ft_strcmp(cmd, "rra") == 0)
		reverse_rotate_a(a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		reverse_rotate_b(b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		reverse_rotate_ab(a, b);
	else
		return (false);
	return (true);
}

void	check_push_swap(t_stack *a, t_stack *b)
{
	char	*line;

	while ((line = get_next_line(STDIN_FILENO)) != NULL)
	{
		ft_strtrim_newline_inplace(line);
		if (!execute_instruction(line, a, b))
		{
			free(line);
			error_exit(a, b);
		}
		free(line);
	}
	if (is_sorted(a) && is_empty(b))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}
