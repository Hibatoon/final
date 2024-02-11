/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:17 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/09 12:07:21 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	still_a_num(t_stack *a, int start, int end)
{
	t_stack	*temp;
	int		data;

	temp = a;
	while (temp)
	{
		data = temp->data;
		if (data >= start && data <= end)
			return (true);
		temp = temp->next;
	}
	return (false);
}

void	move_a_to_b(int moves, t_stack **a, t_stack **b)
{
	if (moves > 0)
	{
		while (moves--)
			ra(a);
	}
	else if (moves < 0)
	{
		while (moves++)
			rra(a);
	}
	pb(a, b);
}

int	there_is(t_stack **a, t_stack **b, t_large sort_info)
{
	sort_info.moves = target_index(*a, sort_info.arr[sort_info.start],
			sort_info.arr[sort_info.end]);
	a_to_b_help(sort_info.moves, a, b);
	if ((*b)->data < sort_info.arr[sort_info.size / 2 - 1])
		rb(b);
	return (sort_info.moves);
}

void	a_to_b(t_stack **a, t_stack **b)
{
	t_large	sort_info;

	sort_info.arr = init_arr(*a);
	sort_info.size = list_size(*a);
	quick_sort(0, sort_info.size - 1, sort_info.arr);
	sort_info.offset = get_offset(sort_info.size);
	sort_info.start = (sort_info.size / 2 - 1) - sort_info.offset;
	sort_info.end = (sort_info.size / 2 - 1) + sort_info.offset;
	while (list_size(*a))
	{
		index_and_move(a);
		if (still_a_num(*a, sort_info.arr[sort_info.start],
				sort_info.arr[sort_info.end]))
		{
			sort_info.moves = there_is(a, b, sort_info);
		}
		else
		{
			sort_info.start = check_start(sort_info.start, sort_info.offset);
			sort_info.end = check_end(sort_info.end, sort_info.size,
					sort_info.offset);
		}
	}
	free(sort_info.arr);
}

void	large_sort(t_stack **a, t_stack **b)
{
	a_to_b(a, b);
	fill_a(a, b);
}
