/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:02:26 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/16 19:08:36 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push
//What should push with NULL be?
//do nothing
void	push(t_stack stack_a, t_stack stack_b)
{
	
}

//pop
//What should be the result of popping an empty stack?

//swap
//rotate
//What should swap and rotate on a 1-element stack do?
//do nothing

void	swap_both(t_stack stack_a, t_stack stack_b)
{
	swap(&stack_a);
	swap(&stack_b);
}

/*
** @brief swap first two elements of stack
** 
*/
void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack)
		scope_error("swap attempt on ZERO value");
	tmp = stack->head->next->data;
	stack->head->next->data = stack->head->data;
	stack->head->data = tmp;
}
