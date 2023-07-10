/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:19:28 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/10 11:10:07 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// print_index(&(box->a));
	return (size);
}
