/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:30:45 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 10:54:40 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/*
** @brief shift down, last to first
**
** tail becomes new head, head next is current head
** old tail prev becomes new tail, tail next is old tail
** @param stack
*/
static void	rev_rotate(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	stack->head = stack->tail;
	stack->head->next = tmp;
	tmp = stack->tail;
	stack->head->prev = tmp->prev;
	stack->tail = tmp->prev;
	stack->tail->prev = tmp->prev->prev;
	stack->tail->next = stack->head;
}

void	rra(t_box *box)
{
	t_stack	*a;

	a = &(box->a);
	a->size = elementcount(a);
	if (a->size > 1)
	{
		rev_rotate(a);
		ft_printf("rra\n");
	}
}

void	rrb(t_box *box)
{
	t_stack	*b;

	b = &(box->b);
	b->size = elementcount(b);
	if (b->size > 1)
	{
		rev_rotate(b);
		ft_printf("rrb\n");
	}
}

void	rrr(t_box *box)
{
	if (box->a.size < 2 && box->b.size < 2)
		return ;
	else if (box->a.size < 2 || box->b.size < 2)
	{
		if (box->a.size > box->b.size)
			rra(box);
		else
			rrb(box);
		return ;
	}
	else
	{
		rev_rotate(&(box->a));
		rev_rotate(&(box->b));
		ft_printf("rrr\n");
	}
}
