/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:27:56 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/19 15:37:40 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* @brief display values inside sorted stack
** @param a return stack*/
void	display_return(t_stack *a)
{
	t_stack	*t_i;

	t_i = a->head;
	ft_printf("\n");
	while (t_i != a->tail)
	{
		ft_printf("%d ", t_i->data);
		t_i = t_i->next;
	}
	if (t_i == a->tail)
		ft_printf("%d\n", t_i->data);
}
