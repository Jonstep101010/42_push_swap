/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:46:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 16:31:15 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*check_alloc(t_box *box, int data)
{
	t_node	*new;

	new = NULL;
	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		error(box);
	new->data = data;
	return (new);
}

void	populate(t_box *box, int new_data)
{
	t_node	*new;

	new = check_alloc(box, new_data);
	if (!(box->a.head))
	{
		new->next = new;
		new->prev = new;
		box->a.head = new;
		box->a.type = A;
	}
	else if ((box->a.head) == (box->a.tail))
	{
		new->next = box->a.head;
		box->a.head->prev = new;
		box->a.head->next = new;
		new->prev = box->a.head;
	}
	else
	{
		box->a.head->prev = new;
		box->a.tail->next = new;
		new->prev = box->a.tail;
		new->next = box->a.head;
	}
	box->a.tail = new;
}
