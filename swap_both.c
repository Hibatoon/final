#include "push_swap.h"

void	swap_both(stack *node1_a, stack *node2_a, stack *node1_b,
		stack *node2_b)
{
	swap_a(node1_a, node2_a);
	swap_b(node1_b, node2_b);
	write(1, "ss\n", 3);
}
