/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/05 09:35:08 by jschwabe         ###   ########.fr       */
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
** TODO: check for INT_MAX and INT_MIN using long
*/
static bool	validate_input(const char *str)
{
	if (!int_format(str))
		return (false);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (false);
	return (true);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	char	**tmp;
	int		i;
	int		ii;

	stack = NULL;
	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		ii = -1;
		if (!tmp[0])
			scope_error("tmp conversion error");
		while (tmp[++ii])
		{
			if (i == 1 && validate_input(tmp[ii]))
				stack = populate(stack, ft_atoi(tmp[ii]));
			else if (validate_input(tmp[ii]) && check_duplicate(stack))
				populate(stack, ft_atoi(tmp[ii]));
			else
				scope_error("stack contains non-numeric values");
		}
		arr_free(tmp);
	}
	return (stack);
}
