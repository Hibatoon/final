/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:00:01 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/10 15:35:19 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_pos(t_stack *a)
{
	int		max;
	int		i;
	t_stack	*temp;
	int		pos;

	max = INT_MIN;
	i = 0;
	temp = a;
	pos = 0;
	while (temp)
	{
		i++;
		if (temp->data > max)
		{
			max = temp->data;
			pos = i;
		}
		temp = temp->next;
	}
	return (pos);
}

static void	sort_two(t_stack *a)
{
	if (a->data > a->next->data)
		swap_a(a, a->next);
}

static void	sort_three(t_stack **a)
{
	int	position;

	position = max_pos(*a);
	if (position == 1)
	{
		ra(a);
		sort_two(*a);
	}
	else if (position == 2)
	{
		rra(a);
		sort_two(*a);
	}
	else
		sort_two(*a);
}

void	sort_else(t_stack **a, t_stack **b)
{
	int		size;

	size = list_size(*a);
	while (size > 3)
	{
		fill_b(a, b);
		size--;
	}
	sort_three(a);
	size = list_size(*b);
	while (size--)
		pa(b, a);
}

void	tiny_sort(t_stack **a, t_stack **b, int argc)
{
	if (argc == 3)
		sort_two(*a);
	else if (argc == 4)
		sort_three(a);
	else
		sort_else(a, b);
}
