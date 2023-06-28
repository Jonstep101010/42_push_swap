/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/28 10:39:33 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	build_b(t_stack *stack)
// {
// 	t_stack	*new_item;
// 	t_stack	*last;

// 	new_item = malloc(sizeof(t_stack));
// 	if (!(stack->head))
// 	{
// 		new_item->next = new_item;
// 		new_item->prev = new_item;
// 		stack->head = new_item;
// 	}
// 	last = stack->head;
// 	new_item->next = stack->head;
// 	if (!(stack->head))
// 	{
// 		new_item->prev = new_item;
// 		stack->head = new_item;
// 	}
// 	while (last->next != stack->head)
// 		last = last->next;
// 	// while (last->prev != stack->head)
// 	// 	last = last->prev;
// 	last->next = new_item;
// 	new_item->prev = last;
// 	new_item->next->prev = new_item;
// 	stack->tail = stack->head->prev;
// }

void	check_input(t_stack *stack)
{
	t_stack	*t_i;

	t_i = stack->head;
	check_stack(stack);
	// printf("isdigit test %d\n", ft_isdigit(t_i->data=''));
	while (t_i->next != stack->head)
	{
		if (t_i->data == t_i->next->data)
			scope_error("stack contains duplicate values");
		// if (!(t_i->data >= '0') || (char)t_i->data > 57)
		// 	scope_error("stack contains non-numeric values");
		t_i = t_i->next;
	}
}

t_stack	parse_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	ii;
	char	**tmp;
	// int x;
	// int tmp;

	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		ii = -1;
		if (!tmp[0])
			scope_error("tmp conversion error");
		while (tmp[++ii])
		{
			if (ft_atoi(tmp[ii]) > INT_MAX || ft_atoi(tmp[ii]) < INT_MIN)
				scope_error("stack contains values outside of int range");
			populate(stack, ft_atoi(tmp[ii]));
		}
	}
	
	// while (argv[i + 1])
	// {
	// 	x = 0;
	// 	while (argv[i + 1][x++] != '\0')
	// 	{
	// 		if (argv[i + 1][x-1] == ' ' || argv[i + 1][x-1] == '-')
	// 			x++;
	// 		if (!(ft_isdigit(argv[i + 1][x-1])) && argv[i + 1][x-1] != ' ' && argv[i + 1][x-1] != '-')
	// 			scope_error("stack contains non-numeric values");
	// 	}
	// 	populate(stack, ft_atoi((ft_split(argv[i+1], ' ')[0])));
	// 	i++;
	// }
	// printf("%d", stack->tail->data);
	// if (elementcount(stack) != arr_len(argv))
	// {
	// 	while (argv[i] && argv[i][x] != '\0')
	// 	{
	// 		x = 0;
	// 		while (argv[i] && argv[i][x] != '\0' && argv[i][x] != '"' && argv[i][x] != ' ')
	// 			x++;
	// 		// if (!(ft_isdigit(argv[i][x+1])))
	// 		// 	scope_error("stack contains non-numeric values");
	// 		tmp = ft_atoi(ft_split(argv[i], ' ')[x]);
	// 		if (tmp != stack->tail->data)
	// 			populate(stack, tmp);
	// 		else
	// 			return (*stack);
	// 		i++;
	// 	}
	// }
	
	// while (i-- > 0)
	// 	build_b(&b);
	// return (b);
	return (*stack);
}

void	populate(t_stack *stack, int new_data)
{
	t_stack	*new_item;
	t_stack	*last;

	new_item = malloc(sizeof(t_stack));
	if (!(stack->head))
	{
		new_item->data = new_data;
		new_item->next = new_item;
		new_item->prev = new_item;
		stack->head = new_item;
	}
	last = stack->head;
	new_item->data = new_data;
	new_item->next = stack->head;
	if (!(stack->head))
	{
		new_item->prev = new_item;
		stack->head = new_item;
	}
	while (last->next != stack->head)
		last = last->next;
	last->next = new_item;
	new_item->prev = last;
	new_item->next->prev = new_item;
	stack->tail = stack->head->prev;
}
