/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:57:12 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/08 21:12:19 by hcharra          ###   ########.fr       */
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
//handle two string with strjoin, and handle empty string and spaces before the args and 
//null stack b in the checker and add other mouvements
void	fill_a(t_stack **a, t_stack **b)
{
	int		*arr;
	int		end;
	t_stack	*temp;
	static int		index;

	end = list_size(*b) - 1;
	arr = sorted_arr(b, end);
	end = push_max(b, a, end);
	index = 0;
	while (list_size(*b))
	{
		stack_moves(*b);
		temp = *b;
		if (temp->data == arr[end] && index == 0)
			end = return_end(a, b, end);
		else if (temp->data != arr[end] && (index == 0
				|| last_node(*a)->data < temp->data))
			index = not_max(b, a, index);
		if (index >= 1)
		{
			if (is_there(arr[end], *b))
				end = move_it(a, b, end, arr[end]);
			else
			{
				rra(a);
				end--;
				index--;
			}
		}
	}
	full_bottom(a, index, arr[end]);
	free(arr);
}
