#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

/* 単方向リストのノード */
typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

/* スタック構造体 */
typedef struct s_stack
{
	t_list	*top;  /* 先頭(トップ)のノードを指す */
	int		size;  /* 要素数を管理する */
}	t_stack;

#endif
