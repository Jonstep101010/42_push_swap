/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:34:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 16:33:35 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tofree;
	int		size;
	int		i;

	i = 0;
	size = elementcount(stack);
	tmp = stack->head;
	while (i < size)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
		i++;
	}
}
