/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:37:09 by 20tyamato         #+#    #+#             */
/*   Updated: 2024/06/10 21:21:09 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node	*new_element;

	new_element = create_node(data);
	if (new_element == NULL)
		return ;
	new_element->next = stack->top;
	stack->top = new_element;
}

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		data;

	if (stack->top == NULL)
		return (-1);
	tmp = stack->top;
	stack->top = stack->top->next;
	data = tmp->data;
	free(tmp);
	return (data);
}

int	is_stack_sorted(t_stack *s)
{
	int		flag;
	t_node	*current;

	flag = 1;
	current = s->top;
	while (current != NULL && current->next != NULL)
	{
		if (current->data > current->next->data)
			flag = 0;
		current = current->next;
	}
	return (flag);
}

int	is_stack_sorted_rev(t_stack *s)
{
	int		flag;
	t_node	*current;

	flag = 1;
	current = s->top;
	while (current != NULL && current->next != NULL)
	{
		if (current->data < current->next->data)
			flag = 0;
		current = current->next;
	}
	return (flag);
}

void	free_stack_ab(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_stack_empty(stack_a))
		pop(stack_a);
	while (!is_stack_empty(stack_b))
		pop(stack_b);
	free(stack_a);
	free(stack_b);
}
