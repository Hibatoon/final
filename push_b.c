#include "push_swap.h"

void pb(stack **first_el, stack **b) 
{
    if (*first_el == NULL) //|| (*b == NULL))
        return;
		
    stack *temp = add_node((*first_el)->data);
    temp->next = *b;
    *b = temp;
    stack *removed = *first_el;
    *first_el = (*first_el)->next;
    free(removed);
    write(1, "pb\n", 3);
}