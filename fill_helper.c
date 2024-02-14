/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:24:49 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/13 13:25:24 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_it_(t_stack **a, t_stack **b, int *end, int max)
{
	int	moves;

	moves = find_moves(max, *b);
	move_b(moves, b);
	pa(b, a);
	*end -= 1;
}

void	is_max(t_stack **a, t_stack **b, int *end)
{
	pa(b, a);
	*end -= 1;
}

void	isnt_max(t_stack **a, t_stack **b, int *index)
{
	pa(b, a);
	ra(a);
	*index += 1;
}

void	not_there(t_stack **a, int *index, int *end)
{
	rra(a);
	*index -= 1;
	*end -= 1;
}
