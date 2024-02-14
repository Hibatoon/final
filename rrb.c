/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:59:31 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 15:27:06 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b)
{
	t_stack	*temp;
	int		k;
	int		size;
	t_stack	*head;

	if (b == NULL || *b == NULL)
		return ;
	temp = *b;
	k = 1;
	size = list_size(*b);
	while (k < size - 1)
	{
		temp = temp->next;
		k++;
	}
	head = temp->next;
	head->next = *b;
	*b = head;
	temp->next = NULL;
	write(1, "rrb\n", 4);
}
