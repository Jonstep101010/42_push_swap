/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:17:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/05 10:40:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_box	stacks;

	if (argc >= 2)
	{
		stacks.a = parse_input(argc, argv);
		if (elementcount(stacks.a) < 2)
			scope_error("invalid input");
	}
	else
		scope_error("invalid input");
	sort(stacks.a);
	display_return(stacks.a);
	return (0);
}

