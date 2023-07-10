/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:13:37 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/10 19:35:06 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//true = rotate
//false = rev_rotate

bool	calc_rot_two(t_stack *stack, int val)
{
	t_node	*current;
	int	tmp;

	stack->size = elementcount(stack);
	tmp = 0;
	current = stack->head;
	while (tmp < (int) (stack->size / 2))
	{
		if (current->index == val)
			break;
		current = current->next;
		tmp++;
	}
	current = stack->head;
	while (tmp != (int) (stack->size / 2))
	{
		if (current->index == val)
			break;
		current = current->prev;
		tmp--;
	}
	if (tmp > 0)
		return (false);
	return (true);
}

/*
** @brief return lowest index in stack
*/
int	find_lowest(t_stack *stack)
{
	size_t	i;
	t_node	*current;
	int	lowest;

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
int	find_highest(t_stack *stack)
{
	size_t	i;
	t_node	*current;
	int		highest;

	stack->size = elementcount(stack);
	if (stack->size == 1)
		return ((int)stack->head->index);
	highest = 0;
	i = stack->size;
	current = stack->head;
	while (i > 1)
	{
		if (highest == 0)
			highest = current->index;
		else if (current->index > highest)
			highest = current->index;
		current = current->next;
		i--;
	}
	return (highest);
}

/*
** @brief determine efficacy of rotation direction
*/
void	rotate_top(t_stack *stack)
{
	int	tmp;
	int	tmp2;
	stack->size = elementcount(stack);
	if (stack->size <= 3)
		return;
	tmp = find_lowest(stack);
	tmp2 = tmp;
	if (tmp == 1 && stack->size == 5)
		tmp2 = 2;
	if (calc_rot_two(stack, tmp) == true || calc_rot_two(stack, tmp2) == true)
	{
		while (!(stack->head->index == tmp || stack->head->index == tmp2))
			rotate(stack, A);
	}
	else
	{
		while (!(stack->head->index == tmp || stack->head->index == tmp2))
			rev_rotate(stack, A);
	}
}
