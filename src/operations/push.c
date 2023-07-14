/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:03:44 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 19:56:26 by jschwabe         ###   ########.fr       */
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

static void	push_new(t_stack *new, t_node *popped, t_type type)
{
	popped->next = popped;
	popped->prev = popped;
	new->head = popped;
	new->tail = popped;
	new->type = type;
}

void	pb(t_box *box)
{
	t_node	*popped;

	popped = pop(&(box->a));
	if (!&(box->b) || !box->b.head)
		push_new(&(box->b), popped, B);
	else if (box->b.head == box->b.tail)
	{
		popped->next = box->b.tail;
		box->b.tail->prev = popped;
		box->b.tail->next = popped;
		popped->prev = box->b.tail;
		box->b.head = popped;
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

void	pa(t_box *box)
{
	t_node	*popped;

	popped = pop(&(box->b));
	if (!&(box->a) || !box->a.head)
		push_new(&(box->a), popped, A);
	else if (box->a.head == box->a.tail)
	{
		popped->next = box->a.tail;
		box->a.tail->prev = popped;
		box->a.tail->next = popped;
		popped->prev = box->a.tail;
		box->a.head = popped;
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
