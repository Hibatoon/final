#include "push_swap.h"

void	pb(stack **first_el, stack **b)
{
	stack	*temp;
	stack	*removed;

	if (*first_el == NULL)
		return ;
	temp = add_node((*first_el)->data);
	temp->next = *b;
	*b = temp;
	removed = *first_el;
	*first_el = (*first_el)->next;
	free(removed);
	write(1, "pb\n", 3);
}
