/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:23:59 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/13 13:01:53 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	still_there(t_stack **a, t_stack **b, int offset, int *arr)
{
	int	moves;
	int	size;
	int	start;
	int	end;

	size = list_size(*a);
	start = (size / 2 - 1) - offset;
	end = (size / 2 - 1) + offset;
	index_and_move(a);
	moves = target_index(*a, arr[start], arr[end]);
	printf("moves : %d\n", moves);
	a_to_b_help(moves, a, b);
	printf("segv\n");
	if ((*b)->data < arr[size / 2 - 1])
		rb(b);
}

int	push_max(t_stack **b, t_stack **a, int end)
{
	t_stack	*temp;
	int		*arr;
	int		moves;

	stack_moves(*b);
	temp = *b;
	arr = sorted_arr(b, end);
	moves = 0;
	while (temp)
	{
		if (temp->data == arr[end])
			moves = temp->moves;
		temp = temp->next;
	}
	move_b(moves, b);
	pa(b, a);
	end--;
	free(arr);
	return (end);
}

void	full_bottom(t_stack **a, int index, int end)
{
	t_stack	*temp;

	while (index >= 1)
	{
		rra(a);
		index--;
	}
	if (!is_sorted(*a))
	{
		temp = last_node(*a);
		if (temp && temp->data == end)
			rra(a);
	}
}

t_fill	ft_assign(t_stack **a, t_stack **b)
{
	t_fill	temp;

	temp.end = list_size(*b) - 1;
	temp.arr = sorted_arr(b, temp.end);
	temp.end = push_max(b, a, temp.end);
	temp.index = 0;
	return (temp);
}
