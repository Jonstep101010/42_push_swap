/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:07:33 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 19:03:22 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief sort three digits
** 312, 321, 213, 132, 231
** @param box input stack (only on stack a!)
*/
void	sort_three(t_box *box)
{
	int		hd;
	int		tl;
	int		md;

	hd = box->a.head->data;
	tl = box->a.tail->data;
	md = box->a.head->next->data;
	if (is_sorted(&(box->a)))
		return ;
	if (hd > md && hd > tl)
	{
		if (tl > md)
			return ((void)ra(box));
		return ((void)sa(box), rra(box));
	}
	else if (hd < md && hd > tl)
		return ((void)rra(box));
	if (hd < tl)
		sa(box);
	if (hd < md)
		return ((void)ra(box));
}

/*
** @brief sort five/four numbers using pb
** (smallest 2 numbers)
*/
void	sort_five(t_box *box)
{
	if (elementcount(&(box->a)) == 4)
	{
		rotate_top(box, A);
		pb(box);
		sort_three(box);
		pa(box);
		return ;
	}
	rotate_top(box, A);
	pb(box);
	rotate_top(box, A);
	pb(box);
	sort_three(box);
	pa(box);
	pa(box);
	if (!is_sorted(&(box->a)))
		sa(box);
}
