#include "push_swap.h"

void	swap_b(stack *first_node, stack *second_node)
{
	int temp;

	if ((!first_node) || (!second_node))
		return ;
	temp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = temp;
	write(1, "sb\n", 3);
}