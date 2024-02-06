/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:59:31 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/05 22:27:13 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b)
{
	t_stack	*last_1;
	int		k;
	int		size;
	t_stack	*head;

	if (b == NULL || *b == NULL)
		return ;
	last_1 = *b;
	k = 1;
	size = list_size(*b);
	while (k < size - 1)
	{
		last_1 = last_1->next;
		k++;
	}
	head = last_1->next;
	head->next = *b;
	*b = head;
	last_1->next = NULL;
	write(1, "rrb\n", 4);
}
