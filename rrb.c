#include "push_swap.h"

void    rrb(stack **b)
{
        if(b == NULL || *b == NULL)
        return;
    
    stack *last_1 = *b;
    int     k = 1;
    int size = list_size(*b);

    while(k < size - 1) //7
    {
        last_1 = last_1 -> next;
        k++;
    }

    stack *head = last_1 -> next;

    head -> next = *b;
    *b = head;

    last_1 ->next = NULL;
    write(1, "rrb\n", 4);
}