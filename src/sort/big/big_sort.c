#include "push_swap.h"

void	forward_rotate_sort_a(t_stack *a, t_stack *b);
void	rev_rotate_sort_b(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);
int get_top_element_of_stack(t_stack *stack);
int get_bottom_element_of_stack(t_stack *stack);
int	get_max_num_in_stack(t_stack *stack);
int	get_min_num_in_stack(t_stack *stack);
int	merge_operations(t_operation_count *operation_count);
t_operation_count	*init_operation_count(void);
void	rev_sort_stack_of_two(t_stack *a, t_stack *b);
void	sort_stack_of_three(t_stack *a, t_stack *b);
int get_position_from_top(t_stack *a, int value);
void	print_operation_count(t_operation_count *operation_count);

void	exec_operations(t_stack *a, t_stack *b, int value);
int	merge_operations(t_operation_count *operation_count);
void	reset_operation_count(t_operation_count *operation_count);
void	repeat_operation(void (*op)(t_stack *, t_stack *),
								t_stack *a, t_stack *b, int count);

void	calc_minimum_steps_for_a(t_stack *a, t_stack *b, t_operation_count *operation_count, int value)
{
	(void)b;
	operation_count->ra = get_position_from_top(a, value);
	operation_count->rra = a->size - get_position_from_top(a, value);
}

int count_steps_using_rb(t_stack *a, t_stack *b, int value)
{
	(void)a;
	int count = 0;
	t_stack *tmp_b = copy_stack(b);

	if (value > get_max_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (value < get_min_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (get_bottom_element_of_stack(tmp_b) == get_min_num_in_stack(tmp_b) || get_top_element_of_stack(tmp_b) == get_max_num_in_stack(tmp_b))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
	}
	while (!(get_bottom_element_of_stack(tmp_b) < value && value < get_top_element_of_stack(tmp_b)) || (get_bottom_element_of_stack(tmp_b) > value && value > get_top_element_of_stack(tmp_b)))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return -1;
		}
	}
	free_stack(tmp_b);
	return (count);
}

