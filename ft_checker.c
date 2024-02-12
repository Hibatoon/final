#include "push_swap_bonus.h"






int main(int argc, char **argv)
{
    if(argc == 1)
        return 0;
    t_stack *a;
    t_stack *b;

    if(!split_all(&argc, argv, &a))
        return 0;
    if(!a)
        return 0;
    execute_actions(&a, &b);
    free_stack(&a);
    free_stack(&b);
}