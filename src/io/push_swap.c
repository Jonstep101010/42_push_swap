/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:17:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 10:48:53 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* @brief display values inside sorted stack
** @param a return stack*/
void	display_return(t_stack *box)
{
	t_node	*t_i;

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

int	main(int argc, char *argv[])
{
	t_box	box;

	ft_bzero(&box, sizeof(t_box));
	if (argc >= 2)
	{
		parse_input(&box, argc, argv);
		if (elementcount(&box.a) <= 1)
		{
			free_stack(&(box.a));
			scope_error("single input");
		}
	}
	else
		scope_error("invalid input");
	sort(&box);
	free_stack(&(box.a));
	if (&(box.b) || box.b.head)
		free_stack(&(box.b));
	return (0);
}
