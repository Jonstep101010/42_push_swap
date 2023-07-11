/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:34:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/11 20:38:49 by jschwabe         ###   ########.fr       */
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
		ft_bzero(tofree, sizeof(t_node));
		free(tofree);
		i++;
	}
	printf("%i", i);
}