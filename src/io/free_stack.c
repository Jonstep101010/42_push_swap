/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:34:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/12 13:58:33 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tofree;
	size_t	size;
	int		i;

	i = 0;
	size = elementcount(stack);
	tmp = stack->head;
	while (i < (int)size)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
		i++;
	}
}
