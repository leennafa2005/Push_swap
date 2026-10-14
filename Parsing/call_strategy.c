/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:01:04 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/14 18:25:37 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    give_index(t_list **stack_a);

void	call_strategy(t_strategy strategy, t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	if (strategy == ADAPTIVE)
		ft_printf(1, "%s", "calling adaptive sort\n");
	else if (strategy == SIMPLE)
		simple(stack_a, stack_b);
	else if (strategy == MEDIUM)
		give_index(stack_a);
	else if (strategy == COMPLEX)
		ft_printf(1, "%s", "calling complex sort\n");
}
