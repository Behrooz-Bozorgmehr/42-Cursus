
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc > 1)
	{
		a = init_stack();
		b = init_stack();
	//	print_string("stack a initial state:");
		fill_stack(a, argv, argc);
	//	print_stack(a);
		if (do_checks(a, b))
		{
			if (check_order(a) == 0)
				sort (a, b);
			print_string("sorted state,\t stack a:");
			print_stack(a);
			print_string("stack b:\n");
			print_stack(b);
			free_all(a, b);
			
		}
	}
	return (0);
}
