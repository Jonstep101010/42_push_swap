/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:57:09 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 18:57:23 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push_member(t_box *box, t_vals *vals)
{
	int		direction;

	if (!(box->a.head))
		return (false);
	direction = find_chunk_member(box, vals);
	vals->max = vals->size * vals->id;
	if (direction == -1 && vals->id < vals->max)
		return (false);
	if (!&(box->a) || !(box->a.head))
		return (false);
	while (direction == 1 && box->a.head->chunk != vals->id)
		ra(box);
	while (direction == 0 && box->a.head->chunk != vals->id)
		rra(box);
	if (box->a.head->chunk == vals->id)
		pb(box);
	return (true);
}

static void	push_chunks(t_box *box, t_vals *chunks)
{
	int		i;

	chunks->id = 1;
	while (chunks->id < chunks->nbr && &(box->a.head))
	{
		i = 0;
		chunks->max = chunks->size * chunks->id;
		while (++i <= chunks->max && push_member(box, chunks) == true)
		{
			if (chunks->id % 2 == 0)
				rb(box);
		}
		chunks->id++;
	}
	while (box->a.size > 5)
	{
		if (box->a.head->index < (int)box->size - 4)
			pb(box);
		else
			ra(box);
	}
	if (box->a.size == 5 && chunks->nbr)
		sort_five(box);
}

void	sort_chunks(t_box *box)
{
	t_vals		chunks;

	chunks.id = 1;
	if (box->a.size <= 100)
		chunks.nbr = 4;
	else if (box->a.size <= 200)
		chunks.nbr = 5;
	else if (box->a.size <= 500)
		chunks.nbr = 11;
	else
		chunks.nbr = 30;
	chunks.size = (((int)box->a.size) / chunks.nbr);
	assign_chunks(box, &(chunks));
	push_chunks(box, &chunks);
	sort_from_b(box);
}
