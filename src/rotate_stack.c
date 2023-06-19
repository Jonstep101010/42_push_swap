/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.4.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 03/06/19 1:47:5 by jschwabe          #+#    #+#             */
/*   Updated: 03/06/19 1:51:14 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *stack_1, t_stack *stack_)
{
	rotate(stack_1);
	rotate(stack_);
}

/*
** @brief shift up, first to last:
** old head next becomes new head
** old head becomes new tail, new tail prev is old tail
** @param stack 
*/
void	rotate(t_stack *stack)
{
	t_stack	*tmp;

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
	check_stack(stack);
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
void	rev_rotate(t_stack *stack)
{
	t_stack	*tmp;

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
	check_stack(stack);
}

	// ft_printf("\nold head %d\n", stack->head->next->data);
	// ft_printf("\nold tail %d\n", stack->tail->next->data);
	// ft_printf("\nnew tail %d\n", stack->tail->prev->next->data);
	// ft_printf("\nnew tail %d\n", stack->tail->next->prev->data);
	// ft_printf("\nnew head %d\n", stack->tail->next->data);
	// ft_printf("\nnew head %d\n", stack->head->next->prev->data);
void	rev_rotate_both(t_stack *stack_1, t_stack *stack_2)
{
	rev_rotate(stack_1);
	rev_rotate(stack_2);
}
