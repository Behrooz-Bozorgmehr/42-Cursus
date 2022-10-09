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
    check_duplicated(a);
    if (check_order(a) == 0)
    {
      int count = 0;
      moves_a2b(a, b, a->size, &count);  
    }
    //print_stack(a, 'A');
    //print_stack(b, 'B');
  	free_all(a, b);
	}
	return (0);
}
