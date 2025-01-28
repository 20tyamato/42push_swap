#include "push_swap.h"

void	print_stack_side_by_side(t_stack *stack1, t_stack *stack2)
{
	t_list	*current1;
	t_list	*current2;

	current1 = stack1->top;
	current2 = stack2->top;
	printf("=======================================\n");
	printf("Stack A            |            Stack B\n");
	printf("=======================================\n");
	printf("top                |                top\n");
	while (current1 || current2)
	{
		if (current1)
		{
			printf("%-18d", current1->value);
			current1 = current1->next;
		}
		else
			printf("%-18s", " ");
		printf(" | ");
		if (current2)
		{
			printf("%18d", current2->value);
			current2 = current2->next;
		}
		else
			printf("%18s", " ");
		printf("\n");
	}
	printf("bottom             |             bottom\n");
	printf("=======================================\n");
}
