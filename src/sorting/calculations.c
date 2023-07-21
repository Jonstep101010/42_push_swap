/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:29:27 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 16:43:43 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
** @brief return node with highest index
*/
t_node	*find_highest(t_stack *stack)
{
	t_node	*target;
	t_node	*current;
	int		i;
	int		highest;

	stack->size = elementcount(stack);
	if (stack->size == 1)
		return (stack->head);
	highest = 0;
	target = NULL;
	i = stack->size;
	current = stack->head;
	while (i)
	{
		if (highest == 0 || current->index > highest)
		{
			highest = current->index;
			target = current;
		}
		current = current->next;
		i--;
	}
	return (target);
}

int	find_chunk_member(t_box *box, t_vals *chunks)
{
	t_node	*current;
	int		count1;
	int		calc1;
	int		calc2;
	int		count2;

	count1 = 0;
	count2 = 0;
	calc1 = -2;
	calc2 = -2;
	current = box->a.head;
	while (current->chunk != chunks->id && count1++ <= (int)box->a.size)
		current = current->next;
	if (current->chunk == chunks->id)
		calc1 = calc_moves(&(box->a), current);
	current = box->a.head;
	while (current->chunk != chunks->id && count2++ <= (int)box->a.size)
		current = current->prev;
	if (current->chunk == chunks->id)
		calc2 = calc_moves(&(box->a), current);
	if (calc1 == -1 || calc2 == -1 || calc1 == -2 || calc2 == -2)
		return (-1);
	if (count1 <= count2)
		return (calc1);
	return (calc2);
}

/*
** @brief return lowest index in stack
*/
int	find_lowest(t_stack *stack)
{
	t_node	*current;
	int		i;
	int		lowest;

	lowest = 0;
	i = 1;
	stack->size = elementcount(stack);
	current = stack->head;
	while (i <= stack->size)
	{
		if (lowest == 0)
			lowest = current->index;
		else if (current->index < lowest)
			lowest = current->index;
		current = current->next;
		i++;
	}
	return (lowest);
}

/*
** @brief calculate best approach to target
** 
** @return int rotate (1), rev_rotate (0), error (-1)
*/
int	calc_moves(t_stack *stack, t_node *target)
{
	t_node	*current;
	int		counter;
	int		counter2;

	counter = 0;
	counter2 = 0;
	current = stack->head;
	while (current != target && counter++ <= ((int)stack->size / 2))
	{
		current = current->next;
	}
	current = stack->head;
	while (current != target && counter2++ <= ((int)stack->size / 2))
	{
		current = current->prev;
	}
	if (counter <= counter2)
		return (1);
	else if (counter > counter2)
		return (0);
	return (-1);
}
