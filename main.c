/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 12:13:04 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/18 19:45:26 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flag	flag;
	t_bench	bench_data;

	bench_data = (t_bench){0};
	stack_a = NULL;
	stack_b = NULL;
	init_flags(&flag);
	if (ac > 1)
	{
		if (!parse_args(ac, av, &flag, &stack_a))
			return (ft_lstclear(&stack_a, del_content), 1);
		if (!is_sorted(stack_a))
			call_strategy(flag.strategy, &stack_a, &stack_b, &bench_data);
		if (flag.bench_set)
			bench(&bench_data, &stack_a, &stack_b, flag.strategy);
		ft_lstclear(&stack_a, del_content);
		ft_lstclear(&stack_b, del_content);
		return (0);
	}
	return (0);
}
