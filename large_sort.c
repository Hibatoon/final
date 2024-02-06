/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:17 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/06 23:53:30 by hcharra          ###   ########.fr       */
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

void	a_to_b_help(int moves, t_stack **a, t_stack **b)
{
	if (moves < 0)
		neg_moves(moves, a);
	else if (moves > 0)
		pos_moves(moves, a);
	pb(a, b);
}

int	check_start(int start)
{
	if (start < 0)
		return (0);
	return (start);
}

int	check_end(int end, int size)
{
	if (end > size - 1)
		return (size - 1);
	return (end);
}

void	index_and_move(t_stack **a)
{
	stack_indexing(*a);
	stack_moves(*a);
}

void	a_to_b(t_stack **a, t_stack **b)
{
	int	*arr;
	int	size;
	int	offset;
	int	start;
	int	end;
	int	moves;

	arr = init_arr(*a);
	size = list_size(*a);
	quick_sort(0, size - 1, arr);
	offset = get_offset(size);
	start = (size / 2 - 1) - offset;
	end = (size / 2 - 1) + offset;
	while (list_size(*a))
	{
		index_and_move(a);
		if (still_a_num(*a, arr[start], arr[end]))
		{
			moves = target_index(*a, arr[start], arr[end]);
			a_to_b_help(moves, a, b);
			if ((*b)->data < arr[size / 2 - 1])
				rb(b);
		}
		else
		{
			start -= offset;
			start = check_start(start);
			end += offset;
			end = check_end(end, size);
		}
	}
	free(arr);
}

void	large_sort(t_stack **a, t_stack **b)
{
	a_to_b(a, b);
	fill_a(a, b);
}
