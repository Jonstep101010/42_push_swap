/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/17 17:10:58 by jschwabe         ###   ########.fr       */
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

//return if rotate (1) or rev_rotate (0), error (-1)
int		calc_moves(t_stack *stack, t_node *target)
{
	t_node	*current;
	int	counter = 0;

	stack->size = elementcount(stack);
	current = stack->head;
	while (current != target && counter <= ((int)stack->size / 2))
	{
		current = current->next;
		counter++;
	}
	current = stack->head;
	int	counter2 = 0;
	while (current != target  && counter2 <= ((int)stack->size / 2))
	{
		current = current->prev;
		counter2++;
	}
	// if (counter > (int)(stack->size / 2) + 1)
	// 	return (-1);
	if (counter <= counter2)
		return (1);
	else if (counter > counter2)
		return (0);
	return (-1);
}

int	find_chunk_member(t_box *box, t_vals *chunks)
{
	t_node	*current;
	int		count1;
	int calc1;
	int calc2;
	int		count2;

	count1 = 0;
	count2 = 0;
	calc1 = -2;
	calc2 = -2;
	current = box->a.head;
	while (current->chunk != chunks->id && count1 < (int)box->a.size)
	{
		count1++;
		current = current->next;
	}
	if (current->chunk == chunks->id)
		calc1 = calc_moves(&(box->a), current);
	current = box->a.head;
	while (current->chunk != chunks->id && count2 < (int)box->a.size)
	{
		count2++;
		current = current->prev;
	}
	if (current->chunk == chunks->id)
		calc2 = calc_moves(&(box->a), current);
	if (calc1 == -1 || calc2 == -1 || calc1 == -2 || calc2 == -2)
		return (-1);
	if (count1 <= count2)
		return (calc1);
	else if (count2 < count1)
		return (calc2);
	return (-1);
}

//know more about function pointers!!
//6 4 1 3 5 2
bool	push_member(t_box *box, t_vals *vals)
{
	int direction;

	if (!(box->a.head))
		return (false);
	direction = find_chunk_member(box, vals);
	vals->max = vals->size * vals->id;
	if (direction == -1 && vals->id < vals->max)
		return (false);
	vals->max = vals->size * vals->id;
	if (!&(box->a) || !(box->a.head))
		return (false);
	while (box->a.head->chunk != vals->id)
	{
		if (direction == 1)
			ra(box);
		else if (direction == 0)
			rra(box);
	}
	if (box->a.head->chunk == vals->id)
	{
		ft_printf("[%d][%d]: %d\n", box->a.head->chunk, box->a.head->index, box->a.head->data);
		pb(box);
	}
	return (true);
	// if (vals->id < vals->max)
	// 	push_member(box, vals);
}
	
void	push_chunks(t_box *box, t_vals *chunks)
{
	int	i = 0;
	chunks->id = 1;
	// ft_printf("chunks nbr %d\n", chunks->nbr);
	chunks->max = chunks->size * chunks->id;
	ft_printf("vals max %d\n", chunks->max);
	while (chunks->id <= chunks->nbr)
	{
		i = 0;
		chunks->max = chunks->size * chunks->id;
		if (!&(box->a) || !&(box->a.head))
			break;
		while (++i <= chunks->max && push_member(box, chunks) == true)
		{
			if (chunks->id % 2 == 0)
				rb(box);
		}
		chunks->id++;
	}
	// print_stack(&(box->b));
	// ft_printf("after rotating/pushing (sort_chunks) member (stack A):\n");
	// print_stack(&(box->a));
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
	// if ((((int)box->a.size) % chunks.nbr) != 0)
	// 	chunks.size+= 1;
	assign_chunks(box, &(chunks));
	print_chunks(box);
	print_stack(&(box->a));
	push_chunks(box, &chunks);
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
		error(box);
		scope_error("not sorted: sorting incorrect");
	}
}

	// else
	// 	print_stack(&(box->a));
	// else if (box->a.size == 500)
	// 		sort
	// else
	// 	sort_huge(box);
