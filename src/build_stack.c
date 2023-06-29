/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:46:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/29 10:59:54 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_head(t_stack *stack, int new_data)
{
	t_stack	*new_item;

	if (!(stack->head))
	{
		new_item = malloc(sizeof(t_stack));
		new_item->data = new_data;
		new_item->next = new_item;
		new_item->prev = new_item;
		stack->head = new_item;
	}
	else
	{
		new_item = malloc(sizeof(t_stack));
	}
	return (new_item);
}

bool	populate(t_stack *stack, int new_data)
{
	t_stack	*new_item;
	t_stack	*last;

	new_item = create_head(stack, new_data);
	new_item->data = new_data;
	last = stack->head;
	new_item->next = stack->head;
	while (last->next != stack->head)
		last = last->next;
	last->next = new_item;
	new_item->prev = last;
	new_item->next->prev = new_item;
	stack->tail = stack->head->prev;
	return (true);
}
	// if (!(stack->head))
	// {
	// 	new_item->prev = new_item;
	// 	stack->head = new_item;
	// }
