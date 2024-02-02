#include "push_swap.h"

void pa(stack **first_el, stack **a) 
{
    if (*first_el == NULL)// || (*a == NULL))
        return;

    stack *temp = add_node((*first_el)->data);

    temp->next = *a;

    *a = temp;

    stack *removed = *first_el;
    *first_el = (*first_el)->next;

    free(removed);
    write(1, "pa\n", 3);
}
