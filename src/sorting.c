/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/09 19:56:22 by jschwabe         ###   ########.fr       */
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
	int	hd;
	int	tl;
	int	md;

	type = stack->type;
	hd = stack->head->data;
	tl = stack->tail->data;
	md = stack->head->next->data;
	if (is_sorted(stack))
		return;
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

void	sort_five(t_box *box)
{
	t_node	*current;
	size_t	cost;

	cost = 0;
	current = box->a.head;
	while (current != box->a.tail && cost < elementcount(&(box->a)) - 2)
	{
		if (current->index == 1)
		{
			break;
		}
		cost++;
		current = current->next;
	}
	printf("cost %zu\n", cost);
	// push(box, B);
	// push(box, B);
	// print_index(&(box->a));
	// ft_printf("--------now: box.b\n");
	// print_index(&(box->b));
	// sort_three(&(box->a));
	// size_t	stop;
	// stop = 1;
	// if (box->b.head->index > box->a.tail->index || box->b.tail->index > box->a.tail->index)
	// {
	// 	while (!(box->b.head->index + 1 == box->a.head->index) && stop < elementcount(&(box->a)))
	// 	{
	// 		stop++;
	// 		rev_rotate(&(box->a), A);
			
	// 	}
	// 	stop = 0;
	// }
	// push(box, A);
	// while (!is_sorted(&(box->a)) && stop < elementcount(&(box->a)))
	// {
		
	// 	stop++;
	// 	rotate(&(box->a), A);
	// }
	// print_stack(&(box->a));
	// push(box, A);
	// int	size;
	// size = (int) elementcount(&(box->a));
	// if (box->a.head->index == size)
	// 	rotate(&(box->a), A);
	// else if (box->a.head->index == size -1)
	// {
	// 	rev_rotate(&(box->a), A);
	// 	swap(&(box->a), A);
	// 	rotate(&(box->a), A);
	// 	rotate(&(box->a), A);
	// }
	// else
	// 	swap(&(box->a), A);
	// if (!is_sorted(&(box->a)))
	// {
	// 	if (box->a.head->next->index > box->a.head->next->next->index)
	// 	{
	// 		rotate(&(box->a), A);
	// 		swap(&(box->a), A);
	// 		rev_rotate(&(box->a), A);
	// 	}
	// }
	// print_stack(&(box->a));
	// t_node	*pushed;
	// pushed = box->a.head;
	// int	next_cost;
	// int	prev_cost;
	// next_cost = 0;
	// prev_cost = 0;
	// if (!is_sorted(&(box->a)))
	// {
	// 	if (pushed->index < pushed->prev->index && pushed->index > pushed->next->next->index)
	// 	{
			
	// 	}
	// }
	// t_node	*popped;
	// if (box->a.head
	// {
	// 	printf("mama");
	// 	push(box, B);
	// 	print_stack(&(box->a));
	// 	push(box, B);
	// 	print_stack(&(box->a));
	// 	print_stack(&(box->b));
	// 	sort_three(&(box->a));
	// 	push(box, A);
	// 	push(box, A);
	// 	if (!is_sorted(&(box->a)))
	// 		swap(&(box->a), A);
	// }
	
	// size_t	counter = 1;
	// t_node	*pushed;
	// pushed = box->a.head;
	
	print_stack(&(box->a));
	print_stack_rev(&(box->a));
	if (!is_sorted(&(box->a)))
		scope_error("not sorted: algo");
	}

	// sort using insertion and merge sort
	// limit number of operations
	// use stack b as temporary storage
	// use stack box.a as the return stack (sorted) & unsorted input stack
void	sort(t_box *box)
{
	size_t	size;

	size = index_box(box);
	if (is_sorted(&(box->a)))
		return ;
	if (size == 2)
		swap(&(box->a), A);
	else if (size <= 3)
		sort_three(&(box->a));
	if (size <= 5)
		sort_five(box);
	if (!is_sorted(&(box->a)))
		scope_error("not sorted: sorting incorrect");
	else
		print_stack(&(box->a));
}
