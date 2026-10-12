/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 12:13:04 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/12 18:23:25 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flag	flag;

	stack_a = NULL;
	stack_b = NULL;
	init_flags(&flag);
	if (ac > 1)
	{
		if (!parse_args(ac, av, &flag, &stack_a))
			return (ft_lstclear(&stack_a, del_content), 1);
		if (flag.bench_set)
			ft_printf(1, "%s", "call bench\n");
		if (!is_sorted(stack_a))
			call_strategy(flag.strategy, &stack_a, &stack_b);
		ft_lstclear(&stack_a, del_content);
		ft_lstclear(&stack_b, del_content);
		return (0);
	}
	return (0);
}
