#include "push_swap.h"

void	sort_3(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (tmp->index > tmp->next->index && tmp->index < tmp->next->next->index)
		sa(stack);
	else if(tmp->index < tmp->next->index && tmp->index < tmp->next->next->index)
		sa(stack);
	else if (tmp->index > tmp->next->index && tmp->next->index > tmp->next->next->index)
		sa(stack);
	tmp = *stack;
	if (tmp->index < tmp->next->index && tmp->index > tmp->next->next->index)
		rra(stack);
	else if (tmp->index > tmp->next->index && tmp->index > tmp->next->next->index)
		ra(stack);
}


void	sort_hub(t_data *data)
{
	if (data->a_size == 2)
		sa(&data->stack_a);
	else if (data->a_size == 3)
		sort_3(&data->stack_a);
}
