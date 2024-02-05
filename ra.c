#include "push_swap.h"

void	ra(stack **a)
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
	write(1, "ra\n", 3);
}
