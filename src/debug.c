#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	if (!current)
	{
		printf("empty\n");
		return ;
	}
	printf("======================\n");
	printf("top\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("bottom\n");
	printf("======================\n");
}

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

void	print_operation_count(t_operation_count *operation_count)
{
	printf("=======================================\n");
	printf("ra: %d\n", operation_count->ra);
	printf("rb: %d\n", operation_count->rb);
	printf("rr: %d\n", operation_count->rr);
	printf("rra: %d\n", operation_count->rra);
	printf("rrb: %d\n", operation_count->rrb);
	printf("rrr: %d\n", operation_count->rrr);
	printf("=======================================\n");
}
