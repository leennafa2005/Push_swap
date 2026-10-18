/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:15:20 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/18 17:29:22 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_list **stack_a, t_bench *bench)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	bench->ra ++;
	bench-> total ++;
}

void	rb(t_list **stack_b, t_bench *bench)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	bench->rb ++;
	bench-> total ++;
}

void	rr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	bench->rr ++;
	bench-> total ++;
}
