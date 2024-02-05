#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;

	if (argc == 1)
		return (1);
	a = NULL;
	b = NULL;
	init_stack(argc, argv, &a);
	if (argc == 2)
	{
		argc = count_word(argv[1], ' ') + 1;
	}
	if (!a)
		return (1);
	if (is_sorted(a))
		return (0);
	if (argc <= 11)
		tiny_sort(&a, &b, argc);
	else
	{
		a_to_b(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
