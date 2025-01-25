#include "push_swap.h"

char	**fix_input(int argc, char **argv, int *error)
{
	int	action;

	action = 0;
	if (argc == 1)
		exit(0);
	else if (argc != 2)
		return (duplicate_2d_array(argv + 1));
	else
	{
		check_str(argv[1], &action, error);
		if (*error == 1)
			return (NULL);
		return (merge_argv_and_split(argv, ft_split(argv[1], ' ')));
	}
}

char	**merge_argv_and_split(char **argv, char **split_argv)
{
	int		i;
	char	**fixed_argv;
	int		len;

	len = ft_2d_array_len(split_argv) + 1;
	fixed_argv = (char **)malloc(sizeof(char *) * (len + 1));
	if (!fixed_argv)
	{
		ft_free_2d_array(split_argv);
		return (NULL);
	}
	fixed_argv[0] = ft_strdup(argv[0]);
	i = 0;
	while (split_argv[i])
	{
		fixed_argv[i + 1] = ft_strdup(split_argv[i]);
		i++;
	}
	fixed_argv[i + 1] = NULL;
	ft_free_2d_array(split_argv);
	return (fixed_argv);
}

int	process_input(char **fixed_argv, t_stack *stack_a, \
					t_stack *stack_b, int *error)
{
	int		*normalized_array;
	int		action;
	int		argc;

	action = 1;
	argc = ft_2d_array_len(fixed_argv);
	valid_input(argc, fixed_argv, &action, error);
	if (action == 1 && *error == 0)
	{
		if (ft_2d_array_len(fixed_argv) == 2)
			exit(0);
		if (ft_strncmp(fixed_argv[0], "./push_swap", \
						ft_strlen("./push_swap")) == 0)
		{
			argc--;
			fixed_argv++;
		}
		normalized_array = normalize_array(fixed_argv, argc);
		fill_stack_a(stack_a, argc, normalized_array);
		sort_stacks(stack_a, stack_b, argc);
		free(normalized_array);
		return (1);
	}
	return (0);
}

void	cleanup(char **fixed_argv, t_stack *stack_a, t_stack *stack_b)
{
	ft_free_2d_array(fixed_argv);
	free_stack_ab(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error;
	char	**fixed_argv;

	if (argc == 1)
		return (0);
	stack_a = create_stack();
	stack_b = create_stack();
	error = 0;
	fixed_argv = fix_input(argc, argv, &error);
	if (argc == 2 && ft_strncmp(argv[1], "", 1) == 0)
	{
		cleanup(fixed_argv, stack_a, stack_b);
		return (0);
	}
	if (!fixed_argv || process_input(fixed_argv, stack_a, stack_b, &error) == 0)
		ft_putstr_fd("Error\n", 2);
	cleanup(fixed_argv, stack_a, stack_b);
	return (0);
}
