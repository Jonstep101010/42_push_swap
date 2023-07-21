/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 16:32:43 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief checks for duplicates in stack
*/
static bool	check(t_stack *a, int data)
{
	t_node	*t_i;

	a->size = elementcount(a);
	if (a->size == 1 || !(a->head))
		return (true);
	t_i = a->head;
	while (t_i != a->tail)
	{
		if (t_i->data == data)
		{
			return (false);
		}
		t_i = t_i->next;
	}
	return (true);
}

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
** @brief checks if input is valid
*/
static bool	validate_input(t_stack *a, const char *str)
{
	if (!int_format(str))
		return (false);
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (false);
	if (!check(a, ft_atoi(str)))
		return (false);
	return (true);
}

void	parse_input(t_box *box, int argc, char **argv)
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
			error(box);
		while (tmp[++ii])
		{
			if (validate_input(&(box->a), tmp[ii]))
				populate(box, ft_atoi(tmp[ii]));
			else
				error(box);
		}
		arr_free(tmp);
	}
}
