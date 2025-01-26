#include "push_swap.h"

void	sort_a(t_stack *a, t_stack *b);
void	rev_sort_b(t_stack *a, t_stack *b);

// 何手になるのかを計算する必要がある
// a：ある数を一番上に持っていくには、何回回転すればいいかを計算する
// b：ある数が入ったら、何回回転したら、ソートされるかを計算する

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	printf("\na\n");
	print_stack(a);
	printf("b\n");
	print_stack(b);

	// aが3つになるまで、手順を計算した上でpbする

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
