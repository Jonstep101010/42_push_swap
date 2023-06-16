/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:35:36 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/16 19:05:53 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate(struct t_stack *stack, int new_data)
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

void	append(struct t_stack *stack, int new_data)
{
	t_stack	*new_item;
	t_stack	*last;

	new_item = malloc(sizeof(t_stack));
	new_item->data = new_data;
	new_item->next = stack->head;
	if (stack->head == NULL)
	{
		new_item->prev = new_item;
		stack->head = new_item;
		return ;
	}
	last = stack->head;
	while (last->next != stack->head)
		last = last->next;
	last->next = new_item;
	new_item->prev = last;
	new_item->next->prev = new_item;
}

void	print_stack(struct t_stack *stack)
{
	t_stack	*t_i;

	if (!stack->head)
		return ((void)ft_printf("\n!EMPTY/BROKEN!\n"));
	t_i = stack->head;
	while (t_i != stack->head->prev)
	{
		if (t_i == stack->head)
			ft_printf("\n(head) %d -> ", t_i->data);
		else
			ft_printf("%d -> ", t_i->data);
		if (t_i->next->next == stack->head)
			ft_printf("%d (tail)\n", t_i->next->data);
		t_i = t_i->next;
	}
	if (t_i == stack->head->prev && t_i == stack->head)
		ft_printf("\n(single element) %d\n", t_i->data);
}

t_stack	parse_input(t_stack *stack, char **argv)
{
	int	i;

	i = 0;
	while (argv[i + 1])
		populate(stack, ft_atoi((ft_split(argv[++i], ' ')[0])));
	return (*stack);
}
