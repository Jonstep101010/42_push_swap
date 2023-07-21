/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 15:16:27 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	index_box(t_box *box)
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

void	sort(t_box *box)
{
	index_box(box);
	if (is_sorted(&(box->a)))
		return ;
	if (box->a.size == 2)
		sa(box);
	else if (box->a.size == 3)
		sort_three(box);
	else if (box->a.size <= 5)
		sort_five(box);
	else if (box->a.size < 45)
	{
		while (box->a.head)
			pb(box);
		sort_from_b(box);
	}
	else
		sort_chunks(box);
	if (!is_sorted(&(box->a)))
		error(box);
}
