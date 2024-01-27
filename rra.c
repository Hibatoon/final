













#include "push_swap.h"

void    rra(stack **a)
{
    stack *last_1 = *a;
    int     k = 1;
    int size = list_size(*a);

    while(k < size - 1) //7
    {
        last_1 = last_1 -> next;
        k++;
    }

    stack *head = last_1 -> next;

    head -> next = *a;
    *a = head;

    last_1 ->next = NULL;

    //return(last_1);
    write(1, "rra\n", 4);
}