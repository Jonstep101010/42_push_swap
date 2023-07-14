/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:06:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/14 19:18:18 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

// push //

void	pa(t_box *box);
void	pb(t_box *box);

// swap //

void	sa(t_box *box);
void	sb(t_box *box);
void	ss(t_box *box);

// rotate //

void	ra(t_box *box);
void	rb(t_box *box);
void	rr(t_box *box);

// reverse rotate //

void	rra(t_box *box);
void	rrb(t_box *box);
void	rrr(t_box *box);

#endif