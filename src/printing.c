/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:54:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/29 11:03:18 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief prints stack (head to tail)
*/
void	print_stack(t_stack *stack)
{
	t_stack	*t_i;

	if (!stack->head)
		return ((void)ft_printf("\n!EMPTY/BROKEN!\n"));
	t_i = stack->head;
	while (t_i->next != stack->head)
	{
		if (t_i == stack->head)
			ft_printf("\n(head) %d -> ", t_i->data);
		else
			ft_printf("%d -> ", t_i->data);
		if (t_i->next->next == stack->head)
			ft_printf("%d (tail)\n", t_i->next->data);
		t_i = t_i->next;
	}
	if (t_i == stack->head->prev && t_i == stack->head)
		ft_printf("\n(single element) %d\n", t_i->data);
}
		// if (t_i->next->data == t_i->next->next->data)
		// {
		// 	if (t_i == stack->head)
		// 		ft_printf("\n(single data node) %d", t_i->data);
		// 	else
		// 		ft_printf("%d (last filled)", t_i->data);
		// 	return ;
		// }

void	print_stack_rev(t_stack *stack)
{
	t_stack	*t_i;

	if (!stack->tail)
		return ((void)ft_printf("\n!EMPTY/BROKEN!\n"));
	t_i = stack->tail;
	while (t_i != stack->head)
	{
		if (t_i == stack->tail)
			ft_printf("\n(tail) %d -> ", t_i->data);
		else
			ft_printf("%d -> ", t_i->data);
		if (t_i->prev->prev == stack->tail)
			ft_printf("%d (head)\n", t_i->prev->data);
		t_i = t_i->prev;
	}
	if (t_i == stack->head->prev && t_i == stack->head)
		ft_printf("\n(single element) %d\n", t_i->data);
}
