
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = init_stack();
		b = init_stack();
		fill_stack(a, argv, argc);
		do_checks(a);
	//	sort(a, b, a->size);
		algo_5(a, b);
		print_stack(a);
	}
	return (0);
}
