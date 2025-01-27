#include "push_swap.h"

int get_top_element_of_stack(t_stack *stack);
int get_bottom_element_of_stack(t_stack *stack);
int	get_max_num_in_stack(t_stack *stack);
int	get_min_num_in_stack(t_stack *stack);

int get_second_max_num_in_stack(t_stack *stack)
{
	t_list *current;
	int max;
	int second_max;

	current = stack->top;
	max = INT_MIN;
	second_max = INT_MIN;
	while (current)
	{
		if (current->value > max)
		{
			second_max = max;
			max = current->value;
		}
		else if (current->value > second_max)
			second_max = current->value;
		current = current->next;
	}
	return (second_max);
}

int get_second_min_num_in_stack(t_stack *stack)
{
	t_list *current;
	int min;
	int second_min;

	current = stack->top;
	min = INT_MAX;
	second_min = INT_MAX;
	while (current)
	{
		if (current->value < min)
		{
			second_min = min;
			min = current->value;
		}
		else if (current->value < second_min)
			second_min = current->value;
		current = current->next;
	}
	return (second_min);
}

void	rev_sort_stack_of_two(t_stack *a, t_stack *b);

void	sort_stack_of_two(t_stack *a, t_stack *b)
{
	if (a->top->value > a->top->next->value)
		swap_a(a, b);
}

void	sort_stack_of_three(t_stack *a, t_stack *b)
{
	if (a->top->next->value < a->top->value && \
				a->top->value < a->top->next->next->value)
		swap_a(a, b);
	else if (a->top->next->next->value < a->top->next->value && \
				a->top->next->value < a->top->value)
	{
		swap_a(a, b);
		reverse_rotate_a(a, b);
	}
	else if (a->top->next->value < a->top->next->next->value && \
				a->top->next->next->value < a->top->value)
		forward_rotate_a(a, b);
	else if (a->top->value < a->top->next->next->value && \
				a->top->next->next->value < a->top->next->value)
	{
		swap_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (a->top->next->next->value < a->top->value && \
				a->top->value < a->top->next->value)
		reverse_rotate_a(a, b);
}

int	get_middle_num_in_stack(t_stack *stack)
{
	int size;
	t_list *current;
	int i;

	size = stack->size;
	current = stack->top;
	if (size % 2 == 0)
		i = 0;
	else
		i = 1;
	while(i != size / 2)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

void	push_first_element_to_a(t_stack *a, t_stack *b)
{
	int max;
	int mid;
	int min;
	int in_number;

	max = get_max_num_in_stack(a);
	mid = get_second_max_num_in_stack(a);
	min = get_min_num_in_stack(a);
	in_number = get_top_element_of_stack(b);
	if (max < in_number)
	{
		push_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (min > in_number)
		push_a(a, b);
	else if (mid < in_number)
	{
		reverse_rotate_a(a, b);
		push_a(a, b);
		forward_rotate_a(a, b);
		forward_rotate_a(a, b);
	}
	else
	{
		forward_rotate_a(a, b);
		push_a(a, b);
		reverse_rotate_a(a, b);
	}
	return ;
}

void	push_second_element_to_a(t_stack *a, t_stack *b)
{
	int max;
	int second_max;
	int second_min;
	int min;
	int in_number;

	max = get_max_num_in_stack(a);
	second_max = get_second_max_num_in_stack(a);
	second_min = get_second_min_num_in_stack(a);
	min = get_min_num_in_stack(a);
	in_number = get_top_element_of_stack(b);
	if (max < in_number)
	{
		push_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (min > in_number)
		push_a(a, b);
	else if (second_max < in_number)
	{
		reverse_rotate_a(a, b);
		push_a(a, b);
		forward_rotate_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (second_min > in_number)
	{
		forward_rotate_a(a, b);
		push_a(a, b);
		reverse_rotate_a(a, b);
	}
	else
	{
		forward_rotate_a(a, b);
		forward_rotate_a(a, b);
		push_a(a, b);
		reverse_rotate_a(a, b);
		reverse_rotate_a(a, b);
	}
	return ;
}

// 4 3 5 2 1

// 5 4
// 2 3
// 1

// 1 4
// 2 3
// 5

// 

// pb pb | sa rra | rra pa ra ra | rra rra pa ra ra

void	sort_stack_of_under_five(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	sort_stack_of_three(a, b);
	// rev_sort_stack_of_two(a, b);
	// print_stack_side_by_side(a, b);
	push_first_element_to_a(a, b);
	// print_stack_side_by_side(a, b);
	push_second_element_to_a(a, b);
	// print_stack_side_by_side(a, b);
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort_stack_of_two(a, b);
	else if (size == 3)
		sort_stack_of_three(a, b);
	else
		sort_stack_of_under_five(a, b);
}
