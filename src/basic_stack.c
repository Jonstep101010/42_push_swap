/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:02:26 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/05 19:03:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push
//What should push with NULL be?
//do nothing

t_stack	*pop(t_stack *to_pop)
{
	t_stack	*popnode;
	t_stack	*ret;

	popnode = NULL;
	ret = NULL;
	if (!to_pop || !to_pop->head)
		return (ret);
	ret = to_pop->head;
	popnode = to_pop->head;
	
	popnode->prev = to_pop->tail;
	popnode = to_pop->head->next;
	
	popnode->next->prev = to_pop->head;
	to_pop->head->next->next->prev = popnode;
	to_pop->tail->next = popnode;
	popnode->next->prev = to_pop->tail;
	to_pop->head = popnode;
	return (ret);
}

void	push(t_box *stacks, t_type type)
{
	t_stack	*popnode;
	if (type == B)
	{
		popnode = pop(stacks->a);
		if (!stacks->b->head)
		{
			stacks->b->head = popnode;
			stacks->b->tail = popnode;
			popnode->prev = popnode;
			popnode->next = popnode;
		}
		else
		{
			//
		}
		
		
		ft_printf("pb\n");
	}
}
	// ft_printf("%d\n\n", popnode->data);

	// print_stack(to_pop);

//pop
//What should be the result of popping an empty stack?

//swap
//rotate
//What should swap and rotate on a 1-element stack do?
//do nothing

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, AB);
	swap(stack_b, AB);
}

/*
** @brief swap first two elements of stack
** 
*/
void	swap(t_stack *stack, t_type type)
{
	int	tmp;

	if (elementcount(stack) <= 1)
		return ;
	tmp = stack->head->next->data;
	stack->head->next->data = stack->head->data;
	stack->head->data = tmp;
	if (type == A)
		ft_printf("sa\n");
	else if (type == B)
		ft_printf("sb\n");
	else
		ft_printf("ss\n");
}
	// if (!stack)
	// 	scope_error("swap attempt on ZERO value");
