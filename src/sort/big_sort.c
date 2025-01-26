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

// 何手になるのかを計算する必要がある
// a：ある数を一番上に持っていくには、何回回転すればいいかを計算する
// b：ある数が入ったら、何回回転したら、ソートされるかを計算する

int get_position(t_stack *stack, int value)
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

void	merge_operations(t_operation_count *operation_count);

void	calc_min_operations(t_stack *a, t_stack *b)
{
	t_list	*current;
	t_operation_count	*operation_count;
	int min_operations;
	int min_operations_number;

	current = a->top;
	operation_count = (t_operation_count *)malloc(sizeof(t_operation_count));
	if (!operation_count)
		return ;
	// initが必要
	min_operations = INT_MAX;
	min_operations_number = current->value;
	while (current)
	{
		if (get_position(a, current->value) < a->size / 2)
			operation_count->ra = get_position(a, current->value);
		else
			operation_count->rra = get_position(a, current->value);
		if (get_position(b, current->value) < b->size / 2)
			operation_count->rb = get_position(b, current->value);
		else
			operation_count->rrb = get_position(b, current->value);
		// merge results
		merge_operations(operation_count);
		// minの場合は、min_operations_numberを更新する
		current = current->next;
	}
	// min_operations_numberを再度計算して、適用する
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	printf("\na\n");
	print_stack(a);
	printf("b\n");
	print_stack(b);

	// aが3つになるまで、手順を計算した上でpbする
	// aの要素一個一個に対して計算する
	calc_min_operations(a, b);

	// aが3つになったら、sort_small_stack(a, b)を実行する
	if (a->size == 3)
		sort_small_stack(a, b);
	rev_sort_b(a, b);
	// aがソートされており、bも逆順にソートされている
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
