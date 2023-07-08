/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:03:44 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/08 12:56:31 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*pop(t_stack *to_pop)
{
	t_node	*pop;
	
	if (!to_pop || !to_pop->head)
		return (NULL);
	pop = to_pop->head;
	if (to_pop->head == to_pop->tail)
	{
		to_pop->head = NULL;
		to_pop->tail = NULL;
	}
	else
	{
		to_pop->head = to_pop->head->next;
		to_pop->head->prev = to_pop->tail;
		to_pop->tail->next = to_pop->head;
	}
	pop->next = NULL;
	pop->prev = NULL;
	return (pop);
}

void	push(t_box *box, t_type type)
{
	t_node	*popped;
	if (type == B)
	{
		popped = pop(&(box->a));
		if (!&(box->b) || !box->b.head)
		{
			popped->next = popped;
			popped->prev = popped;
			box->b.head = popped;
			box->b.tail = popped;
			box->b.type = B;
		}
		else if (box->b.head == box->b.tail)
		{
			popped->next = box->b.head;
			box->b.head->prev = popped;
			box->b.head->next = popped;
			popped->prev = box->b.head;
			box->b.tail = popped;
			box->b.tail->next = box->b.head;
			box->b.tail->prev = box->b.head;
		}
		else
		{
			box->b.head->prev = popped;
			box->b.tail->next = popped;
			popped->prev = box->b.tail;
			popped->next = box->b.head;
			box->b.head = popped;
		}
		ft_printf("pb\n");
	}
	else if (type == A)
	{
		popped = pop(&(box->b));
		if (!&(box->a) || !box->a.head)
		{
			popped->next = popped;
			popped->prev = popped;
			box->a.head = popped;
			box->a.tail = popped;
			box->a.type = A;
		}
		else if (box->a.head == box->a.tail)
		{
			popped->next = box->a.head;
			box->a.head->prev = popped;
			box->a.head->next = popped;
			popped->prev = box->a.head;
			box->a.tail = popped;
			box->a.tail->next = box->a.head;
			box->a.tail->prev = box->a.head;
		}
		else
		{
			popped->prev = box->a.tail;
			popped->next = box->a.head;
			box->a.head->prev = popped;
			box->a.tail->next = popped;
			box->a.head = popped;
		}
		ft_printf("pa\n");
	}
}
