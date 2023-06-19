/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:14:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/19 13:34:47 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief 
** 
** @param stack address of stack to print
*/
void	print_stack(t_stack *stack)
{
	t_stack	*t_i;

	if (!stack->head)
		return ((void)ft_printf("\n!EMPTY/BROKEN!\n"));
	t_i = stack->head;
	while (t_i != stack->head->prev)
	{
		if (t_i == stack->head)
			ft_printf("\n(head) %d -> ", t_i->data);
		else
			ft_printf("%d -> ", t_i->data);
		if (t_i->next->next == stack->head)
			ft_printf("%d (tail)\n", t_i->next->data);
		t_i = t_i->next;
	}
	if (t_i == stack->head->prev && t_i == stack->head)
		ft_printf("\n(single element) %d\n", t_i->data);
}

void	print_stack_rev(t_stack *stack)
{
	t_stack	*t_i;

	if (!stack->tail)
		return ((void)ft_printf("\n!EMPTY/BROKEN!\n"));
	t_i = stack->tail;
	while (t_i != stack->head)
	{
		if (t_i == stack->tail)
			ft_printf("\n(tail) %d -> ", t_i->data);
		else
			ft_printf("%d -> ", t_i->data);
		if (t_i->prev->prev == stack->tail)
			ft_printf("%d (head)\n", t_i->prev->data);
		t_i = t_i->prev;
	}
	if (t_i == stack->head->prev && t_i == stack->head)
		ft_printf("\n(single element) %d\n", t_i->data);
}

bool	check_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*t_i;

	head = stack->head;
	tail = stack->tail;
	t_i = stack->head;
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

size_t	elementcount(t_stack *stack)
{
	t_stack	*t_i;
	size_t	i;

	if (!stack || !stack->head)
		return (0);
	if (stack->head == stack->tail)
		return (1);
	t_i = stack->head->next;
	i = 2;
	while (t_i->next != stack->head)
	{
		t_i = t_i->next;
		i++;
	}
	return (i);
}
