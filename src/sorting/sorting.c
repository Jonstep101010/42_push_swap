/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/16 21:12:02 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_chunks(t_box *box)
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
}

void	assign_chunks(t_box *box, t_vals *c)
{
	t_node	*current;

	current = box->a.head;
	while (current)
	{
		c->max = c->size * c->id;
		if (current->index <= c->max)
			current->chunk = c->id;
		else if (current->index >= c->max)
		{
			c->tmp_size = c->max;
			c->tmp_id = c->id;
			while (current->index > c->tmp_size && c->tmp_id < c->nbr)
			{
				c->tmp_size += c->size;
				c->tmp_id++;
			}
			current->chunk = c->tmp_id;
		}
		current = current->next;
		if (current == box->a.head)
			break ;
	}
}

	// while (box->a.head->index < ((int)box->a.size) - 5)
	// {
	// 	pb(box);
	// 	if (box->a.size <= 5 && box->a.head->index > ((int)box->a.size) - 6)
	// 		return ((void)sort_five(box));
	// 	else
	// 		ra(box);
	// }
int		calc_moves(t_stack *stack, t_node *target, t_vals *val)
{
	t_node	*current;
	int	counter_r;

	stack->size = elementcount(stack);
	counter_r = 0;
	val->tmp_id = 0;
	current = stack->head;
	while (current != target)
	{
		current = current->next;
		counter_r++;
	}
	int counter_rr = 0;
	current = stack->head;
	while (current != target)
	{
		current = current->prev;
		counter_rr++;
	}
	ft_printf("ra[%d], rra[%d]\n", counter_r, counter_rr);
	if (counter_rr < counter_r)
	{
		val->tmp_id = -1;
		return (counter_rr);
	}
	val->tmp_id = 1;
	return (counter_r);
	// else
	// {
	// 	val->tmp_id = -1;
	// 	return (counter_rr);
	// }
}

int	find_chunk_member(t_box *box, t_vals *chunks)
{
	t_node	*current;
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	current = box->a.head;
	while (current->chunk != chunks->id && count1 < (int)box->a.size)
	{
		count1++;
		current = current->next;
	}
	if (current->chunk == chunks->id)
		count1 = calc_moves(&(box->a), current, chunks);
	ft_printf("count 1 %d\n", count1);
	current = box->a.head;
	while (current->chunk != chunks->id && count2 < (int)box->a.size)
	{
		count2++;
		current = current->prev;
	}
	int tmp = chunks->tmp_id;
	if (current->chunk == chunks->id)
		count2 = calc_moves(&(box->a), current, chunks);
	ft_printf("count 2 %d\n", count2);
	if (count1 != count2)
	{
		ft_printf("count1[%d], count2[%d]\n", count1, count2);
		if (count1 < count2)
		{
			chunks->tmp_id = tmp;
			return (count1);
		}
		else
			return (count2);
	}
	return (-10);
}

//know more about function pointers!!
void	push_member(t_box *box, t_vals *vals)
{
	int distance = find_chunk_member(box, vals);
	ft_printf("dist %d\n", distance);
	// void	*op;
	ft_printf("vals tmp id %d\n", vals->tmp_id);
	while (box->a.head->chunk != vals->id)
	{
		
		if (vals->tmp_id == 1)
			ra(box);
		else
			return ;
	}
	if (box->a.head->chunk == vals->id)
		ft_printf("[%d][%d]: %d\n", box->a.head->chunk, box->a.head->index, box->a.head->data);

}
	
void	sort_chunks(t_box *box, t_vals *chunks)
{
	chunks->id = 1;
	push_member(box, chunks);
	print_stack(&(box->b));
	print_stack(&(box->a));
}

	// if (box->a.size % 5 == 0)
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
	print_chunks(box);
	sort_chunks(box, &chunks);
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
		print_stack(&(box->a));
		print_stack_rev(&(box->a));
		print_stack(&(box->b));
		print_stack_rev(&(box->b));
		scope_error("not sorted: sorting incorrect");
	}
}

	// else
	// 	print_stack(&(box->a));
	// else if (box->a.size == 500)
	// 		sort
	// else
	// 	sort_huge(box);
