/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:46:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/04 14:25:47 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*create_head(t_stack *stack)
{
	t_stack	*new_head;

	new_head = malloc(sizeof(t_stack));
	new_head->next = new_head;
	new_head->prev = new_head;
	stack->head = new_head;
	return (stack);
}

t_stack	*populate(t_stack *stack, int new_data)
{
	t_stack	*new_item;
	t_stack	*last;

	if (!stack || !(stack->head))
	{
		new_item = malloc(sizeof(t_stack));
		new_item->data = new_data;
		new_item->next = new_item;
		new_item->prev = new_item;
		new_item->head = new_item;
		new_item->tail = new_item;
		return (new_item);
	}
	new_item = malloc(sizeof(t_stack));
	new_item->data = new_data;
	last = stack->head;
	if (stack->head == stack->tail)
	{
		stack->tail = new_item;
		stack->tail->prev = stack->head;
		stack->tail->next = stack->head;
		stack->head->next = stack->tail;
		stack->head->prev = stack->tail;
		return (stack);
	}
	while (last->next != stack->head)
		last = last->next;
	stack->tail = new_item;
	stack->tail->data = new_data;
	stack->tail->prev = last;
	stack->tail->prev->next = stack->tail;
	stack->tail->next = stack->head;
	stack->tail->next->prev = stack->tail;
	return (stack);
}
