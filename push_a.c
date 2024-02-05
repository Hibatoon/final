#include "push_swap.h"

void	pa(stack **first_el, stack **a)
{
	stack	*temp;
	stack	*removed;

	if (*first_el == NULL)
		return ;
	temp = add_node((*first_el)->data);
	temp->next = *a;
	*a = temp;
	removed = *first_el;
	*first_el = (*first_el)->next;
	free(removed);
	write(1, "pa\n", 3);
}
