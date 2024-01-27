#include "push_swap.h"


static int max_pos(stack *a)
{
    int max = INT_MIN;
    int i = 0;
    stack *temp = a;
    int pos = 0;
    while(temp)
    {
        i++;
        if(temp -> data > max)
        {
            max = temp -> data;
            pos = i;
        }
        temp = temp -> next;
    }
    return pos;
}

static int min_pos(stack *a)
{
    int min = INT_MAX;
    int i = 0;
    stack *temp = a;
    int pos = 0;
    while(temp)
    {
        i++;
        if(temp -> data < min)
        {
            min = temp -> data;
            pos = i;
        }
        temp = temp -> next;
    }
    return pos;
}

static void    sort_two(stack *a)
{
    if(a -> data > a -> next -> data)
        swap_a(a, a->next);
}

static void    sort_three(stack **a)
{
    int position = max_pos(*a);
    //printf("max position : %d\n", position);
    if(position == 1)
    {
        ra(a);
        sort_two(*a);
    }
    else if (position == 2)
    {
        rra(a);
        sort_two(*a);
    }
    else
        sort_two(*a);
}

// static void    sort_else(stack **a, stack **b)
// {
//     int i = 0;
//     int moves = 0;
//     int min = min_pos(*a) - 1;
//     printf("min pos : %d\n", min);
//     stack *temp = *a;
//     while(i < min)
//     {
//         temp = temp -> next;
//         i++;
//     }
//     moves = temp -> moves;
//     printf("moves : %d\n", moves);
//     if(moves < 0)
//     {
//         while(moves)
//         {
//             rra(a);
//             moves++;
//         }    
//     }
//     else if(moves > 0)
//     {
//         while(moves)
//         {
//             ra(a);
//             moves--;
//         }
//     }
//     int size = list_size(*a);
//     printf("size : %d\n", size);
//     while(size > 3)
//     {
//         pb(a, b);
//         size--;
//     }
//     sort_three(a);
//     size = list_size(*b);
//     printf("size : %d\n", size);
//     if(size > 1)
//         sort_two(*b);
//     while(size)
//     {
//         pa(b, a);
//         size--;
//     }
// }

void    sort_else(stack **a, stack **b)
{
    // int j = 0;
    // stack *temp = NULL;
    int size = list_size(*a);
    //printf("list size : %d\n", size);
    while(size > 3)
    {
        stack_moves(*a);
        int i = 0;
        int moves = 0;
        int min = min_pos(*a) - 1;
        //printf("min pos : %d\n", min);
        stack *temp = *a;
        while(i < min)
        {
            temp = temp -> next;
            i++;
        }
        moves = temp -> moves;
        //printf("moves : %d\n", moves);
        if(moves < 0)
        {
            while(moves)
            {
                rra(a);
                moves++;
            }    
        }
        else if(moves > 0)
        {
            while(moves)
            {
                ra(a);
                moves--;
            }
        }
        // int len = list_size(*a);
        // printf("size : %d\n", len);
        // while(len > 3)
        // {
        pb(a, b);
        //     size--;
        // }
        size--;
    }
    sort_three(a);
    size = list_size(*b);
    while(size--)
        pa(b, a);
}
void    tiny_sort(stack **a, stack **b, int argc)
{
    if(argc == 3)
        sort_two(*a);
    else if (argc == 4)
        sort_three(a);
    else
        sort_else(a, b);
}