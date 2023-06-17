/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/17 12:17:46 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	parse_input(t_stack *stack, char **argv)
{
	int	i;

	i = 0;
	while (argv[i + 1])
		populate(stack, ft_atoi((ft_split(argv[++i], ' ')[0])));
	return (*stack);
}

void	populate(t_stack *stack, int new_data)
{
	t_stack	*new_item;
	t_stack	*last;

	new_item = malloc(sizeof(t_stack));
	if (!(stack->head))
	{
		new_item->data = new_data;
		new_item->next = new_item;
		new_item->prev = new_item;
		stack->head = new_item;
	}
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