int count_steps_using_rrb(t_stack *a, t_stack *b, int value)
{
	(void)a;
	int count = 0;
	t_stack *tmp_b = copy_stack(b);
	if (value > get_max_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (b->size - get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (value < get_min_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (b->size - get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (get_bottom_element_of_stack(tmp_b) == get_min_num_in_stack(tmp_b) || get_top_element_of_stack(tmp_b) == get_max_num_in_stack(tmp_b))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
	}
	while (!(get_bottom_element_of_stack(tmp_b) < value && value < get_top_element_of_stack(tmp_b)) || (get_bottom_element_of_stack(tmp_b) > value && value > get_top_element_of_stack(tmp_b)))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return -1;
		}
	}
	free_stack(tmp_b);
	return (count);
}

void	calc_minimum_steps_for_b(t_stack *a, t_stack *b, t_operation_count *operation_count, int value)
{
	operation_count->rb = count_steps_using_rb(a, b, value);
	operation_count->rrb = count_steps_using_rrb(a, b, value);
}

void	minimum_sorting(t_stack *a, t_stack *b)
{
	t_list				*current;
	t_operation_count	*operation_count;
	int					min_operations;
	int					min_operations_number;
	int operation_sum;

	current = a->top;
	operation_count = init_operation_count();
	min_operations = INT_MAX;
	min_operations_number = current->value;
	while (current)
	{
		reset_operation_count(operation_count);
		calc_minimum_steps_for_a(a, b, operation_count, current->value);
		calc_minimum_steps_for_b(a, b, operation_count, current->value);
		operation_sum = merge_operations(operation_count);
		if (min_operations > operation_sum)
		{
			min_operations = operation_sum;
			min_operations_number = current->value;
		}
		current = current->next;
	}
	exec_operations(a, b, min_operations_number);
	free(operation_count);
}

int count_steps_using_ra(t_stack *a, t_stack *b, int value)
{
	(void)b;
	int count = 0;
	t_stack *tmp_a = copy_stack(a);

	if (value > get_max_num_in_stack(a))
	{
		free_stack(tmp_a);
		return (a->size - get_position_from_top(a, get_max_num_in_stack(a)));
	}
	if (value < get_min_num_in_stack(a))
	{
		free_stack(tmp_a);
		return (a->size - get_position_from_top(a, get_max_num_in_stack(a)));
	}
	if (get_bottom_element_of_stack(tmp_a) == get_min_num_in_stack(tmp_a) || get_top_element_of_stack(tmp_a) == get_max_num_in_stack(tmp_a))
	{
		count++;
		fake_forward_rotate_a(a, tmp_a);
	}
	while (!(get_bottom_element_of_stack(tmp_a) < value && value < get_top_element_of_stack(tmp_a)) || (get_bottom_element_of_stack(tmp_a) > value && value > get_top_element_of_stack(tmp_a)))
	{
		count++;
		fake_forward_rotate_a(a, tmp_a);
		if (count > a->size)
		{
			free_stack(tmp_a);
			return -1;
		}
	}
	free_stack(tmp_a);
	return (count);
}

int count_steps_using_rra(t_stack *a, t_stack *b, int value)
{
	(void)b;
	int count = 0;
	t_stack *tmp_a = copy_stack(a);
	if (value > get_max_num_in_stack(a))
	{
		free_stack(tmp_a);
		return (get_position_from_top(a, get_max_num_in_stack(a)));
	}
	if (value < get_min_num_in_stack(a))
	{
		free_stack(tmp_a);
		return (get_position_from_top(a, get_max_num_in_stack(a)));
	}
	if (get_bottom_element_of_stack(tmp_a) == get_min_num_in_stack(tmp_a) || get_top_element_of_stack(tmp_a) == get_max_num_in_stack(tmp_a))
	{
		count++;
		fake_reverse_rotate_a(a, tmp_a);
	}
	while (!(get_bottom_element_of_stack(tmp_a) < value && value < get_top_element_of_stack(tmp_a)) || (get_bottom_element_of_stack(tmp_a) > value && value > get_top_element_of_stack(tmp_a)))
	{
		count++;
		fake_reverse_rotate_a(a, tmp_a);
		if (count > a->size)
		{
			free_stack(tmp_a);
			return -1;
		}
	}
	free_stack(tmp_a);
	return (count);
}

void	insert_b_to_a(t_stack *a, t_stack *b)
{
	int ra_count;
	int rra_count;
	t_list *current;

	current = b->top;
	while(current)
	{
		printf("BEFORE\n");
		printf("current->value: %d\n", current->value);
		print_stack_side_by_side(a, b);
		ra_count = count_steps_using_ra(a, b, current->value);
		rra_count = count_steps_using_rra(a, b, current->value);
		printf("ra_count: %d\n", ra_count);
		printf("rra_count: %d\n", rra_count);
		if (ra_count < rra_count)
			repeat_operation(forward_rotate_a, a, b, ra_count);
		else
			repeat_operation(reverse_rotate_a, a, b, rra_count);
		printf("AFTER\n");
		print_stack_side_by_side(a, b);
		push_a(a, b);
		if (b->size == 0)
			break ;
		current = current->next;
	}
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);

	while (a->size > 3)
		minimum_sorting(a, b);
	sort_stack_of_three(a, b);
	rev_rotate_sort_b(a, b);
	print_stack_side_by_side(a, b);
	// insert_b_to_a(a, b);
	print_stack_side_by_side(a, b);

	forward_rotate_sort_a(a, b);
}

void sort_big_stack_test(t_stack *a, t_stack *b)
{
	// ./push_swap 1 2 5 6 7 8 3 4 9
	// ./push_swap 1 3 4 9
	push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	print_stack_side_by_side(a, b);
	insert_b_to_a(a, b);
	print_stack_side_by_side(a, b);
}

// ./push_swap 5 2 7 1 6 3 9 4 8
// ./push_swap 7 8 9 1 2 3 4 5 6
// ./push_swap 1 2 5 6 7 8 3 4 9

// 1 2 3 4 5 6 7 8 9

// 要するに挿入ソート
// 6操作が入っている構造体を用意する
// その構造体に格納して、操作の圧縮や適用を行う
// Aはpush_bするために必要な回転を計算する
// Bはpush_bされるものを入れる場所まで何回必要か計算する
