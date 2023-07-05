/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/05 19:00:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief sort three digits
** 312, 321, 213, 132, 231
** @param a input stack
*/
void	sort_three(t_stack *a, t_type type)
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
			return ((void)rotate(a, type));
		return ((void)swap(a, type), rev_rotate(a, type));
	}
	else if (hd < md && hd > tl)
		return ((void)rev_rotate(a, type));
	if (hd < tl)
		swap(a, type);
	if (hd < md)
		return ((void)rotate(a, type));
}

void	sort_five(t_box *stacks)
{
	push(stacks, B);
	print_stack(stacks->a);
	// print_stack_rev(stacks->a);
	// check_links(stacks->a);
	print_stack(stacks->b);
	// push(*stacks, B);
	// push(stacks->b, stacks->a, B);
	// sort_three(stacks->a, A);
	// push(*stacks, A);
	// while (!is_sorted(stacks->a))
	// 	rotate(stacks->a, A);
	// push(*stacks, A);
	// while (!is_sorted(stacks->a))
	// 	rotate(stacks->a, A);	
}

	//sort using insertion and merge sort
	//limit number of operations
	//use stack b as temporary storage
	//use stack a as the return stack (sorted) & unsorted input stack
void	sort(t_box *stacks, t_type type)
{
	size_t	size;

	size = elementcount(stacks->a);
	// if (is_sorted(stacks->a))
	// 	return ;
	if (size == 2)
		swap(stacks->a, type);
	// else if (size <= 3)
	// 	sort_three(stacks->a, type);
	if (size == 5)
		sort_five(stacks);
	// if (!is_sorted(stacks->a))
	// 	scope_error("not sorted: sorting incorrect");
}

int	main(int argc, char *argv[])
{
	t_box	stacks;
	t_type	type;
	type = A;
	

	if (argc >= 2)
	{
		stacks.a = parse_input(argc, argv);
		if (elementcount(stacks.a) < 2)
			scope_error("invalid input");
	}
	else
		scope_error("invalid input");
	display_return(stacks.a);
	sort(&stacks, type);
	display_return(stacks.a);
	display_return(stacks.b);
	return (0);
}

	// else if (size <= 5)
	// 	sort_five(a, b);
	// else
	// 	sort_large(a, b);
