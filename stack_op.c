#include "push_swap.h"

void    stack_indexing(stack *a)
{
    stack *temp = a;
    int i = 0;

    while(temp)
    {
        temp -> index = i;
        temp = temp -> next;
        i++;
    }
}

void    stack_moves(stack *a)
{
    stack *temp = a;
    int i = 0;
    int size = list_size(a);
    int half = size / 2;
    if(size % 2 == 1)
        half++;

    while(temp && i < half)
    {
        temp -> moves = i;
        i++;
        temp = temp -> next;
    }
    if(size % 2 == 1)
        half--;
    i = half * -1;
    //printf("$$$%d\n", i);
    while(temp && i < 0)
    {
        temp -> moves = i;
        i++;
        temp = temp -> next;
    }
}
