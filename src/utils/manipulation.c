/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:58:16 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/11 19:00:29 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepend(t_stack *stack, int new_data)
{
	t_node	*new_item;

	new_item = ft_calloc(1, sizeof(t_node));
	new_item->data = new_data;
	new_item->next = stack->head;
	if (stack->head == NULL)
	{
		new_item->prev = new_item;
		new_item->next = new_item;
		stack->head = new_item;
		stack->tail = new_item;
		return ;
	}
	new_item->prev = stack->tail;
	new_item->prev->next = new_item;
	stack->head = new_item;
}

void	append(t_stack *stack, int new_data)
{
	t_node	*new_item;
	t_node	*last;

	new_item = ft_calloc(1, sizeof(t_node));
	new_item->data = new_data;
	new_item->next = stack->head;
	if (stack->head == NULL)
	{
		new_item->prev = new_item;
		new_item->next = new_item;
		stack->head = new_item;
		stack->tail = new_item;
		return ;
	}
	last = stack->tail;
	last->next = new_item;
	new_item->prev = last;
	new_item->next->prev = new_item;
	stack->tail = new_item;
}
