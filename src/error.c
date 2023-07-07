/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:23:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/07 18:17:40 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scope_error(char *msg)
{
	ft_printf("\033[1;31m Error: %s\033[1;0m\n", msg);
	exit(1);
}

void	scope_success(char *msg, t_stack *stack)
{
	print_stack(stack);
	print_stack_rev(stack);
	ft_printf(" ⬆️ Checked ⬆️ \033[1;32m%s\033[1;0m", msg);
	ft_printf(" \033[1;32m\xE2\x9C\x93\033[1;0m\n");
}
