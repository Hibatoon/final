#include "push_swap_bonus.h"

void	sa_bonus(stack *first_node, stack *second_node)
{
	int	temp;

	if ((!first_node) || (!second_node))
		return ;
	temp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = temp;
}

void	sb_bonus(stack *first_node, stack *second_node)
{
	int	temp;

	if ((!first_node) || (!second_node))
		return ;
	temp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = temp;
}

void	rrb_bonus(stack **b)
{
	stack	*last_1;
	int		k;
	int		size;
	stack	*head;

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

void	rra_bonus(stack **a)
{
	stack	*last_1;
	int		k;
	int		size;
	stack	*head;

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

void	rb_bonus(stack **b)
{
	stack	*first_element;
	stack	*last;

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

void	ra_bonus(stack **a)
{
	stack	*first_element;
	stack	*last;

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

void	pb_bonus(stack **first_el, stack **b)
{
	stack	*temp;
	stack	*removed;

	if (*first_el == NULL)
		return ;
	temp = add_node_bonus((*first_el)->data);
	temp->next = *b;
	*b = temp;
	removed = *first_el;
	*first_el = (*first_el)->next;
	free(removed);
}

void	pa_bonus(stack **first_el, stack **a)
{
	stack	*temp;
	stack	*removed;

	if (*first_el == NULL)
		return ;
	temp = add_node_bonus((*first_el)->data);
	temp->next = *a;
	*a = temp;
	removed = *first_el;
	*first_el = (*first_el)->next;
	free(removed);
}
