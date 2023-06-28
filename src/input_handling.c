/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/28 22:51:28 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief checks if string is a valid integer
*/
static bool	int_format(const char *str)
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

/*
** @brief checks for duplicates in stack
*/
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

/*
** @brief checks if input is valid
*/
static bool	validate_input(const char *str)
{
	if (!int_format(str))
		return (false);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN) //needs long format
		return (false);
	//need to check duplicates as well
	return (true);
}

bool	parse_input(t_stack *stack, int argc, char **argv)
{
	char	**tmp;
	int		i;
	int		ii;

	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		ii = -1;
		if (!tmp[0])
			scope_error("tmp conversion error");
		while (tmp[++ii])
		{
			if (validate_input(tmp[ii]) && i == 1
				&& populate(stack, ft_atoi(tmp[ii])))
				stack->elements = 1;
			else if (validate_input(tmp[ii]) && check_duplicate(stack)
				&& populate(stack, ft_atoi(tmp[ii])))
				stack->elements++;
			else
				scope_error("stack contains non-numeric values");
		}
		arr_free(tmp);
	}
	return (true);
}
