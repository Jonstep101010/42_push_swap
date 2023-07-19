/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/19 18:30:08 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_chunks(t_box *box)
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
} */




//function to start from biggest index/boxsize checking if decrementation matches
bool	is_index_sort_a(t_box *box)
{
	int	lowest;
	t_node	*current;

	lowest = (int) box->size + 1;
	current = box->a.tail;
	while (current != box->a.head)
	{
		if (box->a.tail->index != (int)box->size)
			error(box);
		if (current->index < lowest)
			lowest = current->index;
		else
			return (false);
		if (current->prev == box->a.head)
		{
			if (current->prev->index < lowest)
				lowest = current->prev->index;
			else
				return (false);
		}
		current = current->prev;
	}
	return (true);
}

//function to calculate which is the highest number that can go back into stack a, so that only ra/rra or sa are needed


int		find_value_b(t_box *box)
{
	t_node	*current;
	int	count1;
	int	count2;
	int	calc1;
	int	calc2;

	count1 = 0;
	count2 = 0;
	calc1 = -2;
	calc2 = -2;
	current = box->b.head;
	// if (!is_index_sort_a(box) || box->a.tail->index != (int)box->size)
	// 	return (-1);
	while (current->index != box->a.head->index - 1 && count1++ <= (int)box->b.size)
		current = current->next;
	if (current->index == box->a.head->index - 1)
		calc1 = calc_moves(&(box->b), current);
	// if (current->index < find_highest(&(box->b)))
	// 	return (-2);
	current = box->b.head;
	while (current->index != box->a.head->index - 2 && count1++ <= (int)box->b.size)
		current = current->prev;
	if (current->index == box->a.head->index - 2)
		calc1 = calc_moves(&(box->b), current);
	if (calc1 == -1 || calc2 == -1 || calc1 == -2 || calc2 == -2)
		return (-1);
	if (count1 <= count2)
		return (calc1);
	return (calc2);
}

//know more about function pointers!!
bool	push_member(t_box *box, t_vals *vals)
{
	int	direction;

	if (!(box->a.head))
		return (false);
	direction = find_chunk_member(box, vals);
	vals->max = vals->size * vals->id;
	if (direction == -1 && vals->id < vals->max)
		return (false);
	if (!&(box->a) || !(box->a.head))
		return (false);
	while (direction == 1 && box->a.head->chunk != vals->id)
		ra(box);
	while (direction == 0 && box->a.head->chunk != vals->id)
		rra(box);
	if (box->a.head->chunk == vals->id)
		pb(box);
	return (true);
}

bool	rotate_highest_b(t_box *box)
{
	int	direction;

	t_node	*current;
	current = box->b.head;
	// if (!&(box->b.head))
	// 	return (false);
	// direction = find_value_b(box);
	t_node	*target;
	target = find_highest(&(box->b));
	// ft_printf("highest %d\n", target->index);
	direction = calc_moves(&(box->b), target);
	// if (direction == -1)
	// 	return (false);
	// if (direction == -2)
	// {
	// 	if (box->b.tail == target)
	// 		return (rrb(box), true);
	// 	// else
	// 	// {
	// 	// 	while (current->index != target && current != box->b.tail)
	// 	// 		current = current->next;
	// 	// 	if (current->index == target)
	// 	// 		direction = calc_moves(&(box->b), current);
	// 	// 	while (direction == 1 && box->b.head->index != target)
	// 	// 		rb(box);
	// 	// 	while (direction == 0 && box->b.head->index != target)
	// 	// 		rrb(box);
	// 	// }
	// }
	while (direction == 1 && (box->b.head->index != target->index))
		rb(box);
	while (direction == 0 && (box->b.head->index != target->index))
		rrb(box);
	return (true);
}

