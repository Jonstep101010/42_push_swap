/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:07:33 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/10 19:12:44 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief sort three digits
** 312, 321, 213, 132, 231
** @param box.a input stack
*/
void	sort_three(t_stack *stack)
{
	t_type	type;
	int		hd;
	int		tl;
	int		md;

	type = stack->type;
	hd = stack->head->data;
	tl = stack->tail->data;
	md = stack->head->next->data;
	if (is_sorted(stack))
		return ;
	if (hd > md && hd > tl)
	{
		if (tl > md)
			return ((void)rotate(stack, type));
		return ((void)swap(stack, type), rev_rotate(stack, type));
	}
	else if (hd < md && hd > tl)
		return ((void)rev_rotate(stack, type));
	if (hd < tl)
		swap(stack, type);
	if (hd < md)
		return ((void)rotate(stack, type));
}

/*
** @brief sort five/four numbers using pb
** (smallest 2 numbers)
*/
void	sort_five(t_box *box)
{
	if (elementcount(&(box->a)) == 4)
	{
		rotate_top(&(box->a));
		push(box, B);
		sort_three(&(box->a));
		push(box, A);
		return ;
	}
	rotate_top(&(box->a));
	push(box, B);
	rotate_top(&(box->a));
	push(box, B);
	sort_three(&(box->a));
	push(box, A);
	push(box, A);
	if (!is_sorted(&(box->a)))
		swap(&(box->a), A);
}
