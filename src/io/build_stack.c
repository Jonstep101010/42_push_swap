/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:46:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/11 13:39:32 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate(t_box *box, int new_data)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	new->data = new_data;
	if (!(box->a.head))
	{
		new->next = new;
		new->prev = new;
		box->a.head = new;
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
