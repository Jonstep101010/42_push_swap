/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:19:07 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 20:36:15 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"
# include "libft.h"
# include "operations.h"

int		main(int argc, char *argv[]);

//input handling //

void	parse_input(t_box *box, int argc, char **argv);
void	populate(t_box *box, int new_data);
void	free_stack(t_stack *stack);

// //error handling //

void	scope_error(char *msg);
void	scope_success(char *msg, t_stack *stack);
void	error(t_box *box);

// utilities //

void	print_stack(t_stack *stack);
void	print_stack_rev(t_stack *stack);
bool	check_stack(t_stack *stack);
bool	check_links(t_stack *stack);

// stack sorting //

void	sort(t_box *box);
void	sort_three(t_box *box);
void	sort_five(t_box *box);
void	sort_big(t_box *box);

// sorting utils //

bool	is_sorted(t_stack *stack);
size_t	elementcount(t_stack *stack);
size_t	index_box(t_box *box);

// sorting calculations //

bool	calc_rot(t_stack *stack, int val);
void	rotate_top(t_box *box, t_type type);
int		find_lowest(t_stack *stack);
int		find_highest(t_stack *stack);

// manipulation //
// void	prepend(t_stack *stack, int new_data);
// void	append(t_stack *stack, int new_data);

#endif
