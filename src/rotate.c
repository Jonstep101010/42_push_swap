/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:07 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/07 18:14:59 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_box *box)
{
	rotate(&(box->a), AB);
	rotate(&(box->b), AB);
	ft_printf("rr\n");
}

/*
** @brief shift up, first to last:
** old head next becomes new head
** old head becomes new tail, new tail prev is old tail
** @param stack 
*/
void	rotate(t_stack *stack, t_type type)
{
	t_node	*tmp;

	if (elementcount(stack) <= 1)
		return ;
	tmp = stack->tail;
	stack->tail = stack->head;
	stack->tail->prev = tmp;
	stack->tail->next = stack->head->next;
	tmp = stack->head;
	stack->head = tmp->next;
	stack->head->next = tmp->next->next;
	stack->head->prev = stack->tail;
	if (type == A)
		ft_printf("ra\n");
	else if (type == B)
		ft_printf("rb\n");
	else
		return;

}
	// ft_printf("\nold head %d\n", stack->head->prev->data);
	// ft_printf("\nold tail %d\n", stack->tail->prev->data);
	// ft_printf("\nnew tail %d\n", stack->tail->prev->next->data);
	// ft_printf("\nnew tail %d\n", stack->tail->next->prev->data);
	// ft_printf("\nnew head %d\n", stack->tail->next->data);
	// ft_printf("\nnew head %d\n", stack->head->next->prev->data);

/*
** @brief shift down, last to first
** 
** tail becomes new head, head next is current head
** old tail prev becomes new tail, tail next is old tail
** @param stack 
*/
void	rev_rotate(t_stack *stack, t_type type)
{
	t_node	*tmp;

	if (elementcount(stack) <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->tail;
	stack->head->next = tmp;
	tmp = stack->tail;
	stack->head->prev = tmp->prev;
	stack->tail = tmp->prev;
	stack->tail->prev = tmp->prev->prev;
	stack->tail->next = stack->head;
	if (type == A)
		ft_printf("rra\n");
	else if (type == B)
		ft_printf("rrb\n");
	else
		return;
}

// 	// ft_printf("\nold head %d\n", stack->head->next->data);
// 	// ft_printf("\nold tail %d\n", stack->tail->next->data);
// 	// ft_printf("\nnew tail %d\n", stack->tail->prev->next->data);
// 	// ft_printf("\nnew tail %d\n", stack->tail->next->prev->data);
// 	// ft_printf("\nnew head %d\n", stack->tail->next->data);
// 	// ft_printf("\nnew head %d\n", stack->head->next->prev->data);

void	rev_rotate_both(t_box *box)
{
	rev_rotate(&(box->a), AB);
	rev_rotate(&(box->b), AB);
	ft_printf("rrr\n");
}
