/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 14:00:08 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_box *box)
{
	size_t	size;

	size = index_box(box);
	if (is_sorted(&(box->a)))
		return ;
	if (size == 2)
		sa(box);
	else if (size == 3)
		sort_three(box);
	else if (size <= 5)
		sort_five(box);
	// else if (size <= 100)
	// 	sort_big(box);
	// else
	// 	sort_huge(box);
	if (!is_sorted(&(box->a)))
		scope_error("not sorted: sorting incorrect");
	// else
	// 	print_stack(&(box->a));
}
