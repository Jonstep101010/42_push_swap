/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:19:28 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 20:31:38 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief checks if stack is empty, counts elements
*/
size_t	elementcount(t_stack *stack)
{
	t_node	*t_i;
	size_t	i;

	if (!stack || !stack->head)
		return (0);
	if (stack->head == stack->tail)
		return (1);
	t_i = stack->head->next;
	i = 2;
	while (t_i->next != stack->head)
	{
		t_i = t_i->next;
		i++;
	}
	return (i);
}

size_t	index_box(t_box *box)
{
	size_t	size;
	int		i;
	t_node	*current;
	t_node	*tmp;

	size = elementcount(&(box->a));
	current = box->a.head;
	box->a.tail->next = NULL;
	while (current)
	{
		i = 1;
		tmp = box->a.head;
		while (tmp)
		{
			if (current->data > tmp->data)
				i++;
			tmp = tmp->next;
		}
		current->index = i;
		current = current->next;
	}
	box->a.tail->next = box->a.head;
	return (size);
}
