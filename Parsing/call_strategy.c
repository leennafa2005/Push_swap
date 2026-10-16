/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:01:04 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/16 19:36:56 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	call_strategy(t_strategy strategy, t_list **stack_a, t_list **stack_b)
{
	if (strategy == ADAPTIVE)
		adaptive(stack_a, stack_b);
	else if (strategy == SIMPLE)
		simple(stack_a, stack_b);
	else if (strategy == MEDIUM)
		medium(stack_a, stack_b);
	else if (strategy == COMPLEX)
		complex(stack_a, stack_b);
}
