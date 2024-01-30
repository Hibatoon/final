#include "push_swap.h"

stack	*last_node(stack *lst)
{
	stack	*ptr;

	if (lst == NULL)
		return (lst);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}