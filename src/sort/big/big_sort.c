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

void	exec_operations(t_stack *a, t_stack *b, int value);
int	merge_operations(t_operation_count *operation_count);

int get_closest_position_from_top(t_stack *stack, int value)
{
	// 入るvalueがstackで一番大きい数より大きい場合は、その上に置けばいい
	if (value > get_max_num_in_stack(stack))
	{
		if (get_position_from_top(stack, get_max_num_in_stack(stack)) < stack->size / 2)
			return (get_position_from_top(stack, get_max_num_in_stack(stack)));
		else
			return (stack->size - get_position_from_top(stack, get_max_num_in_stack(stack)));
	}
	// 入るvalueがstackで一番小さい数の場合は、一番大きい数の上に置けばいい
	if (value == get_bottom_element_of_stack(stack))
		return (0);
	// スタックの一番下の数と、一番上の数の間にvalueが入ればOK
	if (value > get_bottom_element_of_stack(stack) && value < get_top_element_of_stack(stack))
		return (0);
	// それ以外の場合は、一番近い数の上に置く
	if (get_position_from_top(stack, value) < stack->size / 2)
		return (get_position_from_top(stack, value));
	else
		return (stack->size - get_position_from_top(stack, value));
}

void	calc_minimum_steps_for_a(t_stack *a, t_operation_count *operation_count, int value)
{
	if (get_position_from_top(a, value) < a->size / 2)
		operation_count->ra = get_position_from_top(a, value);
	else
		operation_count->rra = a->size - get_position_from_top(a, value);
}

void	calc_minimum_steps_for_b(t_stack *b, t_operation_count *operation_count, int value)
{
	// calc B
	// raの場合は、rbの数を数える必要がある
	if (operation_count->ra > 0)
		operation_count->rb = get_closest_position_from_top(b, value);
	// rraの場合は、rrbの数を数える必要がある
	else if (operation_count->rra > 0)
		operation_count->rrb = b->size - get_closest_position_from_top(b, value);
}

void	minimum_sorting(t_stack *a, t_stack *b)
{
	t_list				*current;
	t_operation_count	*operation_count;
	int					min_operations;
	int					min_operations_number;

	current = a->top;
	operation_count = init_operation_count();
	min_operations = INT_MAX;
	min_operations_number = current->value;
	while (current)
	{
		// さらなる改善案、合計が最小のものに変更する
		calc_minimum_steps_for_a(a, operation_count, current->value);
		calc_minimum_steps_for_b(b, operation_count, current->value);
		if (min_operations > merge_operations(operation_count))
		{
			min_operations = merge_operations(operation_count);
			min_operations_number = current->value;
		}
		current = current->next;
	}
	exec_operations(a, b, min_operations_number);
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
