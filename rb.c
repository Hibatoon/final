#include "push_swap.h"

void rb(stack **b)
{
    if (*b == NULL || (*b)->next == NULL)
        return;

    stack *first_element = *b;
    *b = (*b)->next;

    stack *last = *b;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = first_element;
    first_element->next = NULL;
    write(1, "rb\n", 3);
}