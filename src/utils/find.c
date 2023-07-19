/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:05:47 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/19 17:52:10 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief return lowest index in stack
*/
int	find_lowest(t_stack *stack)
{
	t_node	*current;
	size_t	i;
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
** @brief return lowest index in stack
*/
t_node	*find_highest(t_stack *stack)
{
	size_t	i;
	t_node	*current;
	int		highest;
	t_node	*target;

	stack->size = elementcount(stack);
	if (stack->size == 1)
		return (stack->head);
	highest = 0;
	i = stack->size;
	current = stack->head;
	while (i)
	{
		if (highest == 0)
		{
			highest = current->index;
			target = current;
		}
		else if (current->index > highest)
		{
			highest = current->index;
			target = current;
		}	
		current = current->next;
		i--;
	}
	return (target);
}
