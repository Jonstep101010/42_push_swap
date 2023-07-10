/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/10 19:50:58 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief checks for duplicates in stack
*/
static bool	check_duplicate(t_stack *box)
{
	t_node	*t_i;
	t_i = box->head;
	while (t_i->next != box->head)
	{
		if (t_i->data == t_i->next->data)
			return (scope_error("stack contains duplicate values"), false);
		t_i = t_i->next;
	}
	return (true);
}

void	populate(t_box *box, int new_data)
{
	t_node	*new;
	new = ft_calloc(1, sizeof(t_node));
	new->data = new_data;
	if (!(box->a.head))
	{
		new->next = new;
		new->prev = new;
		box->a.head = new;
		// box->a.tail = new;
		box->a.type = A;
	}
	else if ((box->a.head) == (box->a.tail))
	{
		new->next = box->a.head;
		box->a.head->prev = new;
		box->a.head->next = new;
		new->prev = box->a.head;
		// box->a.tail = new;
		// box->a.tail->next = box->a.head;
		// box->a.tail->prev = box->a.head;
	}
	else
	{
		box->a.head->prev = new;
		box->a.tail->next = new;
		new->prev = box->a.tail;
		new->next = box->a.head;
		// box->a.tail = new;
	}
	box->a.tail = new;
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
			scope_error("tmp conversion error");
		while (tmp[++ii])
		{
			if (ii == 0 && validate_input(tmp[ii]))
				populate(box, ft_atoi(tmp[ii]));
			else if (validate_input(tmp[ii]) && check_duplicate(&(box->a)))
				populate(box, ft_atoi(tmp[ii]));
			else
				scope_error("stack contains non-numeric values");
		}
		arr_free(tmp);
	}
}
