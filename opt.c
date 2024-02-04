#include "push_swap.h"

void pbc(stack **first_el, stack **b) 
{
    if (*first_el == NULL) //|| (*b == NULL))
        return;
		
    stack *temp = add_node((*first_el)->data);
    temp->next = *b;
    *b = temp;
    stack *removed = *first_el;
    *first_el = (*first_el)->next;
    free(removed);
    //write(1, "pb\n", 3);
}
void pc(stack **first_el, stack **a) 
{
    if (*first_el == NULL)// || (*a == NULL))
        return;

    stack *temp = add_node((*first_el)->data);

    temp->next = *a;

    *a = temp;

    stack *removed = *first_el;
    *first_el = (*first_el)->next;

    free(removed);
}

void    rrc(stack **c)
{
    stack *last_1 = *c;
    int     k = 1;
    int size = list_size(*c);

    while(k < size - 1) //7
    {
        last_1 = last_1 -> next;
        k++;
    }

    stack *head = last_1 -> next;

    head -> next = *c;
    *c = head;

    last_1 ->next = NULL;

    //return(last_1);
    //write(1, "rra\n", 4);
}

void rc(stack **c)
{
    if (*c == NULL || (*c)->next == NULL)
    {
        // Empty stack or only one element, no rotation needed.
        return;
    }

    stack *first_element = *c;
    *c = (*c)->next;

    // Find the last node in the stack.
    stack *last = *c;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = first_element;
    first_element->next = NULL;
    //write(1, "ra\n", 3);
}

stack *helper(stack **b)
{
    stack *c = NULL;
    int size = list_size(*b);
    //printf("size : %d\n", size);
    //stack *temp = b;
    int i = 0;

    while(i < size)
    {
        //append_node(&c, add_node(temp -> data));
        //temp = temp -> next;
        pc(b, &c);
        i++;
    }
    return c;
}


int     min_moves(stack *c)
{
    int min = INT_MAX;
    int moves = 0;
    stack *temp = c;

    while(temp)
    {
        if(temp -> data < min)
        {
            min = temp -> data;
            moves = temp -> moves;
        }    
        temp = temp -> next;
    }
    // printf("MAX : %d\n", max);
    // printf("MOVES : %d\n", moves);
    return moves;
}


void    sort_list(stack **c, stack **b)
{
    //printf("ENTER\n");
    //int size = list_size(c);
    int moves = 0;

    while(list_size(*c))
    {
        //printf("list size : %d\n", list_size(*c));
        //stack_indexing(*c);
        stack_moves(*c);
        moves = min_moves(*c);
        //printf("moves : %d\n", moves);
        if(moves < 0)
        {
            while(moves++)
                rrc(c);
        }
        else if (moves > 0)
        {
            while(moves--)
                rc(c);
        }
        pbc(c, b);
    }
}

void    totoro(stack **a, stack **b)
{
    while(list_size(*b))
    {
        pa(b, a);
    }
}