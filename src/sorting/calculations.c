/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:29:27 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 20:58:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief calculate rotation to get to value
** 
** @return true rotate
** @return false rev_rotate
*/
bool	calc_rot(t_stack *stack, int val)
{
	t_node	*current;
	int		tmp;

	stack->size = elementcount(stack);
	tmp = 0;
	current = stack->head;
	while (tmp < (int)(stack->size / 2))
	{
		if (current->index == val)
			return (true);
		current = current->next;
		tmp++;
	}
	current = stack->tail;
	while (tmp < (int)(stack->size))
	{
		if (current->index == val)
			return (false);
		current = current->prev;
		tmp--;
	}
	return (false);
}
