/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:13:37 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 20:35:46 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief determine efficacy of rotation direction
*/
void	rotate_top(t_box *box, t_type type)
{
	t_stack	*stack;
	int		tmp;
	int		tmp2;

	stack = &(box->a);
	if (type == B)
		stack = &(box->b);
	stack->size = elementcount(stack);
	if (stack->size <= 3)
		return ;
	tmp = find_lowest(stack);
	tmp2 = tmp;
	if (tmp == 1 && stack->size == 5)
		tmp2 = 2;
	if (calc_rot(stack, tmp) == true || calc_rot(stack, tmp2) == true)
	{
		while (!(stack->head->index == tmp || stack->head->index == tmp2))
			ra(box);
	}
	else
	{
		while (!(stack->head->index == tmp || stack->head->index == tmp2))
			rra(box);
	}
}