void	push_chunks(t_box *box, t_vals *chunks)
{
	int	i;

	chunks->id = 1;
	while (chunks->id < chunks->nbr && &(box->a.head))
	{
		i = 0;
		chunks->max = chunks->size * chunks->id;
		while (++i <= chunks->max && push_member(box, chunks) == true)
		{
			if (chunks->id % 2 == 0 && chunks->nbr > 3)
				rb(box);
		}
		chunks->id++;
	}
	while (box->a.size > 5)
	{
		if (box->a.head->index < (int)box->size - 4)
			pb(box);
		else
		{
			ft_printf("[%d] %d\n", box->a.head->index, box->a.head->data);
			ra(box);
		}
	}
	//sort 5 biggest numbers
	if (box->a.size == 5 && chunks->nbr)
		sort_five(box);
	// print_stack(&(box->a));
	// print_stack(&(box->b));
	while (box->b.head)
	{
		// if (box->b.head && box->b.head->index == box->a.head->index - 1 && box->a.tail->index == (int)box->size)
		// 	pa(box);
		// else if (is_index_sort_a(box))
		if (rotate_highest_b(box))
			pa(box);
	}
	// print_stack(&(box->a));
	// print_stack(&(box->b));
	// chunks->nbr = box->a.tail->chunk;
	// chunks->id = box->a.tail->chunk;
	// if (is_index_sort_a(box))
	// 	ft_printf("index sorted\n");
	// else
	// 	ft_printf("index not sorted\n");
	// while (box->b.head->chunk == chunks->id || box->b.tail->chunk == chunks->id)
	// {
	// 	if (box->b.head->index == box->a.head->index - 1 && is_sorted(&(box->a)))
	// 		pa(box);
	// 	// if (box->b.head->index == box->a.head->index - 2 )
	// 	// if (box->b.head->chunk == chunks->id && box->a.tail->chunk == chunks->id)
	// 	// {
	// 	// 	//make sure to not get into infinite loop - prefer range with fewest rotates & bring 
	// 	// 	//to top if necessary/possible
	// 	// }
	// 	// if (box->b.tail->chunk == chunks->id)
	// 	// if (box->b.head->chunk == chunks->id)
	// 	// {
			
	// 	// }
	// }
	// if (box->a.size == 5)
	// 	sort_five(box);
	// if (box->a.size == 2 && !is_sorted(&(box->a)) && box->b.head->index < box->a.head->index)
	// 	rr(box);
	// while (is_sorted(&(box->a)) && (box->b.head->index == box->a.head->index -1 || box->b.tail->index == box->a.head->index -1))
	// {
	// 	if (box->b.head->index >= box->a.head->index -2)
	// 		pa(box);
	// 	else if (box->a.tail->index == box->a.head->index -1)
	// 	{
	// 		rrb(box);
	// 		pa(box);
	// 	}
	// 	else if (box->b.head->index > box->a.head->index - 50)
	// 		rb(box);
	// }
	// // sort_five(box);
	// while (box->b.head->index >= (int) box->size -1)
	// 	pa(box);
}
	// box->a.head->index = 6;


// print_chunks(box);
void	define_chunks(t_box *box)
{
	t_vals		chunks;

	chunks.id = 1;
	if (box->a.size <= 100)
		chunks.nbr = 5;
	else if (box->a.size <= 200)
		chunks.nbr = 5;
	else if (box->a.size <= 500)
		chunks.nbr = 7;
	else
		chunks.nbr = 30;
	chunks.size = (((int)box->a.size) / chunks.nbr);
	assign_chunks(box, &(chunks));
	push_chunks(box, &chunks);
	// while (box->b.head->chunk == chunks.nbr && box->b.head->index <= box->a.head->index - 3)
	// 	rb(box);
	// pa(box);
	// if (box->a.head->index + 1 == box->a.head->next->index)
		
	// if (chunks.nbr == 3)
	// 	sort_big(box);
	// print_stack(&(box->a));
	// print_stack(&(box->b));
	if (!is_sorted(&(box->b)))
		error(box);
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
		ft_printf("box a\n");
		print_stack(&(box->a));
		print_stack_rev(&(box->a));
		ft_printf("box b\n");
		print_stack(&(box->b));
		print_stack_rev(&(box->b));
		error(box);
		scope_error("not sorted: sorting incorrect");
	}
}

//