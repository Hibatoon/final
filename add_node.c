#include "push_swap.h"

stack *add_node(int content)
{
    stack *node = malloc(sizeof(stack));
    if (!node)
        return(NULL);
    node -> data = content;
    node -> index = 0;
    node -> moves = 0;
    node -> next = NULL;
    return(node);
}