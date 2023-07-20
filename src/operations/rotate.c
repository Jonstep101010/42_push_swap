/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:07 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/20 09:11:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief shift up, first to last:
** old head next becomes new head
** old head becomes new tail, new tail prev is old tail
** @param stack 
*/
static void	rotate(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->tail;
	stack->tail = stack->head;
	stack->tail->prev = tmp;
	stack->tail->next = stack->head->next;
	tmp = stack->head;
	stack->head = tmp->next;
	stack->head->next = tmp->next->next;
	stack->head->prev = stack->tail;
}

void	ra(t_box *box)
{
	t_stack	*a;

	a = &(box->a);
	a->size = elementcount(a);
	if (a->size > 1)
	{
		rotate(a);
		ft_printf("ra\n");
	}
}

void	rb(t_box *box)
{
	t_stack	*b;

	b = &(box->b);
	b->size = elementcount(b);
	if (b->size > 1)
	{
		rotate(b);
		ft_printf("rb\n");
	}
}

void	rr(t_box *box)
{
	// box->a.size = elementcount(&(box->a));
	// box->b.size = elementcount(&(box->b));
	if (box->a.size < 2 && box->b.size < 2)
		return ;
	// else if (box->a.size < 2 || box->b.size < 2)
	// {
	// 	if (box->a.size > box->b.size)
	// 		ra(box);
	// 	else
	// 		rb(box);
	// 	return ;
	// }
	// else
	// {
	rotate(&(box->a));
	rotate(&(box->b));
	ft_printf("rr\n");
}
