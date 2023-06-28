/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/28 11:52:18 by jschwabe         ###   ########.fr       */
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
static	bool	int_format(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_duplicate(t_stack *stack)
{
	t_stack	*t_i;
	t_i = stack->head;
	while (t_i->next != stack->head)
	{
		if (t_i->data == t_i->next->data)
			return (scope_error("stack contains duplicate values"), false);
		t_i = t_i->next;
	}
	return (true);
}

static	bool validate_input(const char *str)
{
	if (!int_format(str))
		return (false);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)//needs long format
		return (false);
	//need to check duplicates as well
	return (true);
}



void	parse_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	ii;
	char	**tmp;
	
	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		ii = -1;
		if (!tmp[0])
			scope_error("tmp conversion error");
		while (tmp[++ii])
		{
			if (validate_input(tmp[ii]) && i == 1)
			{
				populate(stack, ft_atoi(tmp[ii]));
				stack->elements = 1;
			}
			else if (validate_input(tmp[ii]) && check_duplicate(stack))
			{
				populate(stack, ft_atoi(tmp[ii]));
				stack->elements++;
			}
			else
				scope_error("stack contains non-numeric values");
		}
		arr_free(tmp);
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
