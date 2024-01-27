#include "push_swap.h"


int main(int argc, char **argv)
{
    if(argc == 1)
        return 1;
    stack *a = NULL;
    stack *b = NULL;

    init_stack(argc, argv, &a);
    // stack *temp = a;
    // while(temp)
    // {
    //     printf("%d\n", temp -> data);
    //     temp = temp -> next;
    // }
    // temp = a;
    // while(temp)
    // {
    //     printf("index : %d\n", temp -> index);
    //     temp = temp -> next;
    // }
    // temp = a;
    // while(temp)
    // {
    //     printf("moves : %d\n", temp -> moves);
    //     temp = temp -> next;
    // }
    //tiny_sort(&a, &b, argc);
    // temp = a;
    // while(temp)
    // {
    //     printf("%d\n", temp -> data);
    //     temp = temp -> next;
    // }
    a_to_b(&a, &b);
    b_to_a(&a, &b);

    stack *temp = a;

    while(temp)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    //printf("a's content : %d\n", a -> data);
    free(a);
}