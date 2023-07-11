/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:17:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/11 14:00:29 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_box	box;

	ft_bzero(&box, sizeof(t_box));
	if (argc >= 2)
	{
		parse_input(&box, argc, argv);
		if (elementcount(&box.a) <= 1)
			scope_error("single input");
	}
	else
		scope_error("invalid input");
	sort(&box);
	return (0);
}
