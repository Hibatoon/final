#include "push_swap.h"
#include <string.h>
#include "get_next_line.h"
#include "push_swap_bonus.h"

bool check_instruction(char *line)
{
    char *actions[] = {"rra\n", "rrb\n", "rrr\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "sa\n", "sb\n", "ss\n", NULL};
    int i = 0;
    while (actions[i] != NULL)
    {
        if (strcmp(line, actions[i]) == 0)
            return true;
        i++;
    }
    return false;
}

void    a_actions(char *line, stack **a, stack **b)
{
    if(!strcmp(line, "ra\n"))
        ra_bonus(a);
    else if(!strcmp(line, "rra\n"))
        rra_bonus(a);
    else if(!strcmp(line, "sa\n"))
        sa_bonus(*a, (*a) -> next);
    else if(!strcmp(line, "pa\n"))
        pa_bonus(b, a);
}

void    b_actions(char *line, stack **a, stack **b)
{
    if(!strcmp(line, "rb\n"))
        rb_bonus(b);
    else if(!strcmp(line, "rrb\n"))
        rrb_bonus(b);
    else if(!strcmp(line, "sb\n"))
        sb_bonus(*b, (*b) -> next);
    else if(!strcmp(line, "pb\n"))
        pb_bonus(a, b);
}

// void    both_actions(char *line, stack **a, stack **b)
// {
//     if(!strcmp(line, "rr\n"))
//         rr(b);
//     else if(!strcmp(line, "rrr\n"))
//         rrr(b);
//     else if(!strcmp(line, "ss\n"))
//         ss(*b, (*b) -> next);
// }
void    execute_actions(stack **a, stack **b)
{
    char *line = get_next_line(0);;

    while(line)
    {
        if(!check_instruction(line))
        {
            write(2, "Error\n", 6);
            return;
        }
        //printf("%s", line);
         a_actions(line, a, b);
         b_actions(line, a, b);
        //both_actions(line, a, b);
        line = get_next_line(0);
    }
    if(is_sorted(*a) && !(*b))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

int main(int argc, char **argv)
{
    if(argc == 1)
        return 0;
    stack *a = NULL;
    stack *b = NULL;

    init_stack(argc, argv, &a);
    if(!a)
        return 0;
    execute_actions(&a, &b);
}