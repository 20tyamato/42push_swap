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

void	calc_minimum_steps_for_a(t_stack *a, t_stack *b, t_operation_count *operation_count, int value)
{
	(void)b;
	// どっちも計算する
	// if (get_position_from_top(a, value) <= a->size / 2)
	operation_count->ra = get_position_from_top(a, value);
	// else
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
		// さらなる改善案、合計が最小のものに変更する
		calc_minimum_steps_for_a(a, b, operation_count, current->value);
		// bがおかしい
		calc_minimum_steps_for_b(a, b, operation_count, current->value);
		printf("BEFORE\n");
		printf("current->value: %d\n", current->value);
		print_operation_count(operation_count);
		operation_sum = merge_operations(operation_count);
		if (min_operations > operation_sum)
		{
			min_operations = operation_sum;
			min_operations_number = current->value;
		}
		printf("AFTER\n");
		print_operation_count(operation_count);
		current = current->next;
	}
	// (void)min_operations_number;
	exec_operations(a, b, min_operations_number);
	free(operation_count);
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	print_stack_side_by_side(a, b);

	while (a->size > 3)
	{
		minimum_sorting(a, b);
		print_stack_side_by_side(a, b);
	}
	sort_stack_of_three(a, b);
	print_stack_side_by_side(a, b);
	rev_rotate_sort_b(a, b);
	print_stack_side_by_side(a, b);
	// aを回転しながら、bを入れまくる
	// insert_b_to_a(a, b);

	forward_rotate_sort_a(a, b);
}

void sort_big_stack_test(t_stack *a, t_stack *b)
{
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	print_stack_side_by_side(a, b);
	forward_rotate_sort_a(a, b);
	print_stack_side_by_side(a, b);
}

// ./push_swap 5 2 7 1 6 3 9 4 8
// ./push_swap 7 8 9 1 2 3 4 5 6

// 1 2 3 4 5 6 7 8 9

// 要するに挿入ソート
// 6操作が入っている構造体を用意する
// その構造体に格納して、操作の圧縮や適用を行う
// Aはpush_bするために必要な回転を計算する
// Bはpush_bされるものを入れる場所まで何回必要か計算する
