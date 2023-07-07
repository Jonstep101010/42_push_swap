/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:02:26 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/06 11:34:10 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push
//What should push with NULL be?
//do nothing

t_stack	*pop(t_stack *to_pop)
{
	t_stack	*popnode;
	// t_stack	*ret;
	// ret = NULL;
	// ret = malloc(sizeof(t_stack));

	if (!to_pop || !to_pop->head)
		return (NULL);
	popnode = stacks.a
	// if (!ret)
	// 	scope_error("alloc fail in pop");
	// popnode = to_pop->head;
	if (to_pop->head == to_pop->tail)
	{
		to_pop->head =  NULL;
		to_pop->tail = NULL;
	}
	else
	{
		to_pop->head = to_pop->head->next;
		to_pop->head->prev = to_pop->tail;
		to_pop->tail->next = to_pop->head;
	}
	popnode->next = NULL;
	popnode->prev = NULL;
	// popnode->prev = to_pop->tail;
	// popnode = to_pop->head->next;
	
	// popnode->next->prev = to_pop->head;
	// to_pop->head->next->next->prev = popnode;
	// to_pop->tail->next = popnode;
	// popnode->prev = to_pop->tail;
	// ret = to_pop->head;
	// to_pop->head = popnode;
	return (popnode);
}

void	push(t_box *stacks, t_type type)
{
	t_stack	*popnode;
	popnode = NULL;
	
	if (type == B)
	{
		popnode = pop(stacks->a);
		printf("%d", popnode->data);
		print_stack(stacks->a);
		// printf("%d", popnode->data);
		stacks->b = popnode;
		popnode->head = popnode;
		popnode->tail = popnode;
		popnode->next = popnode;
		popnode->prev = popnode;
		stacks->a->head = stacks->a.head->data;
		
		// printf("\n%d", popnode->next->data);
		// printf("\n%d", popnode->prev->data);
		// stacks->b->next = stacks->b;
		// stacks->b->prev = stacks->b;
		
		// stacks->b->tail = stacks->b;
		// stacks->b->head = stacks->b;
		print_stack(stacks->b);
		print_stack(stacks->a);
		if (!stacks->b->head)
		{
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
