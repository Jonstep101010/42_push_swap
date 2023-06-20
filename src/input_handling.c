/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/20 13:44:00 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	parse_input(t_stack *stack, t_stack *stack_2, char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i + 1])
		populate(stack, ft_atoi((ft_split(argv[++i], ' ')[0])));
	i = 0;
	while ((stack->head) && i++ <= elementcount(stack))
		make_stack(stack_2);
	return (*stack);
}

void	populate(t_stack *stack, int new_data)
{
	t_stack	*new_item;
	t_stack	*last;

	if (!(stack->head))
		new_item = create_head(stack);
	else
		new_item = malloc(sizeof(t_stack));
	last = stack->head;
	new_item->data = new_data;
	new_item->next = stack->head;
	if (!(stack->head))
	{
		new_item->prev = new_item;
		stack->head = new_item;
	}
	while (last->next != stack->head)
		last = last->next;
	last->next = new_item;
	new_item->prev = last;
	new_item->next->prev = new_item;
	stack->tail = stack->head->prev;
}

t_stack	*create_head(t_stack *stack)
{
	t_stack	*new_head;

	new_head = malloc(sizeof(t_stack));
	new_head->next = new_head;
	new_head->prev = new_head;
	stack->head = new_head;
	return (stack);
}

void	make_stack(t_stack *stack)
{
	t_stack	*new_item;
	t_stack	*last;

	if (!(stack->head))
		new_item = create_head(stack);
	else
		new_item = malloc(sizeof(t_stack));
	last = stack->head;
	new_item->next = stack->head;
	if (!(stack->head))
	{
		new_item->prev = new_item;
		stack->head = new_item;
	}
	while (last->next != stack->head)
		last = last->next;
	last->next = new_item;
	new_item->prev = last;
	new_item->next->prev = new_item;
	stack->tail = stack->head->prev;
}