/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:35:36 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/24 18:35:04 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append(t_stack *stack, int new_data)
{
	t_stack	*new_item;
	t_stack	*last;

	new_item = malloc(sizeof(t_stack));
	new_item->data = new_data;
	new_item->next = stack->head;
	if (stack->head == NULL)
	{
		new_item->prev = new_item;
		stack->head = new_item;
		return ;
	}
	last = stack->head;
	while (last->next != stack->head)
		last = last->next;
	last->next = new_item;
	new_item->prev = last;
	new_item->next->prev = new_item;
}

void	prepend(t_stack *stack, int new_data)
{
	t_stack	*new_item;

	new_item = malloc(sizeof(t_stack));
	new_item->data = new_data;
	new_item->next = stack->head;
	if (stack->head == NULL)
	{
		new_item->prev = new_item;
		stack->head = new_item;
		return ;
	}
	new_item->prev = stack->tail;
	new_item->prev->next = new_item;
	stack->head = new_item;
}

void	stack_push(t_stack *stack, t_stack *popped)
{
	popped->next = stack->head;
	if (stack->head == NULL)
	{
		popped->prev = popped;
		stack->head = popped;
		return ;
	}
	popped->prev = stack->tail;
	stack->tail->next = popped;
	popped->next->prev = popped;
	stack->head = popped;
}
