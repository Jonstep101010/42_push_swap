/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:19:44 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/21 14:28:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <ctype.h>

typedef enum e_type
{
	A = 0,
	B = 1
}t_type;

typedef struct s_node
{
	int				index;
	int				data;
	int				chunk;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	t_type			type;
	int				size;
}	t_stack;

typedef struct s_box
{
	struct s_stack	a;
	struct s_stack	b;
	int				size;
}	t_box;

typedef struct s_vals
{
	int	nbr;
	int	id;
	int	max;
	int	size;
	int	tmp_size;
	int	tmp_id;
}	t_vals;

#endif