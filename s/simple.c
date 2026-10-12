/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:20:05 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/12 19:02:14 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple(t_list **stack_a, t_list **stack_b)
{
	int	count;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	while (*stack_a)
	{
		count = 0;
		while ((*stack_a)->content < (*stack_b)->content
			&& (count < ft_lstsize(*stack_b) - 1))
		{
			rb(stack_b);
			count++;
		}
		pb(stack_a, stack_b);
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);
		while (count --)
			rrb(stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
