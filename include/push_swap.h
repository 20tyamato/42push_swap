/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:41:32 by 20tyamato         #+#    #+#             */
/*   Updated: 2024/06/10 22:07:17 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_node {
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*top;
}	t_stack;

// array_utils.c
int		*to_array(char **s, int size);
int		*to_array_ext(char **s, int size);
int		is_array_sorted(int *array, int size);
int		is_array_duplicate(int *array, int size);

// forward_rotate.c
void	forward_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	forward_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	forward_rotate_ab(t_stack *stack_a, t_stack *stack_b);

// ft_atoi_long.c
long	ft_atoi_long(const char *str);

// input_handler_utils.c
void	check_str(char *str, int *action, int *error);
char	**duplicate_2d_array(char **argv);
int		ft_2d_array_len(char **s);
void	ft_free_2d_array(char **array);

// input_handler.c
void	valid_array(int *array, int size, int *error, int *action);
void	check_input_validity(char **argv, int argc, int *error);
void	valid_input(int argc, char **argv, int *action, int *error);

// main.c
char	**fix_input(int argc, char **argv, int *error);
char	**merge_argv_and_split(char **argv, char **split_argv);
int		process_input(char **fixed_argv, t_stack *stack_a, \
					t_stack *stack_b, int *error);
void	cleanup(char **fixed_argv, t_stack *stack_a, t_stack *stack_b);

// normalize.c
int		*duplicate_array(int *array, int size);
int		*normalize_array(char **argv, int argc);
void	map_indexes(int *array, int *sorted_array, int size);

// push_operations.c
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

// push_swap.c
void	push_swap_forward(t_stack *stack_a, t_stack *stack_b, int place);
void	push_swap_back(t_stack *stack_a, t_stack *stack_b, int place);
void	return_stack_a(t_stack *stack_a, t_stack *stack_b);
void	fill_stack_a(t_stack *stack_a, int size, int *array);
void	push_swap(t_stack *stack_a, t_stack *stack_b);

// quick_sort.c
void	ft_swap(int *a, int *b);
int		partition(int arr[], int low, int high);
void	ft_quick_sort(int arr[], int low, int high);

// reverse_rotate.c
void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

// sorter.c
void	sort_three(t_stack *stack_a, t_stack *stack_b, int argc);
int		get_min(t_stack *stack);
int		get_min_index(t_stack *stack);
void	sort_six(t_stack *stack_a, t_stack *stack_b);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b, int argc);

// stack_operations.c
void	push(t_stack *stack, int data);
int		pop(t_stack *stack);
int		is_stack_sorted(t_stack *s);
int		is_stack_sorted_rev(t_stack *s);
void	free_stack_ab(t_stack *stack_a, t_stack *stack_b);

// stack_utils.c
t_stack	*create_stack(void);
void	clear_stack(t_stack **s);
int		is_stack_empty(t_stack *s);
size_t	stack_size(t_stack *s);
t_node	*create_node(int data);

// swap_operations.c
void	swap_a(t_stack *stack_a, t_stack *stack_b);
void	swap_b(t_stack *stack_a, t_stack *stack_b);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);

// utils.c
int		is_bigger_than_int(char *s);
int		ft_isdigit_ext(int c);
int		is_all_digit(char *s);

#endif