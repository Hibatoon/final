/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:23:59 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/06 23:45:47 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_help(int moves, t_stack **a, t_stack **b)
{
	if (moves < 0)
		neg_moves(moves, a);
	else if (moves > 0)
		pos_moves(moves, a);
	pb(a, b);
}

static int	target_index(t_stack *a, int start, int end)
{
	t_stack	*temp;
	int		data;

	temp = a;
	while (temp)
	{
		data = temp->data;
		if (data >= start && data <= end)
			return (temp->moves);
		temp = temp->next;
	}
	return (-1);
}

void	large_helper(t_stack **a, t_stack **b, int start, int end)
{
	int		moves;
	int		*arr;
	int		size;

	arr = init_arr(*a);
	size = list_size(*a);
	quick_sort(0, size - 1, arr);
	moves = target_index(*a, arr[start], arr[end]);
	a_to_b_help(moves, a, b);
	if ((*b)->data < arr[size / 2 - 1])
		rb(b);
}
