/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:02:26 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 13:56:00 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/*
** @brief swap first two elements' data within stack
*/
static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->next->data;
	stack->head->next->data = stack->head->data;
	stack->head->data = tmp;
	tmp = stack->head->next->index;
	stack->head->next->index = stack->head->index;
	stack->head->index = tmp;
}

void	sa(t_box *box)
{
	t_stack	*a;

	a = &(box->a);
	if (elementcount(a) > 1)
	{
		swap(a);
		ft_printf("sa\n");
	}
}

void	sb(t_box *box)
{
	t_stack	*b;

	b = &(box->b);
	if (elementcount(b) > 1)
	{
		swap(b);
		ft_printf("sb\n");
	}
}

void	ss(t_box *box)
{
	size_t	s_a;
	size_t	s_b;

	s_a = elementcount(&(box->a));
	s_b = elementcount(&(box->b));
	if (s_a < 2 && s_b < 2)
		return ;
	else if (s_a < 2 || s_b < 2)
	{
		if (s_a > s_b)
			sa(box);
		else
			sb(box);
		return ;
	}
	else
	{
		swap(&(box->a));
		swap(&(box->b));
		ft_printf("ss\n");
	}
}
