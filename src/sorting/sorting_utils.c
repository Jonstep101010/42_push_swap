/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:13:37 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 15:17:11 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static void	rot_high(t_box *box, t_node *target)
{
	while (box->b.head->index != target->index)
	{
		if (box->b.head->index == target->index - 2
			&& box->b.head->next->index != target->index -1
			&& box->b.head->next->index != target->index)
		{
			pa(box);
			ra(box);
		}
		if (box->b.head->index == target->index - 1)
			pa(box);
		else
			rb(box);
	}
}

static void	rev_rotate_high(t_box *box, t_node *target)
{
	while (box->b.head->index != target->index)
	{
		if (box->b.head->index == target->index - 2
			&& box->b.head->prev->index != target->index -1
			&& box->b.head->prev->index != target->index)
		{
			pa(box);
			ra(box);
		}
		if (box->b.head->index == target->index - 1)
			pa(box);
		else
			rrb(box);
	}
}

static bool	rotate_highest_b(t_box *box)
{
	int		direction;
	t_node	*target;

	target = find_highest(&(box->b));
	direction = calc_moves(&(box->b), target);
	if (direction == 1)
		rot_high(box, target);
	if (direction == 0)
		rev_rotate_high(box, target);
	return (true);
}

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
	stack->size = i;
	return (i);
}

void	sort_from_b(t_box *box)
{
	while (box->b.head)
	{
		if (rotate_highest_b(box))
			pa(box);
		if (box->a.head->index -1 >= box->a.head->next->index)
			sa(box);
		if (box->a.head->index -1 >= box->a.tail->index)
			rra(box);
	}
}
