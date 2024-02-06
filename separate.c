/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:47:14 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/06 15:56:20 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_pos(t_stack *a)
{
	int		min;
	int		i;
	t_stack	*temp;
	int		pos;

	min = INT_MAX;
	i = 0;
	temp = a;
	pos = 0;
	while (temp)
	{
		i++;
		if (temp->data < min)
		{
			min = temp->data;
			pos = i;
		}
		temp = temp->next;
	}
	return (pos);
}

void	neg_moves(int moves, t_stack **a)
{
	while (moves)
	{
		rra(a);
		moves++;
	}
}

void	pos_moves(int moves, t_stack **a)
{
	while (moves)
	{
		ra(a);
		moves--;
	}
}

void	fill_b(t_stack **a, t_stack **b)
{
	int		i;
	int		moves;
	int		min;
	t_stack	*temp;

	stack_moves(*a);
	i = 0;
	moves = 0;
	min = min_pos(*a) - 1;
	temp = *a;
	while (i < min)
	{
		temp = temp->next;
		i++;
	}
	moves = temp->moves;
	if (moves < 0)
		neg_moves(moves, a);
	else if (moves > 0)
		pos_moves(moves, a);
	pb(a, b);
}
