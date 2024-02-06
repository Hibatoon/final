/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:56:23 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/05 22:07:10 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_bonus(t_stack *first_node, t_stack *second_node)
{
	int	temp;

	if ((!first_node) || (!second_node))
		return ;
	temp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = temp;
}

void	sb_bonus(t_stack *first_node, t_stack *second_node)
{
	int	temp;

	if ((!first_node) || (!second_node))
		return ;
	temp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = temp;
}

void	rrb_bonus(t_stack **b)
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
}

void	rra_bonus(t_stack **a)
{
	t_stack	*last_1;
	int		k;
	int		size;
	t_stack	*head;

	last_1 = *a;
	k = 1;
	size = list_size(*a);
	while (k < size - 1)
	{
		last_1 = last_1->next;
		k++;
	}
	head = last_1->next;
	head->next = *a;
	*a = head;
	last_1->next = NULL;
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

void	ra_bonus(t_stack **a)
{
	t_stack	*first_element;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first_element = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first_element;
	first_element->next = NULL;
}

void	pb_bonus(t_stack **first_el, t_stack **b)
{
	t_stack	*temp;
	t_stack	*removed;

	if (*first_el == NULL)
		return ;
	temp = add_node_bonus((*first_el)->data);
	temp->next = *b;
	*b = temp;
	removed = *first_el;
	*first_el = (*first_el)->next;
	free(removed);
}

void	pa_bonus(t_stack **first_el, t_stack **a)
{
	t_stack	*temp;
	t_stack	*removed;

	if (*first_el == NULL)
		return ;
	temp = add_node_bonus((*first_el)->data);
	temp->next = *a;
	*a = temp;
	removed = *first_el;
	*first_el = (*first_el)->next;
	free(removed);
}
