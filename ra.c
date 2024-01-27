#include "push_swap.h"

// void    rotate_a(stack **stack)
// {
//     //printf("pp");
//     stack  *temp = *stack;
//     stack *first_element = add_node(temp -> data);

//     *stack = temp -> next; //8
//     add_back(stack, first_element);

//     //stack *last = last_node(*stack);
// }


// void    rotate_a(stack **stack)
// {
//     stack *first_element = *stack; //6 NULL
//     *stack = (*stack) -> next;  //5
//     first_element -> next = NULL;

//     stack *last = last_node(*stack); //8

//     last -> next = first_element; // 5 8 6
// }

void ra(stack **a)
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
    write(1, "ra\n", 3);
}

// int main()
// {
//     stack *head = add_node("6");
//     stack  *node1 = add_node("5");
//     stack  *node2 = add_node("8");

//     add_back(&head, node1);
//     add_back(&head, node2);

//     stack  *temp = head;

//     while(temp)
//     {
//         printf("%s\n", temp -> data);
//         temp = temp -> next;
//     }

//     rotate_a(&head);

//     while(head)
//     {
//         printf("--> %s\n", head -> data);
//         head = head -> next;
//     }
// }