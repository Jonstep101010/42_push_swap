/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:02:26 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/11 14:09:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, AB);
	swap(stack_b, AB);
	ft_printf("ss\n");
}

/*
** @brief swap first two elements of stack
*/
void	swap(t_stack *stack, t_type type)
{
	int	tmp;

	if (elementcount(stack) <= 1)
		return ;
	tmp = stack->head->next->data;
	stack->head->next->data = stack->head->data;
	stack->head->data = tmp;
	tmp = stack->head->next->index;
	stack->head->next->index = stack->head->index;
	stack->head->index = tmp;
	if (type == A)
		ft_printf("sa\n");
	else if (type == B)
		ft_printf("sb\n");
	else
		return ;
}
