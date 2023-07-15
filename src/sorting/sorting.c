/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/15 19:09:30 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_chunks(t_box *box)
{
	t_node	*current;

	current = box->a.head;
	while (current)
	{
		ft_printf("chunk [%d][%d]: %d\n", \
		current->chunk, current->index, current->data);
		current = current->next;
		if (current == box->a.head)
			break ;
	}
}

void	assign_chunks(t_box *box, t_vals *c)
{
	t_node	*current;

	current = box->a.head;
	while (current)
	{
		c->max = c->size * c->id;
		if (current->index <= c->max)
			current->chunk = c->id;
		else if (current->index >= c->max)
		{
			c->tmp_size = c->max;
			c->tmp_id = c->id;
			while (current->index > c->tmp_size && c->tmp_id < c->nbr)
			{
				c->tmp_size += c->size;
				c->tmp_id++;
			}
			current->chunk = c->tmp_id;
		}
		current = current->next;
		if (current == box->a.head)
			break ;
	}
}

void	rotate_high(t_box *box, t_type type)
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
	tmp = find_highest(stack);
	tmp2 = tmp - 1;
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


// void	sort_chunks(t_box *box)
// {
// 	while (box->a.head->index < ((int)box->a.size) - 5)
// 	{
// 		pb(box);
// 		if (box->a.size <= 5 && box->a.head->index > ((int)box->a.size) - 6)
// 			return ((void)sort_five(box));
// 		else
// 			ra(box);
// 	}
	
// }

	// if (box->a.size % 5 == 0)
void	define_chunks(t_box *box)
{
	t_vals		chunks;

	chunks.id = 1;
	if (box->a.size <= 100)
		chunks.nbr = 3;
	else if (box->a.size <= 200)
		chunks.nbr = 5;
	else if (box->a.size <= 500)
		chunks.nbr = 7;
	else
		chunks.nbr = 10;
	chunks.size = (((int)box->a.size) / chunks.nbr);
	assign_chunks(box, &(chunks));
	print_chunks(box);
	// sort_chunks(box);
}

void	sort(t_box *box)
{
	index_box(box);
	if (is_sorted(&(box->a)))
		return ;
	if (box->a.size == 2)
		sa(box);
	else if (box->a.size == 3)
		sort_three(box);
	else if (box->a.size <= 5)
		sort_five(box);
	else if (box->a.size > 5)
		define_chunks(box);
	if (!is_sorted(&(box->a)))
	{
		print_stack(&(box->a));
		print_stack_rev(&(box->a));
		print_stack(&(box->b));
		print_stack_rev(&(box->b));
		scope_error("not sorted: sorting incorrect");
	}
}

	// else
	// 	print_stack(&(box->a));
	// else if (box->a.size == 500)
	// 		sort
	// else
	// 	sort_huge(box);
