/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:59:43 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/06 15:53:23 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_indexing(t_stack *a)
{
	t_stack	*temp;
	int		i;

	temp = a;
	i = 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	stack_moves(t_stack *a)
{
	t_stack	*temp;
	int		i;
	int		half;

	temp = a;
	i = 0;
	half = list_size(a) / 2;
	if (list_size(a) % 2 == 1)
		half++;
	while (temp && i < half)
	{
		temp->moves = i;
		i++;
		temp = temp->next;
	}
	if (list_size(a) % 2 == 1)
		half--;
	i = half * -1;
	while (temp && i < 0)
	{
		temp->moves = i;
		i++;
		temp = temp->next;
	}
}

void	free_stack(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		free(temp);
		temp = temp->next;
	}
}
