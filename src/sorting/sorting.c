/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/18 18:19:28 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_chunks(t_box *box)
{
	t_node	*current;

	current = box->a.head;
	while (current)
	{
		ft_printf("chunk [%d][%d]: %d\n", \
		current->chunk, current->index, current->data);
		current = current->next;
		if (current == box->a.head)
			break ;
	}
} */

//know more about function pointers!!
bool	push_member(t_box *box, t_vals *vals)
{
	int	direction;

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

void	push_chunks(t_box *box, t_vals *chunks)
{
	int	i;

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
	while (box->a.head->index <= (int)box->size && box->a.size > 5)
	{
		if (box->a.head->index >= (int)box->size - 5)
			ra(box);
		pb(box);
	}
	// if (box->a.size == 5)
	// 	sort_five(box);
	// if (box->a.size == 2 && !is_sorted(&(box->a)) && box->b.head->index < box->a.head->index)
	// 	rr(box);
	// while (is_sorted(&(box->a)) && (box->b.head->index == box->a.head->index -1 || box->b.tail->index == box->a.head->index -1))
	// {
	// 	if (box->b.head->index >= box->a.head->index -2)
	// 		pa(box);
	// 	else if (box->a.tail->index == box->a.head->index -1)
	// 	{
	// 		rrb(box);
	// 		pa(box);
	// 	}
	// 	else if (box->b.head->index > box->a.head->index - 50)
	// 		rb(box);
	// }
	// // sort_five(box);
	// while (box->b.head->index >= (int) box->size -1)
	// 	pa(box);
}

// print_chunks(box);
void	define_chunks(t_box *box)
{
	t_vals		chunks;

	chunks.id = 1;
	if (box->a.size <= 100)
		chunks.nbr = 3;
	else if (box->a.size <= 200)
		chunks.nbr = 5;
	else if (box->a.size <= 500)
		chunks.nbr = 7;
	else
		chunks.nbr = 10;
	chunks.size = (((int)box->a.size) / chunks.nbr);
	assign_chunks(box, &(chunks));
	push_chunks(box, &chunks);
	// while (box->b.head->chunk == chunks.nbr && box->b.head->index <= box->a.head->index - 3)
	// 	rb(box);
	// pa(box);
	// if (box->a.head->index + 1 == box->a.head->next->index)
		
	// if (chunks.nbr == 3)
	// 	sort_big(box);
	// print_stack(&(box->a));
	// print_stack(&(box->b));
	if (!is_sorted(&(box->b)))
		error(box);
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
	else if (box->a.size > 5)
		define_chunks(box);
	if (!is_sorted(&(box->a)))
	{
		ft_printf("box a\n");
		print_stack(&(box->a));
		print_stack_rev(&(box->a));
		ft_printf("box b\n");
		print_stack(&(box->b));
		print_stack_rev(&(box->b));
		error(box);
		scope_error("not sorted: sorting incorrect");
	}
}
