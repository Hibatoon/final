#include "push_swap.h"

void	rra(stack **a)
{
	stack	*head;
	stack	*last_1;
	int		size;
	int		k;

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
	write(1, "rra\n", 4);
}
