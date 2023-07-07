/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/07 14:44:53 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief sort three digits
** 312, 321, 213, 132, 231
** @param box.a input stack
*/
// void	sort_three(t_stack *box.a, t_type type)
// {
// 	int	hd;
// 	int	tl;
// 	int	md;

// 	hd = box.a->head->data;
// 	tl = box.a->tail->data;
// 	md = box.a->head->next->data;
// 	if (hd > md && hd > tl)
// 	{
// 		if (tl > md)
// 			return ((void)rotate(box.a, type));
// 		return ((void)swap(box.a, type), rev_rotate(box.a, type));
// 	}
// 	else if (hd < md && hd > tl)
// 		return ((void)rev_rotate(box.a, type));
// 	if (hd < tl)
// 		swap(box.a, type);
// 	if (hd < md)
// 		return ((void)rotate(box.a, type));
// }

// void	sort_five(t_box *stacks)
// {
// 	push(stacks, B);
// 	// print_stack(stacks->box.a);
// 	// print_stack_rev(stacks->box.a);
// 	// print_stack_rev(stacks->box.a);
// 	// check_links(stacks->box.a);
// 	// print_stack(stacks->b);
// 	// push(*stacks, B);
// 	// push(stacks->b, stacks->box.a, B);
// 	// sort_three(stacks->box.a, A);
// 	// push(*stacks, A);
// 	// while (!is_sorted(stacks->box.a))
// 	// 	rotate(stacks->box.a, A);
// 	// push(*stacks, A);
// 	// while (!is_sorted(stacks->box.a))
// 	// 	rotate(stacks->box.a, A);	
// }

	//sort using insertion and merge sort
	//limit number of operations
	//use stack b as temporary storage
	//use stack box.a as the return stack (sorted) & unsorted input stack
// void	sort(t_box *stacks, t_type type)
// {
// 	size_t	size;

// 	size = elementcount(stacks->box.a);
// 	// if (is_sorted(stacks->box.a))
// 	// 	return ;
// 	if (size == 2)
// 		swap(stacks->box.a, type);
// 	// else if (size <= 3)
// 	// 	sort_three(stacks->box.a, type);
// 	if (size == 5)
// 		sort_five(stacks);
// 	// if (!is_sorted(stacks->box.a))
// 	// 	scope_error("not sorted: sorting incorrect");
// }

void	populate(t_box *box, int new_data)
{
	t_node	*new;
	new = NULL;
	static int i = 0;
	printf("data [%d] %d\n", i, new_data);
	i++;
	new = malloc(sizeof(t_node));
	new->data = new_data;
	if (!(box->a.head))
	{
		new->next = new;
		new->prev = new;
		box->a.head = new;
		box->a.tail = new;
		box->a.type = A;
		return;
	}
	// a = &(box->a);
	else if ((box->a.head) == (box->a.tail))
	{
		new->next = box->a.head;
		box->a.head->prev = new;
		box->a.head->next = new;
		new->prev = box->a.head;
		box->a.tail = new;
		box->a.tail->next = box->a.head;
		box->a.tail->prev = box->a.head;
		return;
	}
	else
	{
		box->a.head->prev = new;
		box->a.tail->next = new;
		new->prev = box->a.tail;
		new->next = box->a.head;
		box->a.tail = new;
		return;
	}
}

void	parse_input(t_box *box, int argc, char **argv)
{
	// t_stack	*stack_a;
	char	**tmp;
	int		i;
	int		ii;

	// stack_a = &(box->a);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		ii = -1;
		// if (!tmp[0])
		// 	scope_error("tmp conversion error");
		while (tmp[++ii])
		{
			// if (i == 1 && validate_input(tmp[ii]))
			populate(box, ft_atoi(tmp[ii]));
			// else if (validate_input(tmp[ii]) && check_duplicate(stack))
			// 	populate(stack, ft_atoi(tmp[ii]));
			// else
			// 	scope_error("stack contains non-numeric values");
		}
		arr_free(tmp);
	}
}

void	receive(t_box *box)
{
	t_stack	*a;
	a = &(box->a);
	box->a.head->data = 84;
	t_node	*new;
	new = NULL;
	new = malloc(sizeof(t_node));
	new->data = 21;
	new->next = box->a.head;
	new->prev = box->a.head;
	new = box->a.tail;
	// box->a.head->next = box->a.tail;
	a->head->next = a->tail;
}

void	init_box(t_box	*box, int new_data)
{
	t_node	*test;
	test = NULL;
	test = malloc(sizeof(t_node));
	test->next = test;
	test->prev = test;
	box->a.head = test;
	box->a.tail = test;
	test->data = new_data;
	
}

int	main(int argc, char *argv[])
{
	t_box	box;
	ft_bzero(&box, sizeof(t_box));
	// printf("sizeof tbox %lu\n", sizeof(t_box));
	// box.a.head = NULL;
	// box.a.tail = NULL;
	// box.b.head = NULL;
	// box.b.tail = NULL;
	int	i;
	i = 0;
	// init_box(&box, 1);
	// box.a.type = A;
	if (argc >= 2)
	{
		parse_input(&box, argc, argv);
	}
	// t_node	*test;
	// test = box.a.head;
	// // int printed=0;
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
	printf("\n(head) %d\n", box.a.head->data);
	printf("\n(tail) %d\n", box.a.tail->data);
	// printf("%d, %s", argc, argv[1]);
	// t_stack *a = &(box.a);
	// receive(&box);
	// printf("\n%d\n", box.a.tail->data);
	return (0);
}
