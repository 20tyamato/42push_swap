/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:38 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:38 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*new_stack;
	t_list	*current;

	new_stack = create_stack();
	if (new_stack == NULL)
		return (NULL);
	current = stack->top;
	while (current != NULL)
	{
		push(new_stack, current->value);
		current = current->next;
	}
	return (new_stack);
}

int	get_position_from_top(t_stack *stack, int value)
{
	t_list	*current;
	int		i;

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

int	get_top_element_of_stack(t_stack *stack)
{
	if (stack->top)
		return (stack->top->value);
	return (INT_MIN);
}

int	get_bottom_element_of_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current->next)
		current = current->next;
	return (current->value);
}

void	print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	if (!current)
	{
		ft_putstr_fd("empty\n", STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd("======================\n", STDOUT_FILENO);
	ft_putstr_fd("top\n", STDOUT_FILENO);
	while (current)
	{
		ft_putnbr_fd(current->value, STDOUT_FILENO);
		current = current->next;
	}
	ft_putstr_fd("bottom\n", STDOUT_FILENO);
	ft_putstr_fd("======================\n", STDOUT_FILENO);
}
