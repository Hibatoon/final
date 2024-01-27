#include "push_swap.h"

bool is_sorted(stack *a)
{
    stack *temp = a;

    while(temp -> next && temp)
    {
        if(temp -> data > temp -> next -> data)
            return false;
        temp = temp -> next;
    }
    return true;
}