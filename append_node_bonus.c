#include "push_swap_bonus.h"

void	append_node(stack **head, stack *new_node)
{
	stack	*temp;

	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
