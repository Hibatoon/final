#include "push_swap.h"


int main(int argc, char **argv)
{
    if(argc == 1)
        return 1;
    stack *a = NULL;
    stack *b = NULL;

    init_stack(argc, argv, &a);
    if(argc == 2)
         argc = count_word(argv[1], ' ');
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

        stack *temp = b;
        while(temp)
        {
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }

        printf("*******************************\n");
        fill_a(&a, &b);
    }

    stack *temp = a;

    while(temp)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    //printf("a's content : %d\n", a -> data);
    free_stack(&a);
}