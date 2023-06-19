/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:02:26 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/19 15:24:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push
//What should push with NULL be?
//do nothing
void	push(t_stack *to_push, t_stack *to_pop)
{
	t_stack	*popnode;

	popnode = pop(to_pop);
	ft_printf("%d\n\n", popnode->data);
	if (popnode)
		stack_push(to_push, popnode);
}

t_stack	*pop(t_stack *to_pop)
{
	t_stack	*popnode;
	t_stack	*ret;

	popnode = NULL;
	ret = NULL;
	print_stack(to_pop);
	if (!to_pop || !to_pop->head)
		return (ret);
	ret = to_pop->head;
	popnode = to_pop->head;
	popnode->prev = to_pop->tail;
	popnode = to_pop->head->next;
	popnode->next = to_pop->head->next->next;
	to_pop->head->next->next->prev = popnode;
	to_pop->tail->next = popnode;
	popnode->next->prev = to_pop->tail;
	to_pop->head = popnode;
	return (ret);
}

//pop
//What should be the result of popping an empty stack?

//swap
//rotate
//What should swap and rotate on a 1-element stack do?
//do nothing

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

/*
** @brief swap first two elements of stack
** 
*/
void	swap(t_stack *stack)
{
	int	tmp;

	if (elementcount(stack) <= 1)
		return ;
	// if (!stack)
	// 	scope_error("swap attempt on ZERO value");
	tmp = stack->head->next->data;
	stack->head->next->data = stack->head->data;
	stack->head->data = tmp;
}
