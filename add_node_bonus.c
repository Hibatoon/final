#include "push_swap_bonus.h"

stack	*add_node_bonus(int content)
{
	stack	*node;
	
	node = malloc(sizeof(stack));
	if (!node)
		return (NULL);
	node->data = content;
	node->index = 0;
	node->moves = 0;
	node->next = NULL;
	return (node);
}
