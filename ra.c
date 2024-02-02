#include "push_swap.h"


void ra(stack **a)
{
    if (*a == NULL || (*a)->next == NULL)
    {
        // Empty stack or only one element, no rotation needed.
        return;
    }

    stack *first_element = *a;
    *a = (*a)->next;

    // Find the last node in the stack.
    stack *last = *a;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = first_element;
    first_element->next = NULL;
    write(1, "ra\n", 3);
}
