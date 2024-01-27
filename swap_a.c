#include "push_swap.h"

void    swap_a(stack *first_node, stack *second_node)
{
    int temp;

    if ((!first_node) || (!second_node))
        return;
    temp = first_node -> data;
    first_node -> data = second_node -> data;
    second_node -> data = temp;
    write(1, "sa\n", 3);
}

// int main()
// {
//     stack *head = NULL;
//     head = add_node("hello");
//     stack *node = add_node("world");
//     add_back(&head, node);
//     stack *tmp = head;
//     while(tmp)
//     {
//         printf("%s\n", tmp -> data);
//         tmp = tmp -> next;
//     }
//     swap_a(head, node);
//     printf("*********\n");
//     while (head)
//     {
//         printf("%s\n", head -> data);
//         head = head -> next;
//     }
    
// }