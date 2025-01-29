/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:40 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:41 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int data)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		return ;
	new_element->value = data;
	new_element->next = stack->top;
	stack->top = new_element;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		data;

	if (stack->top == NULL)
		return (-1);
	tmp = stack->top;
	stack->top = stack->top->next;
	data = tmp->value;
	free(tmp);
	stack->size--;
	return (data);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->top = NULL;
	return (new_stack);
}

void	free_stack(t_stack *stack)
{
	while (stack->top != NULL)
		pop(stack);
	free(stack);
}

bool	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}
