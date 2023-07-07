/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:19:07 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/07 18:32:22 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

typedef enum e_type
{
	A = 0,
	B = 1,
	AB = 2
}t_type;

// struct s_node 
// {
// 	int				data;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// };

// typedef	struct s_node t_node;

// typedef int t_integer;
// t_integer number = 0;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				type;
}	t_stack;

typedef struct s_box
{
	struct s_stack	a;
	struct s_stack	b;
}	t_box;

int		main(int argc, char *argv[]);

//input handling//
void	parse_input(t_box *box, int argc, char **argv);

// //error handling//
void	scope_error(char *msg);

// //operations//
void	push(t_box *box, t_type type);
void	rotate(t_stack *stack, t_type type);
void	rotate_both(t_box *box);
void	rev_rotate(t_stack *stack, t_type type);
void	rev_rotate_both(t_box *box);
void	swap(t_stack *stack, t_type type);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

// //list functions//
// void	append(t_stack *stack, int new_data);
// void	prepend(t_stack *stack, int new_data);

// //stack sorting//
size_t	elementcount(t_stack *stack);
// void	sort(t_box *stacks, t_type type);
void	sort_three(t_stack *stack);

// /*list checking*/

void	print_stack(t_stack *stack);
void	print_stack_rev(t_stack *stack);
bool	check_stack(t_stack *stack);
bool	is_sorted(t_stack *stack);
// size_t	elementcount(t_stack *stack);
// bool	check_links(t_stack *stack);
void	scope_success(char *msg, t_stack *stack);

// //return values//
// void	display_return(t_stack *a);
// void	display_operations()
#endif
