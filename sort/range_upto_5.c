
#include "push_swap.h"

void	algo_3(t_stack *a)
{
	t_node	*top;
	t_node	*bot;

	top = a->top;
	bot = a->bot;
	if (top->val < bot->val && top->next > bot->val)
	{
		rra(a);
		sa(*a);
	}
	else if (top->val > top->next->val && bot->val > top->val)
		sa(*a);
	else if (top->val < top->next->val && top->val > bot->val)
	   rra(a);
	else if (top->val > top->next->val && top->next->val > bot->val)
	{
		sa(*a);
		rra(a);
	}
	else if (top->val > top->next->val && top->next->val < bot->val)
	{
		rra(a);
		rra(a);
	}
}
