/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:57:12 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/12 22:24:26 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b(int moves, t_stack **b)
{
	if (moves > 0)
	{
		while (moves--)
			rb(b);
	}
	else if (moves < 0)
	{
		while (moves++)
			rrb(b);
	}
}

bool	is_there(int num, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (temp)
	{
		if (temp->data == num)
		{
			return (true);
		}
		temp = temp->next;
	}
	return (false);
}

int	find_moves(int num, t_stack *b)
{
	t_stack	*temp;

	stack_moves(b);
	temp = b;
	while (temp)
	{
		if (temp->data == num)
			return (temp->moves);
		temp = temp->next;
	}
	return (0);
}

void	fill_a(t_stack **a, t_stack **b)
{
	t_fill	fill_info;

	fill_info = ft_assign(a, b);
	while (list_size(*b))
	{
		stack_moves(*b);
		fill_info.temp = *b;
		if (fill_info.temp->data == fill_info.arr[fill_info.end]
			&& fill_info.index == 0)
			fill_info.end = return_end(a, b, fill_info.end);
		else if (fill_info.temp->data != fill_info.arr[fill_info.end]
			&& (fill_info.index == 0
				|| last_node(*a)->data < fill_info.temp->data))
			fill_info.index = not_max(b, a, fill_info.index);
		if (fill_info.index >= 1)
		{
			if (is_there(fill_info.arr[fill_info.end], *b))
				fill_info.end = move_it(a, b, fill_info.end,
						fill_info.arr[fill_info.end]);
			else
			{
				rra(a);
				fill_info.end--;
				fill_info.index--;
			}
		}
	}
	if (fill_info.end >= 0)
		full_bottom(a, fill_info.index, fill_info.arr[fill_info.end]);
	free(fill_info.arr);
}

int		push_and_decrease_end(t_fill fill_info, t_stack **b, t_stack **a)
{
	if (is_there(fill_info.arr[fill_info.end], *b))
	{
		fill_info.end = move_it(a, b, fill_info.end,
				fill_info.arr[fill_info.end]);
	}
	return(fill_info.end);
}