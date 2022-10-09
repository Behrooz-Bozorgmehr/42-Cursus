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
    int count = 0;
    moves_a2b(a, b, a->size, &count);  
      //  upto_five_handler(a, b, 'A', a->size);
        print_stack_details(a, 'A');
        print_stack_details(b, 'B');
/*
        pop_push(b, a, 'B');
        pop_push(b, a, 'B');
        pop_push(b, a, 'B');
        pop_push(b, a, 'B');
        pop_push(b, a, 'B');

        print_stack_details(a, 'A');
        print_stack_details(b, 'B');
        
       
       // five_handler(a, b, 'A', 5);
        five_handler(a, b, 'B', 5);

        print_stack_details(a, 'A');
        print_stack_details(b, 'B');
    */    
      
	//	if (do_checks(a, b))
	//	{
	//		if (check_order(a) == 0)
	//			sort (a, b);
			free_all(a, b);
	//	}
	}
	return (0);
}
