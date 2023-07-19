/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:07:33 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/19 14:55:53 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief calculate rotation to get to value
**
** @return true rotate
** @return false rev_rotate
*/
bool	calc_rot(t_stack *stack, int val)
{
	t_node	*current;
	int		tmp;

	stack->size = elementcount(stack);
	tmp = 0;
	current = stack->head;
	while (tmp < (int)(stack->size / 2))
	{
		if (current->index == val)
			return (true);
		current = current->next;
		tmp++;
	}
	current = stack->tail;
	while (tmp < (int)(stack->size))
	{
		if (current->index == val)
			return (false);
		current = current->prev;
		tmp++;
	}
	return (false);
}

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
	// t_node	*current;

	// current = box->a.head;
	// while (current->index != find_highest(&(box->a)) && current->index > 3)
	// {
	// 	current = current->next;
	// }
	// int	direction;

	// direction = calc_moves(&(box->a), current);
//13 29 15 9 92 83 65 68 7 89 78 81 88 32 24 25 61 58 62 14 35 34 75 64 30 27 60 53 90 38 69 23 56 55 48 5 47 41 4 77 20 82 21 46 91 98 52 86 72 93 42 8 49 71 33 74 2 16 12 3 57 19 17 84 85 36 22 6 31 94 40 44 80 43 96 11 26 66 37 63 97 1 70 95 54 87 79 73 67 99 51 76 45 28 59 10 39 100 18 50 