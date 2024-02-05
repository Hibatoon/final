#include "push_swap_bonus.h"

void	stack_indexing(stack *a)
{
	stack	*temp;
	int		i;

	temp = a;
	i = 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	stack_moves(stack *a)
{
	stack	*temp;
	int		i;
	int		size;
	int		half;

	temp = a;
	i = 0;
	size = list_size(a);
	half = size / 2;
	if (size % 2 == 1)
		half++;
	while (temp && i < half)
	{
		temp->moves = i;
		i++;
		temp = temp->next;
	}
	if (size % 2 == 1)
		half--;
	i = half * -1;
	while (temp && i < 0)
	{
		temp->moves = i;
		i++;
		temp = temp->next;
	}
}

void	free_stack(stack **a)
{
	stack	*temp;

	temp = *a;
	while (temp)
	{
		free(temp);
		temp = temp->next;
	}
}
