#include "push_swap.h"


int main(int argc, char **argv)
{
    if(argc == 1)
        return 1;
    stack *a = NULL;
    stack *b = NULL;
    //stack *temp = NULL;

    init_stack(argc, argv, &a);
    if(argc == 2)
    {
        argc = count_word(argv[1], ' ') + 1;
    }
    //printf("argc : %d\n", argc);
    if(!a)
        return 1;
    if(is_sorted(a))
        return 0;
    if(argc <= 11)
    {
        //printf("tiny\n");
        tiny_sort(&a, &b, argc);
    }
    else
    {
        //printf("large\n");

        //large_sort(&a, &b);

        a_to_b(&a, &b);
        //mergeSort(&b);
        //printf("*****************************************\n");
        // stack *temp = b;

        // while(temp)
        // {
        //     printf("stack b : %d\n", temp -> data);
        //     temp = temp -> next;
        // }

        //stack *c = helper(&b);
        // printf(" b size : %d\n", list_size(b));        
        // temp = c;
        // while(temp)
        // {
        //     printf("stack c : %d\n", temp -> data);
        //     temp = temp -> next;
        // }
        //sort_list(&c, &b);

        //printf(" b size : %d\n", list_size(b));
        // temp = b;
        // while(temp)
        // {
        //     printf("stack b : %d\n", temp -> data);
        //     temp = temp -> next;
        // }
        //printf("size b : %d\n", list_size(b));
        //b_to_a(&a, &b);

        //printf("*******************************\n");
        //totoro(&a, &b);
        // stack *temp = a;
        // while(temp)
        // {
        //     printf("%d\n", temp -> data);
        //     temp = temp -> next;
        // }

        // if(!b)
        //     printf("b is empty\n");
        // if(!c)
        //     printf("c is empty\n");
        fill_a(&a, &b);
    }

    //printf("argc : %d\n", argc);
    // temp = a;

    // while(temp)
    // {
    //     printf("%d ", temp -> data);
    //     temp = temp -> next;
    // }
    //printf("a's content : %d\n", a -> data);
    free_stack(&a);
    free_stack(&b);
}