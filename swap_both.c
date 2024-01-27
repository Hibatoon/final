#include "push_swap.h"

void    swap_both(t_list *node1_a, t_list *node2_a, t_list *node1_b, t_list *node2_b)
{
    swap_a(node1_a, node2_a);
    swap_b(node1_b, node2_b);
    write(1, "ss\n", 3);
}