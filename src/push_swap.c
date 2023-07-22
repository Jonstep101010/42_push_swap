/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:17:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/22 16:26:20 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_return(t_stack *box);

int	main(int argc, char *argv[])
{
	t_box	box;

	ft_bzero(&box, sizeof(t_box));
	if (argc < 2)
		return (EXIT_FAILURE);
	parse_input(&box, argc, argv);
	if (elementcount(&box.a) == 1)
		return (0);
	box.size = elementcount(&(box.a));
	sort(&box);
	display_return(&(box.a));
	free_stack(&(box.a));
	if (&(box.b) || box.b.head)
		free_stack(&(box.b));
	return (EXIT_SUCCESS);
}

/* @brief display values inside sorted stack
** @param a return stack*/
void	display_return(t_stack *box)
{
	t_node	*t_i;

	if (!is_sorted(box))
		ft_printf("not sorted!\n");
	if (!box->head || !box->tail)
		return ;
	t_i = box->head;
	ft_printf("\n");
	while (t_i != box->tail)
	{
		ft_printf("%d ", t_i->data);
		t_i = t_i->next;
	}
	if (t_i == box->tail)
		ft_printf("%d\n", t_i->data);
}

// void	prepend(t_stack *stack, int new_data)
// {
// 	t_node	*new_item;

// 	new_item = ft_calloc(1, sizeof(t_node));
// 	new_item->data = new_data;
// 	new_item->next = stack->head;
// 	if (stack->head == NULL)
// 	{
// 		new_item->prev = new_item;
// 		new_item->next = new_item;
// 		stack->head = new_item;
// 		stack->tail = new_item;
// 		return ;
// 	}
// 	new_item->prev = stack->tail;
// 	new_item->prev->next = new_item;
// 	stack->head = new_item;
// }

// void	append(t_stack *stack, int new_data)
// {
// 	t_node	*new_item;
// 	t_node	*last;

// 	new_item = ft_calloc(1, sizeof(t_node));
// 	new_item->data = new_data;
// 	new_item->next = stack->head;
// 	if (stack->head == NULL)
// 	{
// 		new_item->prev = new_item;
// 		new_item->next = new_item;
// 		stack->head = new_item;
// 		stack->tail = new_item;
// 		return ;
// 	}
// 	last = stack->tail;
// 	last->next = new_item;
// 	new_item->prev = last;
// 	new_item->next->prev = new_item;
// 	stack->tail = new_item;
// }
