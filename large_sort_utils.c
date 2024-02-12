/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:11:07 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/12 14:57:42 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_offset(int size)
{
	int	offset;

	offset = 0;
	if (size <= 21)
		offset = 2;
	else if (size > 100)
		offset = 30;
	else
		offset = 10;
	return (offset);
}

int	target_index(t_stack *a, int start, int end)
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

int	check_start(int start, int offset)
{
	start -= offset;
	if (start < 0)
		return (0);
	return (start);
}

int	check_end(int end, int size, int offset)
{
	end += offset;
	if (end > size - 1)
		return (size - 1);
	return (end);
}
