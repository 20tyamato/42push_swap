#include "push_swap.h"

void	sort_a(t_stack *a, t_stack *b);
void	rev_sort_b(t_stack *a, t_stack *b);

void	sort_small_stack(t_stack *a, t_stack *b);
void	rev_sort_small_stack(t_stack *a, t_stack *b);

int get_top_element_of_stack(t_stack *stack);
int get_bottom_element_of_stack(t_stack *stack);
int	get_max_num_in_stack(t_stack *stack);
int	get_min_num_in_stack(t_stack *stack);

int	merge_operations(t_operation_count *operation_count);
t_operation_count	*init_operation_count(void);

int get_position_from_top(t_stack *stack, int value)
{
	t_list *current;
	int i;

	current = stack->top;
	i = 0;
	while (current)
	{
		if (current->value == value)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

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

static void	repeat_operation(void (*op)(t_stack *, t_stack *),
								t_stack *a, t_stack *b, int count)
{
	while (count-- > 0)
		op(a, b);
}

void	exec_minimum_operations(t_stack *a, t_stack *b, int value)
{
	t_operation_count	*op_count;

	op_count = init_operation_count();
	calc_minimum_steps_for_a(a, op_count, value);
	calc_minimum_steps_for_b(b, op_count, value);
	merge_operations(op_count);
	repeat_operation(forward_rotate_a, a, b, op_count->ra);
	repeat_operation(forward_rotate_ab, a, b, op_count->rr);
	repeat_operation(reverse_rotate_a, a, b, op_count->rra);
	repeat_operation(reverse_rotate_ab, a, b, op_count->rrr);
	repeat_operation(forward_rotate_b, a, b, op_count->rb);
	repeat_operation(reverse_rotate_b, a, b, op_count->rrb);
	push_b(a, b);
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
	exec_minimum_operations(a, b, min_operations_number);
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	print_stack_side_by_side(a, b);
	rev_sort_small_stack(a, b);
	print_stack_side_by_side(a, b);

	while (a->size > 3)
	{
		minimum_sorting(a, b);
		print_stack_side_by_side(a, b);
	}
	if (a->size == 3)
		sort_small_stack(a, b);
	print_stack_side_by_side(a, b);
	rev_sort_b(a, b);
	print_stack_side_by_side(a, b);
	// aを回転しながら、bを入れまくる
	// insert_b_to_a(a, b);

	// aを回転させて、aの最小値が一番上になるまで回転する（どっちに回せば最小になるか）
	sort_a(a, b);
}

// ./push_swap 5 2 7 1 6 3 9 4 8
// ./push_swap 7 8 9 1 2 3 4 5 6

// 要するに挿入ソート
// 6操作が入っている構造体を用意する
// その構造体に格納して、操作の圧縮や適用を行う
// Aはpush_bするために必要な回転を計算する
// Bはpush_bされるものを入れる場所まで何回必要か計算する

// printf("\na\n");
// print_stack(a);
// printf("b\n");
// print_stack(b);
