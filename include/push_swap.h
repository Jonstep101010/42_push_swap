#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdbool.h>

typedef struct t_stack
{
	struct t_stack	*head;
	struct t_stack	*tail;
	int				data;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

int		main(int argc, char **argv);
t_stack	parse_input(t_stack *stack, char **argv);

//operations//
void	swap(t_stack *stack);


//list functions//
void	populate(t_stack *stack, int new_data);
void	append(t_stack *stack, int new_data);
void	print_stack(t_stack *stack);
# endif
