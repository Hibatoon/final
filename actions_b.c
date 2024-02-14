/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:23:56 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 14:59:14 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb_bonus(t_stack *first_node, t_stack *second_node)
{
	int	temp;

	if ((!first_node) || (!second_node))
	{
		return ;
	}
	temp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = temp;
}

void	rrb_bonus(t_stack **b)
{
	t_stack	*temp;
	int		k;
	int		size;
	t_stack	*head;

	if ((*b == NULL) || ((*b)->next == NULL))
		return ;
	if (list_size(*b) <= 1)
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
}

void	pb_bonus(t_stack **first_el, t_stack **b)
{
	t_stack	*temp;
	t_stack	*removed;

	if (*first_el == NULL)
		return ;
	temp = add_node((*first_el)->data);
	temp->next = *b;
	*b = temp;
	removed = *first_el;
	*first_el = (*first_el)->next;
	free(removed);
}

void	rb_bonus(t_stack **b)
{
	t_stack	*first_element;
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first_element = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first_element;
	first_element->next = NULL;
}
