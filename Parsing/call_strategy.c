/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:01:04 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 17:01:04 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

void	call_strategy(t_strategy strategy, t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	if (strategy == ADAPTIVE)
		ft_printf(1, "%s", "calling adaptive sort\n");
	else if (strategy == SIMPLE)
		ft_printf(1, "%s", "calling simple sort\n");
	else if (strategy == MEDIUM)
		ft_printf(1, "%s", "calling medium sort\n");
	else if (strategy == COMPLEX)
		ft_printf(1, "%s", "calling complex sort\n");
}
