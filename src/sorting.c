/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/28 22:54:05 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief sort three digits
** 312, 321, 213, 132, 231
** @param a input stack
*/
void	sort_three(t_stack *a)
{
	int	hd;
	int	tl;
	int	md;

	hd = a->head->data;
	tl = a->tail->data;
	md = a->head->next->data;
	if (hd > md && hd > tl)
	{
		if (tl > md)
			return ((void)rotate(a));
		return ((void)swap(a), rev_rotate(a));
	}
	else if (hd < md && hd > tl)
		return ((void)rev_rotate(a));
	if (hd < tl)
		swap(a);
	if (hd < md)
		return ((void)rotate(a));
}

void	sort(t_stack *a)
{
	//sort using insertion and merge sort
	//limit number of operations
	//use stack b as temporary storage
	//use stack a as the return stack (sorted) & unsorted input stack
	size_t	size;
	size = elementcount(a);
	if (is_sorted(a))
		return ;
	if (size == 2)
		swap(a);
	else if (size <= 3)
		sort_three(a);
	// else if (size <= 5)
	// 	sort_five(a, b);
	// else
	// 	sort_large(a, b);
}
