#include "push_swap.h"

void	sort_a(t_stack *a, t_stack *b);
void	rev_sort_b(t_stack *a, t_stack *b);

void	sort_small_stack(t_stack *a, t_stack *b);

typedef struct s_operation_count
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
} t_operation_count;

int	merge_operations(t_operation_count *operation_count)
{
	int sum;

	sum = 0;
    while (operation_count->ra > 0 && operation_count->rb > 0)
    {
        operation_count->rr++;
        operation_count->ra--;
        operation_count->rb--;
    }
    while (operation_count->rra > 0 && operation_count->rrb > 0)
    {
        operation_count->rrr++;
        operation_count->rra--;
        operation_count->rrb--;
    }
	sum = operation_count->ra + operation_count->rb + operation_count->rr + operation_count->rra + operation_count->rrb + operation_count->rrr;
	return (sum);
}

t_operation_count *init_operation_count(void)
{
	t_operation_count *operation_count;

	operation_count = (t_operation_count *)malloc(sizeof(t_operation_count));
	if (!operation_count)
		return (NULL);
	operation_count->ra = 0;
	operation_count->rb = 0;
	operation_count->rr = 0;
	operation_count->rra = 0;
	operation_count->rrb = 0;
	operation_count->rrr = 0;
	return (operation_count);
}


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

// TODO: 符号が変わるタイミング
int get_closest_position_from_top(t_stack *stack, int value)
{
	t_list *current;
	int i;
	int stack_size;

	current = stack->top;
	i = 0;
	stack_size = stack->size;
	while (current)
	{
		if (current->value < value)
			break ;
	}
}

void	calc_min_operations(t_stack *a, t_stack *b)
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
		// calc A
		if (get_position_from_top(a, current->value) < a->size / 2)
			operation_count->ra = get_position_from_top(a, current->value);
		else
			operation_count->rra = a->size - get_position_from_top(a, current->value);
		// calc B
		// raの場合は、rbの数を数える必要がある
		if (operation_count->ra > 0)
			operation_count->rb = get_closest_position_from_top(b, current->value);
		// rraの場合は、rrbの数を数える必要がある
		else if (operation_count->rra > 0)
			operation_count->rrb = b->size - get_closest_position_from_top(b, current->value);
		// さらなる改善案、合計が最小のものに変更する
		// merge results
		if (min_operations > merge_operations(operation_count))
		{
			min_operations = merge_operations(operation_count);
			min_operations_number = current->value;
		}
		current = current->next;
	}
	// 実際に適用する
	// a関連を先に行い、ra,rr,rrr,rraがなくなり次第、pbして、rb, rrbを行う
	exec_min_operations(a, b, min_operations, min_operations_number);
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);

	while (a->size > 3)
		calc_min_operations(a, b);
	if (a->size == 3)
		sort_small_stack(a, b);
	rev_sort_b(a, b);
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
