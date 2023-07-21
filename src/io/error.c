/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:23:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 14:24:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	own_error(char *msg)
// {
// 	ft_printf("\033[1;31m Error: %s\033[1;0m\n", msg);
// 	exit(1);
// }

void	error(t_box *box)
{
	write(2, "Error\n", 6);
	free_stack(&(box->a));
	free_stack(&(box->b));
	exit(1);
}

// void	error_msg(char *msg, t_box *box)
// {
// 	ft_printf("%s\n", msg);
// 	error(box);
// }

// void	scope_success(char *msg, t_stack *stack)
// {
// 	print_stack(stack);
// 	print_stack_rev(stack);
// 	ft_printf(" ⬆️ Checked ⬆️ \033[1;32m%s\033[1;0m", msg);
// 	ft_printf(" \033[1;32m\xE2\x9C\x93\033[1;0m\n");
// }
