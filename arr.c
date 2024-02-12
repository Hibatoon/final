/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:09:13 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/12 19:13:12 by hcharra          ###   ########.fr       */
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
	int		pivot;

	if (end <= start)
		return ;
	pivot = position(start, end, arr);
	quick_sort(start, pivot - 1, arr);
	quick_sort(pivot + 1, end, arr);
}
