#include "push_swap.h"

static int	max_pos(stack *a)
{
	int		max;
	int		i;
	stack	*temp;
	int		pos;

	max = INT_MIN;
	i = 0;
	temp = a;
	pos = 0;
	while (temp)
	{
		i++;
		if (temp->data > max)
		{
			max = temp->data;
			pos = i;
		}
		temp = temp->next;
	}
	return (pos);
}

static int	min_pos(stack *a)
{
	int		min;
	int		i;
	stack	*temp;
	int		pos;

	min = INT_MAX;
	i = 0;
	temp = a;
	pos = 0;
	while (temp)
	{
		i++;
		if (temp->data < min)
		{
			min = temp->data;
			pos = i;
		}
		temp = temp->next;
	}
	return (pos);
}

static void	sort_two(stack *a)
{
	if (a->data > a->next->data)
		swap_a(a, a->next);
}

static void	sort_three(stack **a)
{
	int	position;

	position = max_pos(*a);
	if (position == 1)
	{
		ra(a);
		sort_two(*a);
	}
	else if (position == 2)
	{
		rra(a);
		sort_two(*a);
	}
	else
		sort_two(*a);
}

void	sort_else(stack **a, stack **b)
{
	int		size;
	int		i;
	int		moves;
	int		min;
	stack	*temp;

	size = list_size(*a);
	while (size > 3)
	{
		stack_moves(*a);
		i = 0;
		moves = 0;
		min = min_pos(*a) - 1;
		temp = *a;
		while (i < min)
		{
			temp = temp->next;
			i++;
		}
		moves = temp->moves;
		if (moves < 0)
		{
			while (moves)
			{
				rra(a);
				moves++;
			}
		}
		else if (moves > 0)
		{
			while (moves)
			{
				ra(a);
				moves--;
			}
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	size = list_size(*b);
	while (size--)
		pa(b, a);
}

void	tiny_sort(stack **a, stack **b, int argc)
{
	if (argc == 3)
		sort_two(*a);
	else if (argc == 4)
		sort_three(a);
	else
		sort_else(a, b);
}
