#include "push_swap.h"

void pa(stack **first_el, stack **a) 
{
    //printf("HEHE\n");
    if (*first_el == NULL)// || (*a == NULL))
        return; // Nothing to push

    // Create a new node for the pushed element
    stack *temp = add_node((*first_el)->data);

    // Update the next pointer of the pushed element
    temp->next = *a;

    // Update the head of the list
    *a = temp;

    // Remove the pushed element from its original list
    stack *removed = *first_el;
    *first_el = (*first_el)->next;

    // Free the removed element
    free(removed);
    write(1, "pa\n", 3);
}
