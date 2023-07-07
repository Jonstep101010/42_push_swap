/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:14:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/07 18:17:16 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief checks if stack is sorted
** @return true/false
*/
bool	is_sorted(t_stack *stack)
{
	t_node	*t_i;

	if (!(stack->head->next))
		return (true);
	t_i = stack->head;
	while (t_i->next != stack->head)
	{
		if (t_i->data > t_i->next->data)
			return (false);
		t_i = t_i->next;
	}
	return (true);
}

/*
** @brief checks links in stack (next and prev)
** not sure if this is necessary/working
*/
bool	check_links(t_stack *stack)
{
	t_node	*current;

	if (!elementcount(stack))
		return (ft_printf("\ncheck: Empty!\n"), false);
	current = stack->head;
	while (current->next != stack->head)
	{
		if (current->next->prev != current)
			return (ft_printf("\nbroken link - %d\n", current->data), false);
		current = current->next;
	}
	return (true);
}

/*
** @brief checks for errors in stack
** @return  true false/printing error
*/
bool	check_stack(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	head = stack->head;
	tail = stack->tail;
	if (head->prev != tail)
		scope_error("tail is not head->prev");
	if (tail->next != head)
		scope_error("head is not tail->next");
	if (tail->next == tail || head->prev == head || head == tail)
		scope_error("stack is of only one item!");
	if (tail->prev->next != tail || tail->next->prev != tail
		|| head->prev->next != head)
		scope_error("tail data is incorrect!");
	if (head->prev->next != head || head->next->prev != head
		|| head->prev->next != head)
		scope_error("head data is incorrect!");
	scope_success("head and tail position", stack);
	return (true);
}


