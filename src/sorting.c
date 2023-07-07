/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/07 19:08:20 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief checks if stack is empty, counts elements
*/
size_t	elementcount(t_stack *stack)
{
	t_node	*t_i;
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

// char	type(int type)
// {
// 	if (type == A)
// 		return ('a');
// 	else if (type == B)
// 		return ('b');
// 	else
// 		return ('n');
// }


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
	if (hd < md && md < tl)
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
	push(box, B);
	push(box, B);
	// print_stack(stacks->box.a);
	// print_stack_rev(stacks->box.a);
	// print_stack_rev(stacks->box.a);
	// check_links(stacks->box.a);
	// print_stack(stacks->b);
	// push(*stacks, B);
	// push(stacks->b, stacks->box.a, B);
	sort_three(&(box->a));
	push(box, A);
	while (!is_sorted(&(box->a)))
		rotate(&(box->a), A);
	push(box, A);
	while (!is_sorted(&(box->a)))
		rotate(&(box->a), A);
	// push(*stacks, A);
	// while (!is_sorted(stacks->box.a))
	// 	rotate(stacks->box.a, A);	
}

	// sort using insertion and merge sort
	// limit number of operations
	// use stack b as temporary storage
	// use stack box.a as the return stack (sorted) & unsorted input stack
void	sort(t_box *box)
{
	size_t	size;

	size = elementcount(&(box->a));
	if (is_sorted(&(box->a)))
		return ;
	if (size == 2)
		swap(&(box->a), A);
	else if (size <= 3)
		sort_three(&(box->a));
	if (size == 5)
		sort_five(box);
	if (!is_sorted(&(box->a)))
		scope_error("not sorted: sorting incorrect");
}


	// printf("sizeof tbox %lu\n", sizeof(t_box));
	// box.a.head = NULL;
	// box.a.tail = NULL;
	// box.b.head = NULL;
	// box.b.tail = NULL;
	// init_box(&box, 1);
	// box.a.type = A;
int	main(int argc, char *argv[])
{
	t_box	box;
	ft_bzero(&box, sizeof(t_box));
	if (argc >= 2)
	{
		parse_input(&box, argc, argv);
		if (elementcount(&box.a) <= 1)
			scope_error("single input");
	}
	else
		scope_error("invalid input");
	// printf("\n(head) %d\n", box.a.head->data);
	// printf("\n(tail) %d\n", box.a.tail->data);
	// // push(&box, B);
	// rotate(&(box.a), A);
	// rev_rotate(&(box.a), A);
	// swap(&(box.a), A);
	// ft_printf("- - - - - -");
	sort(&box);
	// t_node	*test;
	// test = box.a.head;
	// int	i;
	// i = 0;
	// // // int printed=0;
	// while (test->next != box.a.head)
	// {
	// 	if (test == box.a.head)
	// 		printf("\ndata [%d], value %d\n", i, test->data);
	// 	test = test->next;
	// 	i++;
	// 	printf("\ndata [%d], value %d\n", i, test->data);
	// }
	// test = box.a.tail;
	// while (test->prev != box.a.tail)
	// {
	// 	if (test == box.a.tail)
	// 		printf("\ndata [%d], value %d\n", i, test->data);
	// 	test = test->prev;
	// 	i++;
	// 	printf("\ndata [%d], value %d\n", i, test->data);
	// }
	// printf("\n(head) %d\n", box.a.head->data);
	// printf("\n(tail) %d\n", box.a.tail->data);
	ft_printf("\n[head] %d", box.a.head->data);
	ft_printf("\n[next] %d", box.a.head->next->data);
	ft_printf("\n[tail] %d", box.a.tail->data);
	print_stack(&(box.a));
	print_stack_rev(&(box.a));
	// printf("\nbox.b.head %d", box.b.head->data);
	// push(&box, A);
	// printf("\n(head) %d\n", box.a.head->data);
	// printf("\n(tail) %d\n", box.a.tail->data);
	// if (box.b.head)
	// 	printf("\nbox.b.head %d", box.b.head->data);
	return (0);
}


