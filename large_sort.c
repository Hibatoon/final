/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:17 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/08 21:23:17 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_arr(t_stack *a)
{
	int		*arr;
	int		i;
	t_stack	*temp;
	int		size;

	size = list_size(a);
	arr = malloc((size) * sizeof(int));
	i = 0;
	temp = a;
	while (temp)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}

static int	position(int start, int end, int *arr)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	i = start - 1;
	j = start;
	pivot = arr[end];
	while (j < end)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}
	i++;
	temp = arr[end];
	arr[end] = arr[i];
	arr[i] = temp;
	return (i);
}

void	quick_sort(int start, int end, int *arr)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = position(start, end, arr);
	quick_sort(start, pivot - 1, arr);
	quick_sort(pivot + 1, end, arr);
}

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

static int	get_offset(int size)
{
	int	offset;

	offset = 0;
	if (size <= 16)
		offset = 2;
	else if (size > 100)
		offset = 30;
	else
		offset = 10;
	return (offset);
}

// void	a_to_b_help(int moves, t_stack **a, t_stack **b)
// {
// 	if (moves < 0)
// 		neg_moves(moves, a);
// 	else if (moves > 0)
// 		pos_moves(moves, a);
// 	pb(a, b);
// }

int	check_end(int end, int size, int offset)
{
	end += offset;
	if (end > size - 1)
		return (size - 1);
	return (end);
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

void	index_and_move(t_stack **a)
{
	stack_indexing(*a);
	stack_moves(*a);
}
void	a_to_b_helping(int *arr, int start, int end, t_stack **a, t_stack **b)
{
	int	moves;

	moves = target_index(*a, arr[start], arr[end]);
	move_a_to_b(moves, a, b);
	if ((*b)->data < arr[list_size(*a) / 2 - 1])
		rb(b);
}

int	check_start(int start, int offset)
{
	start -= offset;
	if (start < 0)
		return (0);
	return (start);
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
		if (still_a_num(*a, sort_info.arr[sort_info.start],sort_info.arr[sort_info.end]))
		{
			sort_info.moves = target_index(*a, sort_info.arr[sort_info.start],sort_info.arr[sort_info.end]);
			a_to_b_help(sort_info.moves, a, b);
			if ((*b)->data < sort_info.arr[sort_info.size / 2 - 1])
				rb(b);
		}
		else
		{
			sort_info.start = check_start(sort_info.start, sort_info.offset);
			sort_info.end = check_end(sort_info.end, sort_info.size, sort_info.offset);
		}
	}
	free(sort_info.arr);
}

void	large_sort(t_stack **a, t_stack **b)
{
	a_to_b(a, b);
	fill_a(a, b);
}
