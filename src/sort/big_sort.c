#include "push_swap.h"

// 何手になるのかを計算する必要がある

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	printf("\na\n");
	print_stack(a);
	printf("b\n");
	print_stack(b);

	// aが3つになるまで、手順を計算した上でpbする

	// aがソートされており、bも逆順にソートされている
	// aを回転しながら、bを入れまくる
	// aを回転させて、aの最小値が一番上になるまで回転する（どっちに回せば最小になるか）
}

// ./push_swap 5 2 7 1 6 3 9 4 8
