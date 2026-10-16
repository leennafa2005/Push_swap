/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:55:23 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/16 19:42:34 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_bits(int index)
{
	int	bit;

	bit = 0;
	while (index)
	{
		index = index >> 1;
		bit++;
	}
	return (bit);
}

void	complex(t_list **stack_a, t_list **stack_b)
{
	int	bits;
	int	b;
	int	s;

	give_index(stack_a);
	bits = get_bits(get_max(stack_a));
	b = 0;
	while (b < bits)
	{
		s = ft_lstsize(*stack_a);
		while (s)
		{
			if (((*stack_a)->index >> b & 2) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			s--;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		b++;
	}
}
