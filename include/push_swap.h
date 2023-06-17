/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:19:07 by jschwabe          #+#    #+#             */
/*   Updated: 2023/06/17 14:44:20 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

# define SA "sa"
# define SB "sb"
# define SS "ss"

typedef struct t_stack
{
	struct t_stack	*head;
	struct t_stack	*tail;
	int				data;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

int		main(int argc, char *argv[]);

//input handling//
t_stack	parse_input(t_stack *stack, char **argv);
void	populate(t_stack *stack, int new_data);

//operations//
void	swap(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

//list functions//
void	append(t_stack *stack, int new_data);
void	prepend(t_stack *stack, int new_data);

//list checking//
void	print_stack(t_stack *stack);
bool	check_stack(t_stack *stack);

//error handling//
void	scope_error(char *msg);
void	scope_success(char *msg, t_stack *stack);
#endif
