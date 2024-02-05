#include "push_swap.h"

void	rrb(stack **b)
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
	write(1, "rrb\n", 4);
}
