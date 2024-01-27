#include "push_swap.h"

void append_node(stack **head, stack *new_node)
{
    // if(!head || !new_node)
    //     return;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        stack *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}