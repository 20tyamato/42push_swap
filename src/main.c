#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = create_stack();
	b = create_stack();
	if (!parse_args(argc, argv, a))      // 引数を分割・数値変換・エラーチェック
		return (error_exit(a, b));
	if (is_sorted(a))                    // 既にソート済みかチェック
		return (clean_exit(a, b));
	push_swap(a, b);                     // ソート用のアルゴリズム実行
	return (clean_exit(a, b));          // 後始末して終了
}
