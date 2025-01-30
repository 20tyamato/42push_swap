#include "push_swap.h"

static void	ft_strtrim_newline_inplace(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len == 0)
		return ;
	while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
	{
		s[len - 1] = '\0';
		len--;
	}
}

static bool	execute_instruction(const char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "sa") == 0)
		fake_swap_a(a, b);
	else if (ft_strcmp(cmd, "sb") == 0)
		fake_swap_b(a, b);
	else if (ft_strcmp(cmd, "ss") == 0)
		fake_swap_ab(a, b);
	else if (ft_strcmp(cmd, "pa") == 0)
		fake_push_a(a, b);
	else if (ft_strcmp(cmd, "pb") == 0)
		fake_push_b(a, b);
	else if (ft_strcmp(cmd, "ra") == 0)
		fake_forward_rotate_a(a, b);
	else if (ft_strcmp(cmd, "rb") == 0)
		fake_forward_rotate_b(a, b);
	else if (ft_strcmp(cmd, "rr") == 0)
		fake_forward_rotate_ab(a, b);
	else if (ft_strcmp(cmd, "rra") == 0)
		fake_reverse_rotate_a(a, b);
	else if (ft_strcmp(cmd, "rrb") == 0)
		fake_reverse_rotate_b(a, b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		fake_reverse_rotate_ab(a, b);
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
