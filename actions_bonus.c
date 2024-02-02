#include "push_swap_bonus.h"

void    sa_bonus(stack *first_node, stack *second_node)
{
    int temp;

    if ((!first_node) || (!second_node))
        return;
    temp = first_node -> data;
    first_node -> data = second_node -> data;
    second_node -> data = temp;
}

void    sb_bonus(stack *first_node, stack *second_node)
{
    int temp;

    if ((!first_node) || (!second_node))
        return;
    temp = first_node -> data;
    first_node -> data = second_node -> data;
    second_node -> data = temp;
}

void    rrb_bonus(stack **b)
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
}

void    rra_bonus(stack **a)
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
}

void rb_bonus(stack **b)
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
}

void ra_bonus(stack **a)
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
}

void pb_bonus(stack **first_el, stack **b) 
{
    if (*first_el == NULL) //|| (*b == NULL))
        return;
		
    stack *temp = add_node((*first_el)->data);
    temp->next = *b;
    *b = temp;
    stack *removed = *first_el;
    *first_el = (*first_el)->next;
    free(removed);
}

void pa_bonus(stack **first_el, stack **a) 
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

